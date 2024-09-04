# operators in python can be overloaded using following methods

# magic methods
# + -> p1.__add__(p2)
# - -> p1.__sub__(p2)
# * -> p1.__mul__(p2)
# / -> p1.__truedive__(p2) ->returns floaing point answer
# // -> p1.__floordiv__(p2) -> returns integer ans
# __str__() -> used to set what happens when str(obj)\
# __len__() -> used to set what happens when len(obj)

class Number:
        def __init__(self, n) -> None:
                self.n = n
        def __add__(self, Num):
                return self.n + Num.n            

n= Number(1)
m = Number(2)

print(n + m)