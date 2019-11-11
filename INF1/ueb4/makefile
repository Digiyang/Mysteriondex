CC = gcc -Wall
PRG = ueb4
OBJ = ueb4.o
Test= ueb4

$(PRG): ueb4.o
	$(CC) -o $@ $^ -lm

ueb4.o: ueb4.c
	$(CC) -c $< 

run:
	./$(Test)
clean:
	rm $(OBJ) $(PRG) -f

all: clean $(PRG) run

