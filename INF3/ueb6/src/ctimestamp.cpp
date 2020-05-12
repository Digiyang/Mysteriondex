#include <iostream>
#include <ctime>
#include "ctimestamp.h"



//////////////////////////////////////////////////////////// statische Variablen
bool CTimestamp::printTime = true;

//////////////////////////////////////////////////////////// Manipulatoren
ostream &printOnlyDate(ostream &os)
{
    CTimestamp::printTime = false;
    return os;
}

ostream &printDateTime(ostream &os)
{
    CTimestamp::printTime = true;
    return os;
}

//////////////////////////////////////////////////////////// Konstruktoren
CTimestamp::CTimestamp()
: CDate{}, CTime{}
{
    time_t rawtime = time(NULL);
    struct tm *time = localtime(&rawtime);

    switch (time->tm_wday)
    {
        case 0: weekday = SUNDAY;       break;
        case 1: weekday = MONDAY;       break;
        case 2: weekday = TUESDAY;      break;
        case 3: weekday = WEDNESDAY;    break;
        case 4: weekday = THURSDAY;     break;
        case 5: weekday = FRIDAY;       break;
        case 6: weekday = SATURDAY;     break;
    }
}

//////////////////////////////////////////////////////////// Operatoren
ostream &operator<< (ostream &os, const CTimestamp &ts)
{
    switch (ts.weekday)
    {
        case SUNDAY:    os << "So, "; break;
        case MONDAY:    os << "Mo, "; break;
        case TUESDAY:   os << "Di, "; break;
        case WEDNESDAY: os << "Mi, "; break;
        case THURSDAY:  os << "Do, "; break;
        case FRIDAY:    os << "Fr, "; break;
        case SATURDAY:  os << "Sa, "; break;
    }
    os << static_cast<CDate>(ts);
    if (ts.printTime)
        os << "; " << static_cast<CTime>(ts);

    return (os << flush);
}
