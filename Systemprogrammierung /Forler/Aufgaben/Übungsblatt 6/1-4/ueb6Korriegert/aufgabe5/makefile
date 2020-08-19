OBJ = main.o
ERRFLAGS = -W -Wall -Wextra -Werror
OPTFLAGS = -std=c11 -O3
CFLAGS += $(ERRFLAGS) $(OPTFLAGS)

BirneX: CFLAGS += -DBirneX
BirneX: main

BananaMac: CFLAGS += -DBananaMac
BananaMac: main

Doors10: CFLAGS += -DDoors10
Doors10: main

LockedBSE: CFLAGS += -DLockedBSD
LockedBSE: main


clean:   
	$(RM) *~ *.o main
 
