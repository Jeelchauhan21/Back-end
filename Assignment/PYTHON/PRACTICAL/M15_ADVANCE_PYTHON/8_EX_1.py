# Combined Example of Method Overloading and Overriding in Python

class Calculator:
    # Method Overloading using default arguments
    def add(self, a=0, b=0, c=0):
        return a + b + c


class Animal:
    def sound(self):
        print("Animals make sounds")


class Dog(Animal):
    # Method Overriding - overriding sound() method of Animal class
    def sound(self):
        print("Dog barks")


# ---------- DEMO ----------
print("---- Method Overloading ----")
calc = Calculator()
print("Sum of 2 numbers:", calc.add(10, 20))
print("Sum of 3 numbers:", calc.add(10, 20, 30))
print("Sum of 1 number:", calc.add(5))

print("\n---- Method Overriding ----")
a = Animal()
d = Dog()

a.sound()  # Calls Animal's sound() method
d.sound()  # Calls Dog's overridden sound() method
