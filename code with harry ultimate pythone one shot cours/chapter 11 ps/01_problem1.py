# create a class (2-D vecrtor) and use it to create a class representing 3D vector
class TwoDvec:
        def __init__(self, i, j) -> None:
                self.i = i
                self.j = j
        def show(self):
                print(f"The vector is {self.i}i + {self.j}j")
                
class ThreeDvec(TwoDvec):#the constructor of parent class is not automatically invoked
        def __init__(self, i, j, k) -> None:
                super().__init__(i, j)
                self.k = k
        
        def show(self):
                print(f"The vector is {self.i}i + {self.j}j + {self.k}k")
                
o = TwoDvec(2,3)
o.show()
b = ThreeDvec(2,3,4)
b.show()