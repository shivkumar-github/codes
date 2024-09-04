# switch in py 

def http_status(status):
        match status:
                case 200:
                        return "OK"
                case 404:
                        return "Not Found"
                case 500:
                        return "Inernal Server Error"
                case _: #default case
                        return "Unknown status"
                
print(http_status(200))
        