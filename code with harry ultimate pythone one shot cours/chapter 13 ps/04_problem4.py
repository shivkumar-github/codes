# wrtite a program filter a list of number which are divisible by 5
l = [55,34,9,666,23,1,35]

def isDiv(a):
        if not a % 5:
                return True
        return False

print(list(filter(isDiv,l)))