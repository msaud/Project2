CC = g++
CPPFLAGS =-c -Wall -g -std=c++11

all: Chicken.exe

Chicken.exe: Driver.o Bone.o ChickenYard.o Player.o Game.o Field.o
	$(CC)  Driver.o Bone.o ChickenYard.o Player.o Game.o Field.o -o Chicken.exe
Driver.o: Driver.cpp
	$(CC) $(CPPFLAGS) Driver.cpp
Bone.o: Bone.cpp
	$(CC) $(CPPFLAGS) Bone.cpp
ChickenYard.o: ChickenYard.cpp
	$(CC) $(CPPFLAGS) ChickenYard.cpp
Player.o: Player.cpp
	$(CC) $(CPPFLAGS) Player.cpp
Game.o: Game.cpp
	$(CC) $(CPPFLAGS) Game.cpp
Field.o: Field.cpp
	$(CC) $(CPPFLAGS) Field.cpp

.PHONY: clean
clean:			# clean the directory
			$(info -- cleaning the directory --)
			rm -f *.o
			rm -f Chicken.exe
