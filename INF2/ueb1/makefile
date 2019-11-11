CC = gcc -Wall
prog = ueb01
obj = main.o time.o tools.o

$(prog) : $(obj)
	@$(CC) -o $@ $^ -lm

$(obj) :
	@$(CC) -c $<

time.o : time.c time.h tools.h

tools.o : tools.c tools.h

main.o : main.c time.h tools.h

clean :
	@rm $(obj) $(prog) -f

all : clean $(prog) run

run : 
	@clear
	@./$(prog)
