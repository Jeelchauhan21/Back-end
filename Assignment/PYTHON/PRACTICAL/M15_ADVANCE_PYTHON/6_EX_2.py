
company_name = "TechCorp"# Global variable

class Employee:
    def details(self, name, salary):
        
        self.name = name
        self.salary = salary

    def show_details(self):
        # Local variable inside method
        bonus = 5000
        print("Employee Name:", self.name)
        print("Salary:", self.salary)
        print("Bonus (Local Variable):", bonus)
        print("Company (Global Variable):", company_name)


emp1 = Employee()
emp1.details('jeel',50000)


emp1.show_details()
