def myFunc():
        print("Hello world!")
        
myFunc()
print(__name__) #if used in the orignal program it prints __main__ else prints the name of the file module this is used to check if the file is directly executed or imported from another module

if (__name__ == "__main__"):
        print("Running the orignal file")
