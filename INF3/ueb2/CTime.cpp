#include"CTime.h"
#include <stdio.h>
#include <time.h>
#include<stdarg.h>

CTime::CTime()       //1.Konstruktor
{
   time_t CurrentTime=time(0);
   struct tm *ltm=localtime(&CurrentTime);
   hour = ltm->tm_hour;
   minute = ltm->tm_min;
   seconde = ltm->tm_sec;
}

CTime::CTime(int h, int m, ...)     //2.Konstruktor
{
      hour = h;
      va_list var;
      va_start(var,m);
      minute = m ;
      seconde = va_arg(var,int);
      va_end(var);   
}

void CTime::print()     // Methode
{
   printf("%02d.%02d.%02d", hour, minute, seconde);
}
