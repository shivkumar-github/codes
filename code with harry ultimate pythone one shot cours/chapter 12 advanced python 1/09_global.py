a = 12
def fun():
        global a #allow access to global variable
        a = 3
        print(a)

        
fun()
print(a)
