objects = main.o Critter.o Ant.o Doodlebug.o Game.o validate.o

all: game clean

game: $(objects)
	g++ -g $(objects) -o game

clean:
	rm *.o