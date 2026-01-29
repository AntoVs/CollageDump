import tkinter as gojo

wind = gojo.Tk()
wind.geometry("800x400")
wind.title("trial window for frame")

tframe = gojo.Frame(wind)
b = gojo.Label(tframe ,text="helloo")

b.pack()
tframe.pack()
wind.mainloop()