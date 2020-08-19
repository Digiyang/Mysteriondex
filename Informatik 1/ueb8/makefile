CC = gcc -Wall
PROG = ueb08
OBJ = ueb08.o 

$(PROG): ueb08.o
	 $(CC) -g -o $@ $^ -lm

ueb08.o: ueb08.c escapesequenzen.h
	 $(CC) -c $<

run:
	./$(PROG)
   
clean:
	rm $(PROG) $(OBJ) -f

all: clean $(PROG) run
