# write a class calculator capable of finding square , cube and square root of a number

import math
class calculator:
        def __init__(self, n) -> None:
                self.n = n
                self.square = n*n
                self.cube = n*n*n
                self.squareroot = math.sqrt(n)
        def printinfo(self):
                print(f"square = {self.square}, cube = {self.cube}, squareoot = {self.squareroot}")
                
calc = calculator(7)
calc.printinfo()