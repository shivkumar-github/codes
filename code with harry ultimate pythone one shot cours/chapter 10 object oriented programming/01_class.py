class Employee:
        language = "python"#this is a class attribute
        salary = 1200000

harry = Employee()
harry.name = "Harry" #this is an instance attribute
print(f"name : {harry.name} , language : {harry.language}, salary : {harry.salary}")

shubham = Employee()
shubham.hobby =  "football"
print(f"language : {shubham.language}, salary : {shubham.salary}, hobby : {shubham.hobby}")

# here name and hobby are object attributes and salary and language are class attribute as they directly belong to the class