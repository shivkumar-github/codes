# 3 types of ineritance = single, multiple , multilevel
class Employee:
        company = "ITC"
        def show(self):
                print(f"The name of the employee is {self.name}, and salary is {self.salary}")
                
# class Programmer:
#         company = "ITC Infothect"
#         def show(self):
#                 print(f"The name is {self.name} and the salary is {self.salary}")
                
#                 def showLanguager(self):
#                         print(f"The name is {self.name} and he is good with {self.language}  language")

class Programmer(Employee):
        company = "ItC Infotech"
        def showLanguager(self):
                print(f"The name is {self.name} and he is good with {self.language}  language")
                
a = Employee()
b = Programmer()

print(a.company, b.company)