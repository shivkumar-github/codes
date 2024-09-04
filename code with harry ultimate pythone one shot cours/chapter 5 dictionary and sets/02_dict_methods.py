empty_dict = {}
print(type(empty_dict))
marks= {
        "key" : "value",
        "harry" : "23",
        "shivkumar" : "34",
        0 : "ramesh"
}

# # printing all items
# print(marks.items())

# # printing keys
# print(marks.keys())

# # printitng values
# print(marks.values())

# # updating dictionary
# marks.update({"harry" : "99"})
# # pairs which are not present will be added
# marks.update({"renuka" : 100})

# print(marks)

# get method
print(marks.get("harry"))
print(marks.get("girl1")) #prints none
# print(marks["girl1"]) ->> it throws error


# pop
marks.pop("harry")
print(marks)

# popitem