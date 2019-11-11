CC = gcc -Wall
ZUSATZ = -o 
OBJ = main.o datetime.o database.o tools.o menu.o cds.o sort.o
PROG = main


$(PROG): $(OBJ)
	$(CC) $(ZUSATZ) $@ $^


main.o: main.c datastructure.h tools.h  database.h menu.h cds.h
	$(CC) -c $<

database.o: database.c database.h tools.h escapesequenzen.h datastructure.h 
	$(CC) -c $<

tools.o: tools.c tools.h escapesequenzen.h
	$(CC) -c $<

menu.o: menu.c tools.h menu.h
	$(CC) -c $<



cds.o: cds.c cds.h sort.h
	$(CC) -c $<

sort.o: sort.c sort.h
	$(CC) -c $<	

clean:
	rm $(OBJ) $(PROG) -f


run:
	./$(PROG)


all: clean $(PROG) run



