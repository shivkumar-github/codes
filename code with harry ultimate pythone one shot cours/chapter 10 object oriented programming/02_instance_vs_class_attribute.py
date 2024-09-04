class Employee:
        language = "python"
        salary = 1200000
        
shivkumar = Employee()
shivkumar.language = "javascript" #instance attribute has more priority
print(shivkumar.language)