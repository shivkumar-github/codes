# Write a class "Complex" to represent complex numbers, along with overloaded operators "+" and "*" which adds and mutliples them

class Complex:
        def __init__(self, x, y) -> None:
                self.x = x
                self.y = y
        
        def __add__(self, compl2):
                return (f"{self.x + compl2.x} + {self.y + compl2.y}i")
          
        def __mul__(self, compl2):
                return (f"The multiplication is {self.x*compl2.x - self.y*compl2.y} + {self.x*compl2.y + self.y*compl2.x}i")
                
c1 = Complex(1,2)
c2 = Complex(2,4)
print(c1*c2)
print(c1+c2)