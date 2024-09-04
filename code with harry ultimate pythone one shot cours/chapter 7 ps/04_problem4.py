# find if the number is prime or not
n = int(input("enter the number : "))
is_prime = True
for i in range (2, n):
        if(n % i == 0):
                is_prime = False
                break
if(is_prime):
        print("a prime number")
else:
        print("not a prime number")