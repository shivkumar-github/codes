a = int(input("Enter your age : "))

if(a>=18):
        print("you are above the age of consent.")
        print("in the if ")
elif(a<0):
        print("you are entering an invalid age")
elif(a == 0):
        print("you are just born")
else:
        print("You are below the age of concent.")
print("end of programe")