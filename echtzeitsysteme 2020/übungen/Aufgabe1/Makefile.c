CC = gcc -std=c11
WARNFLAGS = -W -Wall -Wextra -Werror
OPTFLAGS = -O3
DEBUGFLAGS = -ggdb3 -DDEBUG
CFLAGS += $(WARNFLAGS)
PROG = main
QUEUEDEMO = queuedemo
ERROR = queuedemoerror


prototype_process: prototype_process.c
	$(CC) -o prototype_process  prototype_process.c process.c

queuedemo: queuedemo.c
	$(CC) -o queuedemo	queuedemo.c queue.c process.c

queuedemoerror: queuedemoerror.c
	$(CC) -o queuedemoerror	queuedemoerror.c queue.c process.c

main: main.c
	$(CC) -o main	main.c processmodel.c queue.c process.c

ifdef DEBUG
CFLAGS += $(DEBUGFLAGS)
else
CFLAGS += $(OPTFLAGS)
endif

clean0:
	rm $(OBJ) $(PROG) -f

clean1:
	rm $(OBJ) $(QUEUEDEMO) -f

clean2:
	rm $(OBJ) $(ERROR) -f

run:
	./$(PROG)


all: clean $(PROG) run