# create a class programmer for storing information about programmers in microsoft
class programmer:
        company = "Microsoft"
        def __init__(self, name, salary, pin):
                self.name = name
                self.salary = salary
                self.pin = pin
        def printInfo(self):
                print(self.name, self.company, self.salary, self.pin)
                
shivkumar = programmer("shivkumar",8000000,2099)
shivkumar.printInfo()