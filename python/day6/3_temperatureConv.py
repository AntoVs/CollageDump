import tkinter as tinker

def ctof():
    c = float(cbox.get())
    f = (c*(9/5)) + 32
    resbox.config(text=f"{f} f")

def ftoc():
    f = float(cbox.get())
    c = (f - 32)* 5/9
    resbox.config(text=f"{c} c")

wind = tinker.Tk()
wind.geometry("800x400")
wind.title("celc to f converter")

ques = tinker.Label(wind ,text = "Enter value in celcius :")
ques.pack()
cbox = tinker.Entry(wind)
cbox.pack()
button = tinker.Button(wind,text="celcius to Farenheit" , command = ctof)
button.pack()
button = tinker.Button(wind,text="Farenheit to celcius" , command = ftoc)
button.pack()
resbox = tinker.Label(wind)
resbox.pack()

wind.mainloop()