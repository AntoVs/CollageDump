class bank :
    def __init__(self,name,acc,balance):
        self.name = name
        self.acc = acc
        self.balance = balance
    
    def deposit(self,amount):
        self.balance += amount
        print("current Balance :",self.balance)
    
    def withdraw(self,amount):
        if(self.balance >= amount):
            self.balance -= amount
            print("current Balance :",self.balance)
        else:
            print("Insufficient Balance !")
    
    def bal(self):
        print("current Balance :",self.balance)

name = input("Enter Your Name :")
AccNo = int(input("Account Number :"))
Cbal = int(input("Current Account Balance :"))
c1 = bank(name,AccNo,Cbal)

while(1):
    a = int(input("\n1.Deposit\n2.Withdraw\n3.AcoountBalance\n4.Exit\nEnter Your Choice:"))
    if(a == 1):
        b = int(input("Enter money to deposit : "))
        c1.deposit(b)
    elif(a == 2):
        c = int(input("Enter money to Withdraw : "))
        c1.withdraw(c)
    elif(a == 3):
        c1.bal()
    elif(a == 4):
        print("Exiting !")
        break
    else:
        print("Invalid Input !")
