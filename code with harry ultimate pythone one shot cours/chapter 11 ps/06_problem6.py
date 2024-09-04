# write str method to print vector as 7i + 8j + 9k
# assume vector of dimension 3 for this proble
class Vector:
        def __init__(self, x, y, z) -> None:
                self.x = x
                self.y = y
                self.z = z
        def __str__(self):
                return f"{self.x}i + {self.y}j + {self.z}k"
        
v1 = Vector(1,2,3)
print(str(v1))