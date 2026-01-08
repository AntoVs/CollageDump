class shoppingcart:
    def __init__(self):
        self.product = {}
    def add(self,prod,price):
        self.product[prod] = price
    def rem(self,prod):
        del self.product[prod]
    def disp(self):
        for key,value in self.product.items():
            print(f"{key}: {value}")
        print("total Price :",sum(self.product.values()))
    def calc(self):
        print("total Price :",sum(self.product.values()))

sc = shoppingcart()
while(1):
    a = int(input("\n1.AddItem\n2.RemoveItem\n3.DisplayCart\n4.Exit\nEnter Your Choice:"))
    if (a == 1):
        b = input("Enter the product : ")
        c = int(input("Enter the price : "))
        sc.add(b,c)
    elif (a == 2):
        b = input("Enter Item to delete : ")
        sc.rem(b)
    elif (a == 3):
        sc.disp()
    elif (a == 4):
        print("Exiting !")
        break
    else:
        print("Invalid Choice ! ")