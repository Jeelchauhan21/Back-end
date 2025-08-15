n=int(input("Enter a Number : "))

if n%2!=0:
    for i in range(3,int(n/2)+1,2):
        print("Number is Prime")
        break
else:
    print("Number is not Prime")
