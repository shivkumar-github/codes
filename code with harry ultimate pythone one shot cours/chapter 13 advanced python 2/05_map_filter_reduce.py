from functools import reduce
# map
# map applies the function to all the items in an input list
l = [1, 2, 3, 4, 5 ]
square = lambda x : x*x

sqrList = list((map(square, l))) #converting it to the list
print (sqrList)


# Filter example
def even(n):
        if not(n%2):
                return True
        return False

onlyEven = list(filter(even, l)) #filter returns a filter object
print(onlyEven)

# Reduce Example
# have to import it from functools module
# first the function will execute on first two values then on the result and then next value and so on till last value
def sum(a, b):
        return a + b


print(reduce(sum, l))
