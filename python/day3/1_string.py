a = input("Enter your String : ")

print("length of the string is :",len(a))
print("String in uppercase : ",a.upper())
print("String in lowercase : ",a.lower())
rev = a[::-1]
print("reverse is :",rev)

if(a == rev) :
	print("The given string is a palindrome")
else :
	print("The given string is not a palindrome")

count = 0
for i in a:
	if i in ("aeiouAEIOU") :
		count +=1
		a = a.replace(i,'_')
print("replaced string :",a)
print("no of vowels = ",count)
