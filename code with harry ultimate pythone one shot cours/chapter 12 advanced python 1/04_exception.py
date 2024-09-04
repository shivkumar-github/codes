# when something goes wrong there are many built in excepiions which are raised in py they can be handled using try statement
try:
        a = int(input("hey, Enter a number : "))
        print(a)
except ValueError as e:
        print("This is valueerror!")
        print(e)
except Exception as e:
        print(e)
