#include <iostream>
#include <ctime>
#include "ctimestamp.h"



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

//////////////////////////////////////////////////////////// print
void CTimestamp::print() const
{
    switch (weekday)
    {
        case SUNDAY:    cout << "So, "; break;
        case MONDAY:    cout << "Mo, "; break;
        case TUESDAY:   cout << "Di, "; break;
        case WEDNESDAY: cout << "Mi, "; break;
        case THURSDAY:  cout << "Do, "; break;
        case FRIDAY:    cout << "Fr, "; break;
        case SATURDAY:  cout << "Sa, "; break;
    }
    CDate::print(); cout << "; ";
    CTime::print(); cout << flush;
}
