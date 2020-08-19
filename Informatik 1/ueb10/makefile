CC = gcc -Wall
PROG = ueb10
OBJ = ueb10.o tools.o Funktionen.o 

$(PROG): $(OBJ)
	$(CC) -g -o $@ $^ -lm

ueb10.o: ueb10.c Funktionen.h tools.h escapesequenzen.h
	$(CC) -c $<

Funktionen.o: Funktionen.c tools.h escapesequenzen.h
	$(CC) -c $<

tools.o: tools.c tools.h escapesequenzen.h
	$(CC) -c $<

run:
	./$(PROG)
   
clean:
	rm $(PROG) $(OBJ) -f

all: clean $(PROG) run
