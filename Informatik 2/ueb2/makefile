CC = gcc -Wall
prog = ueb02
obj = main.o datetime.o tools.o menu.o

$(prog) : $(obj)
	@$(CC) -o $@ $^ -lm

$(obj) :
	@$(CC) -c $<

menu.o : menu.c menu.h 

datetime.o : datetime.c datetime.h datastructure.h tools.h

tools.o : tools.c tools.h

main.o : main.c tools.h menu.h

clean :
	@rm $(obj) $(prog) -f

all : clean $(prog) run

run : 
	@clear
	@./$(prog)
