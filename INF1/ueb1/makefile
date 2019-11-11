CC = gcc -Wall
PRG = ueb1
OBJ = ueb1.o
Test= a.out

$(PRG): ueb1.o
	$(CC) -o $@ $^

ueb1.o: ueb1.c
	$(CC) -c $< 

run:
	./$(Test)
clean:
	rm $(OBJ) $(PRG) -f

all: clean $(PRG) run

