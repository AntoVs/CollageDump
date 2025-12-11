a = float(input("enter the number 1 :"))
b = float(input("enter the number 2 :"))

c = input ("ENter your operation :{+ - * / }")
if (c == '+'):
	print("result is ", a + b)
elif (c == '-'):
	print("result is ", a - b)
elif (c == '/'):
	if (b == 0):
		print("cannot div by 0 !")
	else :
		print("result is ", a / b)
elif (c == '*'):
	print("result is ", a * b)
