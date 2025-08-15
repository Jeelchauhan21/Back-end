name=input("Enter Your Name : ")
age=int(input("Enter Your Age : "))
weight=int(input("Enter Your Weight : "))

if age >= 18:
    if weight >=50:
        print("You eligible for donate blood")
    else:
        print("You not eligible for donate blood because your weight is less than 50")
else:
    print("You not eligible for donate blood because your age is less than 18")
    

