#  slicing a string 
name = "harry"
shortstring  = name[0:3] #start from 0 index till3 with 3 excluding
# default value before colon is 0 and after is len -1
shortstring1 = name[-4:-1]
print(shortstring)
print(shortstring1)
print(name[1])

# 
string1 = "0123456789"
print(string1[2:6:3]) #third value is difference