from tkinter import *
master = Tk()

def var_states():
   print("mDone")
def setAI():
    print(var1.get())
def setCollectible():
    print(var4.get())
def setCollision():
    print(var3.get())
def setInput():
    print(var1.get())
def setGravity():
    print(var5.get())


Label(master, text="What features you want to add to the current tile?").grid(row=0, sticky=W)
var1 = BooleanVar()
var1.set(True)
Checkbutton(master, text="AI ?", variable=var1,command=setAI).grid(row=1, sticky=W)
var2 = BooleanVar()
Checkbutton(master, text="Input ?", variable=var2,command=setInput).grid(row=2, sticky=W)
var3 = BooleanVar()
Checkbutton(master, text="Collidable?", variable=var3,command=setCollision).grid(row=3, sticky=W)
var4 = BooleanVar()
Checkbutton(master, text="Collectible?", variable=var4,command=setCollectible).grid(row=4, sticky=W)
var5 = BooleanVar()
Checkbutton(master, text="Gravity?", variable=var5,command=setGravity).grid(row=5, sticky=W)



Button(master, text='Quit', command=master.quit).grid(row=6, sticky=W, pady=4)
Button(master, text='Show', command=var_states).grid(row=7, sticky=W, pady=4)
mainloop()