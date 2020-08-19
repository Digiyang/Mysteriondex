CC = gcc -Wall
prog = Matrizenprodukt
obj = ueb09.o matrix.o tools.o

$(prog) : $(obj)
	@$(CC) -o $@ $^ -lm

$(obj) :
	@$(CC) -c $<

matrix.o : matrix.c matrix.h tools.h

tools.o : tools.c tools.h

ueb09.o : ueb09.c matrix.h tools.h

clean :
	@rm $(obj) $(prog) -f

all : clean $(prog) run

run : 
	@clear
	@./$(prog)
