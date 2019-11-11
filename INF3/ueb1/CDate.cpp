#include "CDate.h"
#include <stdio.h>
#include <time.h>

CDate::CDate()       //1.Konstruktor
{
   time_t TT = time(NULL);
   struct tm *timeinfo = localtime(&TT);
   day = timeinfo->tm_mday;
   month = timeinfo->tm_mon+1;
   year = timeinfo->tm_year+1900;
}

CDate::CDate(int dd, int mm, int yyyy)      //2.Konstruktor
{
   day = dd;
   month = mm;
   year = yyyy;
}

void CDate::print()     // Methode
{
   printf("%02d.%02d.%4d", day, month, year);
}
