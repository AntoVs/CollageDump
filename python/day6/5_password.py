import tkinter as ola

def check():
    a = userbox.get()
    b = passbox.get()
    if (a == "admin") and (b == "1234"):
        label3.config(text="LoginSuccesfull")
    else:
        label3.config(text="LoginFailed")

wind = ola.Tk()
wind.geometry("800x400")
wind.title("LoginPage")
label1 = ola.Label(wind, text="Enter UserName :")
label1.pack()
userbox = ola.Entry(wind)
userbox.pack()
label2 = ola.Label(wind, text="Enter Password :")
label2.pack()
passbox = ola.Entry(wind)
passbox.pack()
but1 = ola.Button(wind, text="Submit", command = check)
but1.pack()
label3 = ola.Label(wind)
label3.pack()
wind.mainloop()