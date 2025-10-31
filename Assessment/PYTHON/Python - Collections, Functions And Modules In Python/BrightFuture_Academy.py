# EduTrack - Python Console Attendance System

attendance_records = []

def mark_attendance():
    print("\n--- Mark Attendance ---")
    roll = input("Enter Roll Number: ")
    name = input("Enter Student Name: ")
    course = input("Enter Course Name: ")
    date = input("Enter Date (YYYY-MM-DD): ")
    
    # Check for duplicate roll/date entry
    for record in attendance_records:
        if record["roll"] == roll and record["date"] == date:
            print(" Attendance already marked for this student on that date.")
            return
    
    status = input("Enter Attendance Status (P/A): ").upper()
    if status not in ["P", "A"]:
        print(" Invalid status! Please enter 'P' or 'A'.")
        return
    
    record = {
        "roll": roll,
        "name": name,
        "course": course,
        "date": date,
        "status": status
    }
    attendance_records.append(record)
    print("✅ Attendance recorded successfully!")

def student_report():
    print("\n--- Student Attendance Report ---")
    roll = input("Enter Roll Number: ")
    student_records = [r for r in attendance_records if r["roll"] == roll]
    
    if not student_records:
        print(" No records found for this student.")
        return
    
    total_days = len(student_records)
    present_days = sum(1 for r in student_records if r["status"] == "P")
    attendance_percent = (present_days / total_days) * 100
    
    print(f"\nReport for Roll No: {roll}")
    print("------------------------------------------------")
    print(f"Total Days: {total_days}")
    print(f"Days Present: {present_days}")
    print(f"Days Absent: {total_days - present_days}")
    print(f"Attendance %: {attendance_percent:.2f}")
    
    if attendance_percent < 75:
        print(" Status: Defaulter")
    else:
        print("Status: Regular")

def class_report():
    print("\n--- Full Class Attendance Report ---")
    if not attendance_records:
        print(" No attendance data available.")
        return
    
    students = {}
    for record in attendance_records:
        roll = record["roll"]
        if roll not in students:
            students[roll] = {"name": record["name"], "P": 0, "A": 0}
        students[roll][record["status"]] += 1
    
    print("{:<10} {:<20} {:<10} {:<10} {:<15}".format("Roll", "Name", "Present", "Absent", "Attendance %"))
    print("-" * 70)
    
    for roll, data in students.items():
        total = data["P"] + data["A"]
        percent = (data["P"] / total) * 100 if total > 0 else 0
        print("{:<10} {:<20} {:<10} {:<10} {:<15.2f}".format(roll, data["name"], data["P"], data["A"], percent))

def main_menu():
    while True:
        print("\n===== EduTrack - Student Attendance System =====")
        print("1. Mark Attendance")
        print("2. View Student Report")
        print("3. View Full Class Report")
        print("4. Exit")
        choice = input("Enter your choice: ")

        if choice == '1':
            mark_attendance()
        elif choice == '2':
            student_report()
        elif choice == '3':
            class_report()
        elif choice == '4':
            print(" Exiting EduTrack. Goodbye!")
            break
        else:
            print(" Invalid choice. Please try again.")

# Run program
main_menu()
