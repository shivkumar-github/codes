# add static method in problem2 to greet the user with hello

import math
class calculator:
        def __init__(self, n) -> None:
                self.square = n*n
                self.cube = n*n*n
                self.squareroot = math.sqrt(n)
        def printinfo(self):
                print(f"square = {self.square}, cube = {self.cube}, squareoot = {self.squareroot}")
        @staticmethod
        def greet():
                print("hello")
                
calc = calculator(7)
calc.printinfo()