from random import randint
class train:
        def __init__(self,trainNo):
                self.trainNo = trainNo
        
        def book(self,fro, to):
                print(f"Ticket is booked in train number : {self.trainNo}, from {fro} to {to}")
                
        def getStatus (self):
                print(f"train no {self.trainNo} is running on time")
                
        def getFare (self, fro, to):
                print(f"Ticket fare in train no : {self.trainNo}, from {fro} to {to} is {randint(22,666)}")
                
                
t1 = train(155)
t1.book("kolhapur", "mumbai")
t1.getFare("kolhpur", "mumbai")