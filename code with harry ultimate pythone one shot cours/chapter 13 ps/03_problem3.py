# A list contains multiplication table of 7 and. Write a program to convert it to verticle string of same numbers
l = [str(7*i) for i in range(1,11)]
table = "\n".join(l)
print(table)