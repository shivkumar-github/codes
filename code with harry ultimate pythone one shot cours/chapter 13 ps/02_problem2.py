# write a program to input name, marks and phone number of  a student and format it using the format function like below
# "The name of the student is Harry, his marks are 72 and phone is 9999999888"
name = input("Enter your name : ")
marks = int(input("Enter your marks : "))
phone = input("Enter your phone number : ")
a = "The name of the student is {0}, his marks are {1} and phone is {2}".format(name, marks, phone) #0, 1, 2 are written for just readability
print(a)
