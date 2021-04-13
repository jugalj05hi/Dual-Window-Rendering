# Why am I not using Make?
# 1.)   I want total control over the system. 
#       Occassionally I want to have some logic
#       in my compilation process.
# 2.)   Realistically our projects are 'small' enough 
#       this will not matter.
# 3.)   Feel free to implement your own make files.
# 4.)   It is handy to know Python


import os

COMPILER="c++"

SOURCE="./src/*.cpp"

# You can can add other arguments as you see fit.
# What does the "-D MAC" command do? 
ARGUMENTS="-D MAC -std=c++11 -shared -fPIC -undefined dynamic_lookup -rpath ./"

# Which directories do we want to include.
INCLUDE_DIR="-I ./include/ -I./pybind11/include/ -I/usr/local/include/ -I/Library/Frameworks/SDL2.framework/Headers `python3.9 -m pybind11 --includes`"
#clang++ -framework SDL2 -F ./Frameworks Source/main.cpp -o ./Output/main_test -rpath @executable_path/
    # INCLUDE_DIR="-I ./include/ -I/Library/Frameworks/SDL2.framework/Headers -I./../common/thirdparty/old/glm"
    # LIBRARIES="-F/Library/Frameworks -framework SDL2_ttf -framework SDL2_mixer -framework SDL2_image -framework SDL2"
# What libraries do we want to include
LIBRARIES="-F/Library/Frameworks -framework SDL2_ttf -framework SDL2_mixer -framework SDL2_image -framework SDL2 `python3.9-config --ldflags`"

# The name of our executable
EXECUTABLE="mygameengine.so"

# Build a string of our compile commands that we run in the terminal
compileString=COMPILER+" "+ARGUMENTS+" -o "+EXECUTABLE+" "+" "+INCLUDE_DIR+" "+SOURCE+" "+LIBRARIES

# Print out the compile string
print(compileString)

# Run our command
os.system(compileString)
