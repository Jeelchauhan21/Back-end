list=['Apple','Mango','Banana','Avacado']

s_item=input("Enter Search item : ")

for i in list:
    if i==s_item:
        print("Yes Item found in list")
        break
else:
     print("Item Not Found in list")
