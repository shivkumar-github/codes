name = "shivkumar"
# len
print (len(name))

# endswith and startswith
print(name.endswith("ar"))
print(name.endswith("rr"))
print(name.startswith("shivk"))
print(name.startswith("shidd"))
print(name.startswith("Shivk")) # case sensetive function

# capitalize
string1 = "this is string"
print(string1.capitalize()) #This is a string

# replace
string2 = "shivkumar is a good good boy"
print(string2.replace("good", "bad")) # it does not change the original string instead returns a new string
print(string2)

#  slicing a string 
shortstring  = name[0:3] #start from 0 index till3 with 3 excluding
# default value before colon is 0 and after is len -1
shortstring1 = name[-4:-1]
print(shortstring)
print(shortstring1)
print(name[1])

# 
string1 = "0123456789"
print(string1[2:6:3]) #third value is difference