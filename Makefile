#Makefile for "Snake" C++ application
#Created by Stasi Samuele  09/2020


PROG = Snake
CC = g++
OBJ = main.o Apple.o MainMenu.o ModMenu.o Points.o Version.o
LIBS = -lstdc++fs -lsfml-network -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
MYLIB = -LSfmlApi/ -ISfmlAPI/ -lSfmlAPI

$(PROG): $(OBJ)
	$(CC) -o $(PROG) $(MYLIB) $(OBJ)

%.o: %.cpp %.hpp
	$(CC) -c $^ $(LIBS)

libSfmlApi:
	echo "\n \n--------- Building 'SfmlAPI' library ---------\n \n"
	git clone https://s-stasi/SfmlAPI.git
	$(MAKE) -C SfmlAPI