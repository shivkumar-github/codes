# virtual enviroment is an isolated enviroment 

# commands to enter in terminal
# pip install virtualenv
# virtualenv env  ->> creating a new virtual enviroment named env
# select yes when pop up appears for adding this folder 
# to activate the virtual enviroment ->> .\env\Scripts\activate.ps1 ->> to deactivate just use word "deactivate"
# after successfully creating the enviroment a "(env)" name of virtual enviroment will appear in terminal before location name

# pip freeze command shows the packages included in the enviroment

import pandas
print(pandas.__version__)

# it is good to store the version of all packages in a txt file 
# to install all the package mentioned in requirement.txt use pip install -r .\requirements.txt
