
class Student:
    def details(self, name, age, grade):
        self.name = name      
        self.age = age        
        self.grade = grade    


student1 = Student()
student1.details('jeel',21,'A')


print("Student Details:")
print("Name:", student1.name)
print("Age:", student1.age)
print("Grade:", student1.grade)
