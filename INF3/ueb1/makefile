WARNFLAGS = -W -Wall -Wextra
OPTFLAGS = -std=c++17
DEBUGFLAGS = -ggdb3 -fsanitize=address
CXXFLAGS += $(WARNFLAGS) $(OPTFLAGS)

all: ueb01

ueb01: cdate.cpp

clean:
	$(RM) ueb01 *.o
	$(RM) -r *.dSYM
