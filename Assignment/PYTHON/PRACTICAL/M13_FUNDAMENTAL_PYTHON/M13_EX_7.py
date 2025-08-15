
print("********** Enter Student Details **********")
name=input("Enter Name : ")
rno=int(input("Enter Student Roll_no : "))
s1=int(input("Enter Subject 1 Marks : "))
s2=int(input("Enter Subject 2 Marks : "))
s3=int(input("Enter Subject 3 Marks : "))

total=s1+s2+s3
per=total/3

print("Student Percentage is : ",per)

print("*"*50)

print("*"*50)
print("Student Name is : ",name)
print("Student Roll.no is : ",rno)
print("Total Marks : ",total)
print("Percentage is : ",float(per))


if per > 90:
    print("Result is : Grade A ")
elif per > 80:
    print("Result is : Grade B")
elif per > 60:
    print("Result is : Grade C")
elif per > 40:
    print("Result is : Pass")
else:
    print("Result is : Fail")

print("*"*50)


