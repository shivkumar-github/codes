# make spam detecting code with spamming strings 
# "Make a lot of money", "buy now", "subscribe this", "click this"

p1 = "Make a lot of money"
p2 = "buy now"
p3 = "subscribe this"
p4 = "click this"

message = input("Enter your message")

# if(message.find(p1) != -1 or message.find(p2) != -1 or message.find(p3) != -1 or message.find(p4) != -1):
#         print("Message is spam")
# else:
#         print("Message is not spam")

if((p1 in message) != -1 or (p2 in message) != -1 or (p3 in message) != -1 or (p4 in message) != -1):
        print("Message is spam")
else:
        print("Message is not spam")