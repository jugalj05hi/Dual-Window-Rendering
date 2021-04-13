# Run with:
#
# (Linux & Mac) python3.5 test.py -m ./mygameengine.so
# (Windows) python3.6 test.py -m ./mygameengine.pyd
#
# The program should also run with 'python2.7' but you will have
# to change the 3.5's to 2.7's in your respective build script as
# well as make sure you compiled with 3.5 or 2.7 load flags.
#
# You will see `python3.5-config --includes` for example which corresponds
# to which version of python you are building.
# (In fact, run `python3.5-config --includes` in the terminal to see what it does!)
import mygameengine

# Now use some python libraries for random numbers!
import random
import threading


# Initialize SDL
test = mygameengine.Engine()


# Our main game loop
# Note: This is a simple game that loops for 20 iterations and then
#       exits. 
from tkinter import *
# test.Loop()

master = Tk()

def var_states():
    print(test.Loop())
#    print("mDone")
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
Checkbutton(master, text="AI ?", variable=var1,command=setAI).grid(row=1, sticky=W)
# start_button = Button(YourFrame, command = lambda:threading.Thread(target = readSensor).start()) #YourFrame is the Frame widget where you placed the start button

var2 = BooleanVar()
Checkbutton(master, text="Input ?", variable=var2,command=setInput).grid(row=2, sticky=W)
var3 = BooleanVar()
Checkbutton(master, text="Collidable?", variable=var3,command=setCollision).grid(row=3, sticky=W)
var4 = BooleanVar()
Checkbutton(master, text="Collectible?", variable=var4,command=setCollectible).grid(row=4, sticky=W)
var5 = BooleanVar()
Checkbutton(master, text="Gravity?", variable=var5,command=setGravity).grid(row=5, sticky=W)

Button(master, text='Quit', command=master.quit).grid(row=6, sticky=W, pady=4)
Button(master, text='Show', command=NONE).grid(row=7, sticky=W, pady=4)

# mainloop()

# while(1):
    # master.after(0,setAI)
    # master.after(0,setCollision)
threading.Thread(target=test.Loop()).start()

threading.Thread(target=master.mainloop()).start()

# master.update_idletasks()
# master.update()

# print(test.gridNumber())
    # update()
# mainloop()

    # or
# print("Setting up game loop")
# for i in range(0,20):
#     # Clear the screen
#     # test.clear()
#     # Generate random coordinates for our box
#     x = random.randint(1,400)
#     y = random.randint(1,400)
#     test.DrawRectangle(x,y,10,10)
#     # Add a little delay
#     test.delay(100)
#     # Refresh the screen
#     test.flip()

