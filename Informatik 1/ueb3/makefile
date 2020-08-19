CC = gcc -Wall
PRG = ueb3
OBJ = ueb3.o
Test= ueb3

$(PRG): ueb3.o
	$(CC) -o $@ $^

ueb1.o: ueb3.c
	$(CC) -c $< 

run:
	./$(Test)
clean:
	rm $(OBJ) $(PRG) -f

all: clean $(PRG) run

