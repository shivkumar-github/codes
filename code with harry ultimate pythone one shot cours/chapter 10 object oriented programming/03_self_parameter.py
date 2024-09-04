# 
class Employee :
        language = "js"
        salary = 1200000
        
        def getInfo(self): #if not written self then gives error and self is a conventional name
                print(self.language)
                print(self.salary)
                
        @staticmethod #marked as a function which doesn't need self 
        def greet():
                print("welome")
                
shivkumar = Employee()
shivkumar.getInfo()
Employee.getInfo(shivkumar)
shivkumar.greet()