# create a class "Pets" fromm a class "Animals" and further create a class "Dog" from "Pets" add a method "bark" to class "dog"

class Animal():
        pass
        
class Pets():
        pass
        
class Dog(Pets, Animal):
        @staticmethod
        def bark():
                print("The do is barking!")
        
        
d = Dog()
d.bark()