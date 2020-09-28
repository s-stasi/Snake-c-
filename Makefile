#Makefile for "Snake" C++ application
#Created by Stasi Samuele  09/2020


PROG = Snake
CC = g++
OBJ = main.o Apple.o Points.o Version.o
LIBS = 
MYLIB = -LSfmlApi/ -ISfmlAPI/ -lSfmlAPI

$(PROG): $(OBJ)
	$(CC) -o $(PROG) -lstdc++fs -lsfml-network -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system $(MYLIB) $(OBJ)

%.o: %.cpp %.hpp
	$(CC) -c $^ -lstdc++fs -lsfml-network -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

libSfmlApi:
	echo "\n \n--------- Building 'SfmlAPI' library ---------\n \n"
	git clone https://s-stasi/SfmlAPI.git
	$(MAKE) -C SfmlAPI