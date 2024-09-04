# write a programe to fill letter template given with name and date
letter = ''' Dear <|Name|>, 
You are selected!
<|Date|>'''
                
print(letter.replace("<|Name|>", "Shivkumar").replace("<|Date|>", "22nd July"))
