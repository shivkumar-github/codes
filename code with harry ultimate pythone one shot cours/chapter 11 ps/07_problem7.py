# overload the len method on a vector of problem 5 to display the dimensions of the vector
class Vector:
        def __init__(self,l) -> None:
                self.l = l
                
        def __len__(self):
                return len(self.l)
        
v = Vector([1,2,3,4])
print(len(v))