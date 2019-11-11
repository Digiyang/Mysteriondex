#include <stdio.h>
#include <stdlib.h>
#include "timeutils.h"
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

   if((input = sscanf(buff, "%2s:%2s:%2s", HH, MM, SS)) < 2) return 0;

    if(input == 2){
	    givenTime->Hour = 0;
	    givenTime->Minute = atoi(HH);
	    givenTime->Second = atoi(MM);
    }else{
	    givenTime->Hour = atoi(HH);
	    givenTime->Minute = atoi(MM);
	    givenTime->Second = atoi(SS);
    }

    if(isTimeValid(givenTime)) return 1;

    return 0;
}

int getTime(char * question, int numSong, TCD * CD) 
{

    int scanErg;
    printf("%s",question);
    char input[40];
    TSong *song = CD->songs + numSong;

    do
    {
        scanErg = scanf("%39[^\n]", input);
	    clearBuffer();
        if (scanErg != 0) 
        {
           if (getTimeFromString(input, &(song->Dauer)) == 1) 
           {
	      return 1;
           }
           else
              scanErg = 0;
        }
    } while (scanErg == 0);
    return 0;
}




void printTime(TTime * time) {

    printf("%d:%d",time->Minute, time->Second);
}
