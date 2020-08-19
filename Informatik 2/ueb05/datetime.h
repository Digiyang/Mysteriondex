#ifndef TIMEUTILS_H
#define TIMEUTILS_H TIMEUTILS_H
#include "datastructure.h"

	int isTimeValid (TTime * timeCheck);

	int getTimeFromString (char * buff, TTime * givenTime);

	int getTime(char * question, int numSong, TCD * CD);

	void printTime(TTime * time);

    void addTime(TCD * T1);

#endif // TIMEUTILS_H_INCLUDED
