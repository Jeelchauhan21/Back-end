# Function to calculate grade based on marks
def calculate_grade(marks):
    if marks >= 90:
        return "A"
    elif marks >= 75:
        return "B"
    elif marks >= 60:
        return "C"
    elif marks >= 40:
        return "D"
    else:
        return "F"

# Function to display student details
def display_students(student_data):
    print("\n---------- Student Records ----------------")
    for name, marks in student_data.items():
        print("Name: ",{name}," Marks: ",{marks},"Grade :" ,{calculate_grade(marks)})
    print("-------------------------------------------\n")

# Main program
def grade_management_system():
    students = {}  # Dictionary to store student name and marks

    while True:
        print("\nGrade Management System")
        print("1. Add Student")
        print("2. View Students")
        print("3. Exit")

        choice = input("Enter your choice: ")

        if choice == "1":
            name = input("Enter student name: ")
            marks = float(input("Enter marks (0-100): "))
            students[name] = marks
            print("Student record added successfully!")

        elif choice == "2":
            if students:
                display_students(students)
            else:
                print("No student records found.")

        elif choice == "3":
            print("Exiting Grade Management System. Goodbye!")
            break

        else:
            print("Invalid choice! Please try again.")


grade_management_system()
