#Tyler Armstrong
#Nov 9, 2022
#CSE170 Final Project
CC = g++ -std=c++17
inc = -I ./inc
file = main.cpp src/*.cpp #shader.cpp shaderprogram.cpp
lib = -L ./lib 
exe = CodeZ.exe

ifdef OS
	link = -lopengl32 -static -lglew32.dll -static -lfreeglut.dll -o

else
   ifeq ($(shell uname), Linux)
		link = -lGL -lGLEW -lglut -o
   endif
endif

all:
	$(CC) $(inc) $(file) $(lib) $(link) $(exe)


debug: #for debugging with gdb
	g++ -g $(exe) -o broken

debugtest: #run gdb
	gdb broken

run: 
	./$(exe)

clean:
	rm -f $(exe)