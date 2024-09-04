# find sum of n natural numbers
n = int(input("enter the number : "))
sum = 0
i = 1
while(i <= n):
        sum += i 
        i += 1
print(f"The sum of natural numbers till  {n} is {sum}")