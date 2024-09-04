def fact(num):
        if(num < 0):
                print("invalid input")
                return -1
        elif(num<=1):
                return 1
        return num*fact(num-1)

print(fact(-1))