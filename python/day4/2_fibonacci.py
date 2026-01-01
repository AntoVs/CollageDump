def fibo(n):
    if (n==0):
        print (" ")
    elif (n == 1):
        print ("0")
    else:
        pre = 0
        current = 1
        print("0 1",end=" ")
        for x in range (1,n-1):
            next = pre + current
            print(next,end="  ")
            pre = current
            current = next
    print()

n = int(input("enter the number of terms :"))
fibo(n)