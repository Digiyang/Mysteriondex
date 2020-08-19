#include <stdio.h>
#include <stdlib.h>
#include "datetime.h"
#include "datastructure.h"
#include "tools.h"



int isTimeValid (TTime * timeCheck) {


    if (timeCheck->Hour >= 24 || timeCheck->Minute >= 60 || timeCheck->Second >= 60) return 0;
    if (timeCheck->Hour < 0 || timeCheck->Minute < 0 || timeCheck->Second < 0) return 0;
    return 1;
}


int getTimeFromString (char * buff, TTime * givenTime){

    int input;


    char * HH = malloc(sizeof(char));
    char * MM = malloc(sizeof(char));
    char * SS = malloc(sizeof(char));

   if((input = sscanf(buff, "%2s:%2s:%2s", HH, MM, SS)) < 3) return 0;


    givenTime->Hour = atoi(HH);
    givenTime->Minute = atoi(MM);
    givenTime->Second = atoi(SS);


    if(isTimeValid(givenTime)) return 1;

    return 0;
}

