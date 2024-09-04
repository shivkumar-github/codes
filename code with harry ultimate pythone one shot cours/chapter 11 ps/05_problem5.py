# write a class vector representing a vector of 3 dimensions . overload the + and * operator which calculates the sum and the dot(.) product of them
class Vector:
        def __init__(self, x, y, z) -> None:
                self.x = x
                self.y = y
                self.z = z
        
        def __add__(self,v2):
                return f"addition is : {self.x+v2.x}i + {self.y + v2.y}j + {self.z + v2.z}k"
        
        def __mul__(self,v2):
                return f"dot product is : {self.x*v2.x + self.y*v2.y + self.z*v2.z}"

vec1 = Vector(1,2,3)
vec2 = Vector(4,5,6)
print(vec1+vec2)
print(vec1*vec2)