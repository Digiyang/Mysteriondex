#include <ctime>
#include <iostream>
#include "ctime.h"

using namespace std;

static int is_time_valid(const int hour, const int minute, const int second);



/////////////////////////////////////////////////////////// Konstruktoren
CTime::CTime()
{
    time_t rawtime = time(NULL);
    struct tm *time = localtime(&rawtime);

    hour = time->tm_hour;
    minute = time->tm_min;
    second = time->tm_sec;
}

CTime::CTime(int h, int m, int s)
: hour{h}, minute{m}, second{s}
{
    if (!is_time_valid(hour, minute, second))
    {
        cerr << "invalid time" << endl;
        throw "invalid time";
    }
}

/////////////////////////////////////////////////////////// print
void CTime::print() const
{
    cout.fill('0');
    cout.width(2);
    cout << hour << ':';
    cout.width(2);
    cout << minute;
    if (second)
    {
        cout << ':';
        cout.width(2);
        cout << second;
    }
    cout.fill(' ');
}



/////////////////////////////////////////////////////////// is_time_valid
static int is_time_valid(const int hour, const int minute, const int second)
{
    if (hour   > 23 || hour   < 0 ||
        minute > 59 || minute < 0 ||
        second > 59 || second < 0   )
        return 0;

    return 1;
}

