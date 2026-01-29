import tkinter as tinker

def fun():
    a = int(input_1.get())
    if a%2 == 0:
        label_2.config(text=f"{a} is even")
    else:
        label_2.config(text=f"{a} is odd")

wind = tinker.Tk()
wind.geometry("800x400")
label_1 = tinker.Label(wind, text="Enter Number :")
input_1 = tinker.Entry(wind)
but_1 = tinker.Button(wind, text="Check", command = fun)
label_2 = tinker.Label(wind)
label_1.pack()
input_1.pack()
but_1.pack()
label_2.pack()

wind.mainloop()