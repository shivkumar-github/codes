# multiple - more than 1 base classes
class Employee:
        company = "ITC"
        name = "default name"
        def show(self):
                print(f"The name of the employee is {self.name}, and salary is {self.company}")
   
class Coder:
        language = "python"
        def printLanguages(self):
                print(f"Out of all languages here is your language : {self.language}")
        
class Programmer(Employee, Coder):
        company = "ItC Infotech"
        def showLanguager(self):
                print(f"The name is {self.company} and he is good with {self.language}  language")
                
a = Employee()
b = Programmer()

b.show()
b.showLanguager()
b.printLanguages()