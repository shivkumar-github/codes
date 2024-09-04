# create a class with a class attribute a; create an object from it and set 'a'  directly using obect.a  =0 does this changes the class attribute - >> no

class cls:
        a = 1
        
o = cls() #prints the class attribute as instance attribute is not present
print(o.a)
o.a = 2
print(o.a) #prints the instance attribute as instance is present
print(cls.a) #prints the class attribute