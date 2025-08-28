print("Simple Calculator Using Exception Handling In Python")

def calc():
    try:

        a=int(input("Enter First Number : "))
        b=int(input("Enter Second Number : "))

        opr=input("Enter Operation(+,-,*,/) :")

        if opr=='+':
            result = a+b
        elif opr=='-':
            result = a-b
        elif opr=='*':
            result = a*b
        elif opr=='/':
            result = a/b
        else:
            print("Invalid Choice")


        print("Result Is : ",result)

    except ValueError:
        print("Error: Invalid input! Please enter numeric values.")
    except ZeroDivisionError:
        print("Division By Zero is Not Allowed")


calc()
