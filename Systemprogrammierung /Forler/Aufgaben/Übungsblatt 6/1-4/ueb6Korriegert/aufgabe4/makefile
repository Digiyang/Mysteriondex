CFLAGS = -W -Wall -Werror -std=c11

debug2: CFLAGS += -DDEBUG
debug2: ver2

ver2: CFLAGS += -I awesome2
ver2: main

ver3: CFLAGS += -I awesome3
ver3: main

main:


clean:
	$(RM) *~ *.o main

