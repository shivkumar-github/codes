try:
        a = int(input("Hey Enter a number : "))
        print(a)
        
except Exception as e: 
        print(e)
        
else:#else used with try , we enters else when try is successfully executed
        print("I am inside else")
        