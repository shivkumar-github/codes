# i don't understand the code 
class Employee:
        a = 1
        
        @classmethod #directly shows class attribute
        def  show(cls):
                print(f"The class value of a is {cls.a}")
                
        @property #poperty method is used to set a method in a class as a property which can be accessed with dot notation which allows to internally call a method without knowledge of user(abstraction)
        def name(self):
                return f"{self.fname} {self.lname}"
        
        @name.setter #A setter is a method associated with a property that is called when a value is assigned to the property
        def name(self, value): #value is the value assigned to attribute like looking method (using @property)
                self.fname = value.split(" ")[0]
                self.lname = value.split(" ")[1]
                
e = Employee()
e.a = 45

e.name = "shivkumar rajmane"
print(e.fname, e.lname)

e.show()