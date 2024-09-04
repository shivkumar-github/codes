def main():
        try:
                a = int(input("Hey Enter a number : "))
                return(a)
                
        except Exception as e: 
                return(e)
                
        else:#else used with try , we enters else when try is successfully executed
                return ("I am inside else")
        
        finally: #finally statement executed definitely (it also overwrites return)
                print("I am in finally!")
                
main()
