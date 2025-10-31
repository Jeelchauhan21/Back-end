"""
MediTrack_main.py
A single-file minimal-but-complete demonstration of the MediTrack desktop app using Tkinter + SQLite3.
Features included:
- Patient and appointment management with classes
- Visit tracking (inheritance used between Appointment and Visit)
- Billing calculations and invoice export to CSV
- User roles: Admin, Receptionist, Doctor with access control and custom exceptions
- Regex-based search for patients/appointments
- File operations, exception handling

This is a demo / starting point: for production you should split into modules, add hashing for passwords,
better form validation, and tests.
"""
import os
import re
import csv
import sqlite3
from datetime import datetime
import tkinter as tk
from tkinter import ttk, messagebox, simpledialog, filedialog

# ---------------------------
# Custom Exceptions
# ---------------------------
class AccessDenied(Exception):
    pass

class InvalidDataError(Exception):
    pass

# ---------------------------
# Database helper
# ---------------------------
DB_FILE = 'meditrack.db'

def init_db():
    conn = sqlite3.connect(DB_FILE)
    c = conn.cursor()
    # Users table (in production store hashed passwords!)
    c.execute('''
    CREATE TABLE IF NOT EXISTS users(
        id INTEGER PRIMARY KEY,
        username TEXT UNIQUE,
        password TEXT,
        role TEXT
    )
    ''')
    # Patients
    c.execute('''
    CREATE TABLE IF NOT EXISTS patients(
        id INTEGER PRIMARY KEY,
        name TEXT,
        dob TEXT,
        phone TEXT,
        address TEXT,
        notes TEXT
    )
    ''')
    # Appointments / Visits
    c.execute('''
    CREATE TABLE IF NOT EXISTS appointments(
        id INTEGER PRIMARY KEY,
        patient_id INTEGER,
        date TEXT,
        time TEXT,
        doctor TEXT,
        reason TEXT,
        status TEXT,
        diagnosis TEXT,
        prescription TEXT,
        FOREIGN KEY(patient_id) REFERENCES patients(id)
    )
    ''')
    # Invoices
    c.execute('''
    CREATE TABLE IF NOT EXISTS invoices(
        id INTEGER PRIMARY KEY,
        appointment_id INTEGER,
        subtotal REAL,
        tax REAL,
        total REAL,
        created_at TEXT,
        FOREIGN KEY(appointment_id) REFERENCES appointments(id)
    )
    ''')
    conn.commit()
    # Insert default users if not exist
    try:
        c.execute("INSERT OR IGNORE INTO users(username,password,role) VALUES ('admin','admin123','Admin')")
        c.execute("INSERT OR IGNORE INTO users(username,password,role) VALUES ('reception','recep123','Receptionist')")
        c.execute("INSERT OR IGNORE INTO users(username,password,role) VALUES ('doc','doc123','Doctor')")
        conn.commit()
    finally:
        conn.close()

# ---------------------------
# Domain Classes
# ---------------------------
class Patient:
    def __init__(self, name, dob, phone, address='', notes='', id=None):
        self.id = id
        self.name = name
        self.dob = dob
        self.phone = phone
        self.address = address
        self.notes = notes

    def save(self):
        conn = sqlite3.connect(DB_FILE)
        c = conn.cursor()
        if not self.name or not self.phone:
            raise InvalidDataError('Patient must have a name and phone number')
        if self.id is None:
            c.execute('INSERT INTO patients(name,dob,phone,address,notes) VALUES (?,?,?,?,?)',
                      (self.name, self.dob, self.phone, self.address, self.notes))
            self.id = c.lastrowid
        else:
            c.execute('UPDATE patients SET name=?,dob=?,phone=?,address=?,notes=? WHERE id=?',
                      (self.name, self.dob, self.phone, self.address, self.notes, self.id))
        conn.commit()
        conn.close()

    @staticmethod
    def get_all():
        conn = sqlite3.connect(DB_FILE)
        c = conn.cursor()
        c.execute('SELECT id,name,dob,phone,address,notes FROM patients')
        rows = c.fetchall()
        conn.close()
        return [Patient(id=r[0], name=r[1], dob=r[2], phone=r[3], address=r[4], notes=r[5]) for r in rows]

    @staticmethod
    def find_by_regex(pattern):
        # Searches name and notes using regex
        rx = re.compile(pattern, re.IGNORECASE)
        result = []
        for p in Patient.get_all():
            if rx.search(p.name) or (p.notes and rx.search(p.notes)):
                result.append(p)
        return result

    def __str__(self):
        return f"{self.id}: {self.name} ({self.phone})"

class Appointment:
    def __init__(self, patient_id, date, time, doctor, reason, status='Scheduled', id=None):
        self.id = id
        self.patient_id = patient_id
        self.date = date
        self.time = time
        self.doctor = doctor
        self.reason = reason
        self.status = status

    def save(self):
        conn = sqlite3.connect(DB_FILE)
        c = conn.cursor()
        if not self.patient_id:
            raise InvalidDataError('Appointment must be linked to a patient')
        if self.id is None:
            c.execute('INSERT INTO appointments(patient_id,date,time,doctor,reason,status) VALUES (?,?,?,?,?,?)',
                      (self.patient_id, self.date, self.time, self.doctor, self.reason, self.status))
            self.id = c.lastrowid
        else:
            c.execute('UPDATE appointments SET patient_id=?,date=?,time=?,doctor=?,reason=?,status=? WHERE id=?',
                      (self.patient_id, self.date, self.time, self.doctor, self.reason, self.status, self.id))
        conn.commit()
        conn.close()

    @staticmethod
    def get_for_patient(patient_id):
        conn = sqlite3.connect(DB_FILE)
        c = conn.cursor()
        c.execute('SELECT id,patient_id,date,time,doctor,reason,status,diagnosis,prescription FROM appointments WHERE patient_id=?', (patient_id,))
        rows = c.fetchall()
        conn.close()
        return rows

# Visit inherits from Appointment and extends it with diagnosis & prescription
class Visit(Appointment):
    def __init__(self, patient_id, date, time, doctor, reason, diagnosis='', prescription='', status='Completed', id=None):
        super().__init__(patient_id, date, time, doctor, reason, status=status, id=id)
        self.diagnosis = diagnosis
        self.prescription = prescription

    def save(self):
        conn = sqlite3.connect(DB_FILE)
        c = conn.cursor()
        if self.id is None:
            # create appointment with extra fields
            c.execute('INSERT INTO appointments(patient_id,date,time,doctor,reason,status,diagnosis,prescription) VALUES (?,?,?,?,?,?,?,?)',
                      (self.patient_id, self.date, self.time, self.doctor, self.reason, self.status, self.diagnosis, self.prescription))
            self.id = c.lastrowid
        else:
            c.execute('UPDATE appointments SET patient_id=?,date=?,time=?,doctor=?,reason=?,status=?,diagnosis=?,prescription=? WHERE id=?',
                      (self.patient_id, self.date, self.time, self.doctor, self.reason, self.status, self.diagnosis, self.prescription, self.id))
        conn.commit()
        conn.close()

# Billing helper
class Billing:
    TAX_PERCENT = 0.05

    @staticmethod
    def calculate(subtotal, medicines):
        if subtotal < 0 or medicines < 0:
            raise InvalidDataError('Charges cannot be negative')
        subtotal_all = float(subtotal) + float(medicines)
        tax = subtotal_all * Billing.TAX_PERCENT
        total = subtotal_all + tax
        return round(subtotal_all,2), round(tax,2), round(total,2)

    @staticmethod
    def save_invoice(appointment_id, subtotal, tax, total):
        conn = sqlite3.connect(DB_FILE)
        c = conn.cursor()
        created_at = datetime.now().isoformat()
        c.execute('INSERT INTO invoices(appointment_id,subtotal,tax,total,created_at) VALUES (?,?,?,?,?)',
                  (appointment_id, subtotal, tax, total, created_at))
        conn.commit()
        conn.close()
        # Also save a CSV file copy
        filename = f'invoice_{appointment_id}_{int(datetime.now().timestamp())}.csv'
        with open(filename, 'w', newline='') as f:
            writer = csv.writer(f)
            writer.writerow(['appointment_id','subtotal','tax','total','created_at'])
            writer.writerow([appointment_id, subtotal, tax, total, created_at])
        return filename

# ---------------------------
# Access control
# ---------------------------
class AccessControl:
    def __init__(self, username):
        self.username = username
        self.role = None
        self._load_role()

    def _load_role(self):
        conn = sqlite3.connect(DB_FILE)
        c = conn.cursor()
        c.execute('SELECT role FROM users WHERE username=?', (self.username,))
        r = c.fetchone()
        conn.close()
        if r:
            self.role = r[0]
        else:
            raise AccessDenied('User not found')

    def require(self, allowed_roles):
        if self.role not in allowed_roles:
            raise AccessDenied(f'Role {self.role} cannot perform this action')

# ---------------------------
# GUI
# ---------------------------
class MediTrackApp(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title('MediTrack')
        self.geometry('900x600')
        self.current_user = None
        self._build_login()

    def _build_login(self):
        for w in self.winfo_children():
            w.destroy()
        frame = ttk.Frame(self, padding=20)
        frame.pack(fill='both', expand=True)
        ttk.Label(frame, text='MediTrack Login', font=('TkDefaultFont', 16)).pack(pady=10)
        user_var = tk.StringVar()
        pass_var = tk.StringVar()
        ttk.Label(frame, text='Username').pack()
        ttk.Entry(frame, textvariable=user_var).pack()
        ttk.Label(frame, text='Password').pack()
        ttk.Entry(frame, textvariable=pass_var, show='*').pack()
        def do_login():
            u = user_var.get().strip()
            p = pass_var.get().strip()
            if not u or not p:
                messagebox.showerror('Login error', 'Provide username and password')
                return
            conn = sqlite3.connect(DB_FILE)
            c = conn.cursor()
            c.execute('SELECT username FROM users WHERE username=? AND password=?', (u,p))
            r = c.fetchone()
            conn.close()
            if not r:
                messagebox.showerror('Login error', 'Invalid credentials')
                return
            self.current_user = u
            self.access = AccessControl(u)
            self._build_main()
        ttk.Button(frame, text='Login', command=do_login).pack(pady=10)

    def _build_main(self):
        for w in self.winfo_children():
            w.destroy()
        # Top menu with role info
        top = ttk.Frame(self)
        top.pack(fill='x')
        ttk.Label(top, text=f'Logged in: {self.current_user} ({self.access.role})').pack(side='left', padx=10, pady=6)
        ttk.Button(top, text='Logout', command=self._build_login).pack(side='right', padx=10)

        pane = ttk.Panedwindow(self, orient='horizontal')
        pane.pack(fill='both', expand=True)
        left = ttk.Frame(pane, width=300)
        right = ttk.Frame(pane)
        pane.add(left, weight=1)
        pane.add(right, weight=3)

        # Left: patient list + actions
        ttk.Label(left, text='Patients', font=('TkDefaultFont', 12)).pack(pady=6)
        self.pat_list = tk.Listbox(left)
        self.pat_list.pack(fill='both', expand=True, padx=6, pady=6)
        self._refresh_patients()
        ttk.Button(left, text='New Patient', command=self._new_patient).pack(fill='x', padx=6)
        ttk.Button(left, text='Edit Patient', command=self._edit_patient).pack(fill='x', padx=6, pady=3)
        ttk.Button(left, text='Regex Search', command=self._regex_search).pack(fill='x', padx=6)

        # Right: appointment and details
        ttk.Label(right, text='Patient / Appointment Details', font=('TkDefaultFont', 12)).pack(pady=6)
        self.details = tk.Text(right, height=20)
        self.details.pack(fill='both', expand=True, padx=6, pady=6)

        btn_frame = ttk.Frame(right)
        btn_frame.pack(fill='x')
        ttk.Button(btn_frame, text='New Appointment', command=self._new_appointment).pack(side='left', padx=6)
        ttk.Button(btn_frame, text='Log Visit (Doctor)', command=self._log_visit).pack(side='left', padx=6)
        ttk.Button(btn_frame, text='Billing', command=self._billing).pack(side='left', padx=6)
        ttk.Button(btn_frame, text='Export All Patients CSV', command=self._export_patients_csv).pack(side='right', padx=6)

        # Bind selection
        self.pat_list.bind('<<ListboxSelect>>', self._on_patient_select)

    def _refresh_patients(self):
        self.pat_list.delete(0, tk.END)
        for p in Patient.get_all():
            self.pat_list.insert(tk.END, f'{p.id} | {p.name} | {p.phone}')

    def _get_selected_patient_id(self):
        sel = self.pat_list.curselection()
        if not sel:
            return None
        txt = self.pat_list.get(sel[0])
        pid = int(txt.split('|')[0].strip())
        return pid

    def _on_patient_select(self, event=None):
        pid = self._get_selected_patient_id()
        if pid is None:
            return
        conn = sqlite3.connect(DB_FILE)
        c = conn.cursor()
        c.execute('SELECT id,name,dob,phone,address,notes FROM patients WHERE id=?', (pid,))
        p = c.fetchone()
        self.details.delete('1.0', tk.END)
        self.details.insert(tk.END, f'Patient ID: {p[0]}\nName: {p[1]}\nDOB: {p[2]}\nPhone: {p[3]}\nAddress: {p[4]}\nNotes: {p[5]}\n\n')
        # appointments
        c.execute('SELECT id,date,time,doctor,reason,status,diagnosis,prescription FROM appointments WHERE patient_id=? ORDER BY date DESC', (pid,))
        rows = c.fetchall()
        if rows:
            self.details.insert(tk.END, 'Appointments / Visits:\n')
            for r in rows:
                self.details.insert(tk.END, f'  ID:{r[0]} | {r[1]} {r[2]} | Dr:{r[3]} | {r[4]} | {r[5]}\n')
                if r[6] or r[7]:
                    self.details.insert(tk.END, f'    Diagnosis: {r[6]}\n    Prescription: {r[7]}\n')
        conn.close()

    def _new_patient(self):
        self.access.require(['Admin','Receptionist'])
        dlg = PatientDialog(self, 'New Patient')
        self.wait_window(dlg)
        if dlg.saved:
            self._refresh_patients()

    def _edit_patient(self):
        self.access.require(['Admin','Receptionist'])
        pid = self._get_selected_patient_id()
        if not pid:
            messagebox.showerror('Select patient', 'Please select a patient first')
            return
        dlg = PatientDialog(self, 'Edit Patient', pid)
        self.wait_window(dlg)
        if dlg.saved:
            self._refresh_patients()

    def _regex_search(self):
        pattern = simpledialog.askstring('Regex Search', 'Enter regex to search name or notes (e.g. Follow up|diabetes):')
        if not pattern:
            return
        try:
            results = Patient.find_by_regex(pattern)
        except re.error as e:
            messagebox.showerror('Regex error', str(e))
            return
        self.details.delete('1.0', tk.END)
        if not results:
            self.details.insert(tk.END, 'No matches')
            return
        for p in results:
            self.details.insert(tk.END, f'{p.id} | {p.name} | {p.phone} | {p.notes}\n')

    def _new_appointment(self):
        self.access.require(['Admin','Receptionist'])
        pid = self._get_selected_patient_id()
        if not pid:
            messagebox.showerror('Select patient', 'Please select a patient first')
            return
        dlg = AppointmentDialog(self, 'New Appointment', pid)
        self.wait_window(dlg)
        if dlg.saved:
            self._on_patient_select()

    def _log_visit(self):
        # Only doctor can finalize visit details
        try:
            self.access.require(['Doctor','Admin'])
        except AccessDenied:
            messagebox.showerror('Access denied', 'Only Doctors or Admin can log visits')
            return
        pid = self._get_selected_patient_id()
        if not pid:
            messagebox.showerror('Select patient', 'Please select a patient first')
            return
        dlg = VisitDialog(self, 'Log Visit', pid)
        self.wait_window(dlg)
        if dlg.saved:
            self._on_patient_select()

    def _billing(self):
        pid = self._get_selected_patient_id()
        if not pid:
            messagebox.showerror('Select patient', 'Please select a patient first')
            return
        # Choose appointment
        rows = Appointment.get_for_patient(pid)
        if not rows:
            messagebox.showerror('No appointment', 'No appointments available for billing')
            return
        # For simplicity ask for appointment id
        aid = simpledialog.askinteger('Billing', 'Enter appointment id for billing:')
        if not aid:
            return
        subtotal = simpledialog.askfloat('Charges', 'Enter consultation charge:')
        medicines = simpledialog.askfloat('Medicines', 'Enter medicines charge:')
        try:
            subtotal_all, tax, total = Billing.calculate(subtotal, medicines)
        except InvalidDataError as e:
            messagebox.showerror('Invalid data', str(e))
            return
        filename = Billing.save_invoice(aid, subtotal_all, tax, total)
        messagebox.showinfo('Billed', f'Total: {total}\nInvoice saved to {filename}')

    def _export_patients_csv(self):
        patients = Patient.get_all()
        fname = filedialog.asksaveasfilename(defaultextension='.csv', filetypes=[('CSV','*.csv')])
        if not fname:
            return
        with open(fname, 'w', newline='') as f:
            w = csv.writer(f)
            w.writerow(['id','name','dob','phone','address','notes'])
            for p in patients:
                w.writerow([p.id,p.name,p.dob,p.phone,p.address,p.notes])
        messagebox.showinfo('Exported', f'Exported {len(patients)} patients to {fname}')

# ---------------------------
# Dialogs
# ---------------------------
class PatientDialog(tk.Toplevel):
    def __init__(self, parent, title, pid=None):
        super().__init__(parent)
        self.title(title)
        self.saved = False
        self.pid = pid
        self._build()
        if pid:
            self._load(pid)

    def _build(self):
        frame = ttk.Frame(self, padding=10)
        frame.pack(fill='both', expand=True)
        self.name = tk.StringVar()
        self.dob = tk.StringVar()
        self.phone = tk.StringVar()
        self.address = tk.StringVar()
        self.notes = tk.StringVar()
        ttk.Label(frame, text='Name').grid(row=0,column=0)
        ttk.Entry(frame, textvariable=self.name).grid(row=0,column=1)
        ttk.Label(frame, text='DOB').grid(row=1,column=0)
        ttk.Entry(frame, textvariable=self.dob).grid(row=1,column=1)
        ttk.Label(frame, text='Phone').grid(row=2,column=0)
        ttk.Entry(frame, textvariable=self.phone).grid(row=2,column=1)
        ttk.Label(frame, text='Address').grid(row=3,column=0)
        ttk.Entry(frame, textvariable=self.address).grid(row=3,column=1)
        ttk.Label(frame, text='Notes').grid(row=4,column=0)
        ttk.Entry(frame, textvariable=self.notes).grid(row=4,column=1)
        btn = ttk.Button(frame, text='Save', command=self._save)
        btn.grid(row=5,column=0,columnspan=2,pady=6)

    def _load(self, pid):
        conn = sqlite3.connect(DB_FILE)
        c = conn.cursor()
        c.execute('SELECT name,dob,phone,address,notes FROM patients WHERE id=?', (pid,))
        r = c.fetchone()
        conn.close()
        if r:
            self.name.set(r[0]); self.dob.set(r[1]); self.phone.set(r[2]); self.address.set(r[3]); self.notes.set(r[4])

    def _save(self):
        try:
            p = Patient(name=self.name.get().strip(), dob=self.dob.get().strip(), phone=self.phone.get().strip(), address=self.address.get().strip(), notes=self.notes.get().strip(), id=self.pid)
            p.save()
            self.saved = True
            self.destroy()
        except InvalidDataError as e:
            messagebox.showerror('Invalid', str(e))

class AppointmentDialog(tk.Toplevel):
    def __init__(self, parent, title, pid):
        super().__init__(parent)
        self.title(title)
        self.saved = False
        self.pid = pid
        self._build()

    def _build(self):
        frame = ttk.Frame(self, padding=10)
        frame.pack(fill='both', expand=True)
        self.date = tk.StringVar(value=datetime.now().date().isoformat())
        self.time = tk.StringVar(value=datetime.now().time().strftime('%H:%M'))
        self.doctor = tk.StringVar()
        self.reason = tk.StringVar()
        ttk.Label(frame, text='Date').grid(row=0,column=0); ttk.Entry(frame, textvariable=self.date).grid(row=0,column=1)
        ttk.Label(frame, text='Time').grid(row=1,column=0); ttk.Entry(frame, textvariable=self.time).grid(row=1,column=1)
        ttk.Label(frame, text='Doctor').grid(row=2,column=0); ttk.Entry(frame, textvariable=self.doctor).grid(row=2,column=1)
        ttk.Label(frame, text='Reason').grid(row=3,column=0); ttk.Entry(frame, textvariable=self.reason).grid(row=3,column=1)
        ttk.Button(frame, text='Save', command=self._save).grid(row=4,column=0,columnspan=2,pady=6)

    def _save(self):
        try:
            a = Appointment(patient_id=self.pid, date=self.date.get().strip(), time=self.time.get().strip(), doctor=self.doctor.get().strip(), reason=self.reason.get().strip())
            a.save()
            self.saved = True
            self.destroy()
        except InvalidDataError as e:
            messagebox.showerror('Invalid', str(e))

class VisitDialog(tk.Toplevel):
    def __init__(self, parent, title, pid):
        super().__init__(parent)
        self.title(title)
        self.saved = False
        self.pid = pid
        self._build()

    def _build(self):
        frame = ttk.Frame(self, padding=10)
        frame.pack(fill='both', expand=True)
        self.date = tk.StringVar(value=datetime.now().date().isoformat())
        self.time = tk.StringVar(value=datetime.now().time().strftime('%H:%M'))
        self.doctor = tk.StringVar()
        self.reason = tk.StringVar()
        self.diagnosis = tk.StringVar()
        self.prescription = tk.StringVar()
        ttk.Label(frame, text='Date').grid(row=0,column=0); ttk.Entry(frame, textvariable=self.date).grid(row=0,column=1)
        ttk.Label(frame, text='Time').grid(row=1,column=0); ttk.Entry(frame, textvariable=self.time).grid(row=1,column=1)
        ttk.Label(frame, text='Doctor').grid(row=2,column=0); ttk.Entry(frame, textvariable=self.doctor).grid(row=2,column=1)
        ttk.Label(frame, text='Reason').grid(row=3,column=0); ttk.Entry(frame, textvariable=self.reason).grid(row=3,column=1)
        ttk.Label(frame, text='Diagnosis').grid(row=4,column=0); ttk.Entry(frame, textvariable=self.diagnosis).grid(row=4,column=1)
        ttk.Label(frame, text='Prescription').grid(row=5,column=0); ttk.Entry(frame, textvariable=self.prescription).grid(row=5,column=1)
        ttk.Button(frame, text='Save Visit', command=self._save).grid(row=6,column=0,columnspan=2,pady=6)

    def _save(self):
        try:
            v = Visit(patient_id=self.pid, date=self.date.get().strip(), time=self.time.get().strip(), doctor=self.doctor.get().strip(), reason=self.reason.get().strip(), diagnosis=self.diagnosis.get().strip(), prescription=self.prescription.get().strip())
            v.save()
            self.saved = True
            self.destroy()
        except InvalidDataError as e:
            messagebox.showerror('Invalid', str(e))

# ---------------------------
# Entry point
# ---------------------------
if __name__ == '__main__':
    init_db()
    app = MediTrackApp()
    app.mainloop()
