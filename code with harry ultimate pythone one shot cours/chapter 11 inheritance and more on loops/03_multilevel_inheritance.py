class c1:
        def __init__(self) -> None:
                print("constructer of c1")
        a1 = 1
        
class c2(c1):
        def __init__(self) -> None:
                print("constructer of c1")
        a2 = 2
        
class c3(c2):
        def __init__(self) -> None:
                print("constructer of c1")
        a3 = 3
        
o1 = c1()
o2 = c2()
o3 = c3()

print(o1.a1)
print(o2.a1, o2.a2)
print(o3.a1, o3.a2, o3.a3)

        