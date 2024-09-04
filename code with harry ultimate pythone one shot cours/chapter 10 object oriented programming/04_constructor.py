# 
class Employee :
        language = "js"
        salary = 1200000
        def __init__(self, name, salray, language): # dunder(starting with __) method which is automatically called
                self.name = name
                self.language = language
                self.salary = salray
                print("I am creating an object.")
                
                
        def getInfo(self): #if not written self then gives error and self is a conventional name
                print(self.language)
                print(self.salary)
                
        @staticmethod #marked as a function which doesn't need self 
        def greet():
                print("welome")
                
shivkumar = Employee("shivkumar", 1300000, "cpp")
shivkumar.getInfo()
