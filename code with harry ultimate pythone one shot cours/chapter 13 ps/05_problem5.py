from functools import reduce
# write a program to find the maximum of the number of the numbers in a list using the reduce function
l = [55,34,9,666,23,1,3]
def maxi(a,b):
        if a > b:
                return a
        return b

max = reduce(maxi, l)
print(max)