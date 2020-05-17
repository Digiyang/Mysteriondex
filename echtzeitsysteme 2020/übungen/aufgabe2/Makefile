CC = gcc -std=c11
WARNFLAGS = -W -Wall -Wextra -Werror
OPTFLAGS = -O3
DEBUGFLAGS = -ggdb3 -DDEBUG
CFLAGS += $(WARNFLAGS)
OBJORPHAN= orphan.o

ifdef DEBUG
	CFLAGS += $(DEBUGFLAGS)
else
	CFLAGS += $(OPTFLAGS)
endif

all: orphan

orphan: $(OBJORPHAN)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) *~ *.o orphan
