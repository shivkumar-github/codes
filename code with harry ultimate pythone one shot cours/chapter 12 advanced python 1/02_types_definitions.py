# types hints are added using : syntax for vcariables and -> for function return types (they help to understand the code better)
age : int = 22
name : str = "shivkumar"

def greeting(name:str)->str:
        return f"Hello! {name}"

print(greeting("shivkumar"))

# pythons typing module provides advanced types of hint like L:ist m Tuple and Dict
from typing import List, Tuple, Dict, Union

# list of integers
numbers : List[int] = [1,2,3,4]

# touple of a string and a integer
person : Tuple [str,int] =  ("shivkumar", 22)

# dictionary with a string key and integer value
# i said no code
scores : Dict[str, int] = {"shivkumar": 22}


# union type for variables and function return types
identifiers :Union[int,str] =  'shivkumar2211'

