print("************* This Is a Simple Calculator Using a Python ****************")

def add(a,b):
    return a+b

def sub(a,b):
    return a-b

def mul(a,b):
    return a*b

def div(a,b):
    if b==0:
        print("Not Divide By Zero ")
    else:
        return a/b

while True:
    print("*"*40)
    print("1. ADDITION")
    print("2. SUBTRACTION")
    print("3. MULTIPLICATION")
    print("4. DIVISION")
    print("5. EXIT")
    print("*"*40)

    choice=int(input("Enter Your Choice(1-4):"))

    if choice==1:
        a=int(input("Enter First Number : "))
        b=int(input("Enter Second Number : "))
        print("-> Addition is : ",add(a,b))
    elif choice==2:
        a=int(input("Enter First Number : "))
        b=int(input("Enter Second Number : "))
        print("-> Subtraction is : ",sub(a,b))
    elif choice==3:
        a=int(input("Enter First Number : "))
        b=int(input("Enter Second Number : "))
        print("-> Multiplication is : ",mul(a,b))
    elif choice==4:
        a=int(input("Enter First Number : "))
        b=int(input("Enter Second Number : "))
        print("-> Division is : ",div(a,b))
    elif choice==5:
        print("Thank You For Using My Calculator")
        break
    else:
        print("INVALID CHOICE TRY AGAIN")



