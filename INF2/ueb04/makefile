CC = gcc -Wall
ZUSATZ = -o 
OBJ = main.o database.o tools.o menu.o cds.o timeutils.o
PROG = main


$(PROG): $(OBJ)
	$(CC) $(ZUSATZ) $@ $^


main.o: main.c datastructure.h tools.h  database.h menu.h cds.h
	$(CC) -c $<

database.o: database.c database.h tools.h escapesequenzen.h datastructure.h timeutils.c timeutils.h
	$(CC) -c $<

tools.o: tools.c tools.h escapesequenzen.h
	$(CC) -c $<

menu.o: menu.c tools.h menu.h
	$(CC) -c $<

timeutils.o: timeutils.c timeutils.h
	$(CC) -c $<	

cds.o: cds.c cds.h
	$(CC) -c $<

clean:
	rm $(OBJ) $(PROG) -f


run:
	./$(PROG)


all: clean $(PROG) run



