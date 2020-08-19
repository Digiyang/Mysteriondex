#include <ctime>
#include <iostream>
#include "ctime.h"
#include "tools.h"

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

/////////////////////////////////////////////////////////// Operatoren
ostream &operator<< (ostream &os, const CTime &t)
{
    char oldFillchar = os.fill('0');                    // normale Variante
    os.width(2);
    os << t.hour << ':';
    os.width(2);
    os << t.minute;
    if (t.second)
    {
        os << ':';
        os.width(2);
        os << t.second;
    }
    os.fill(oldFillchar);

    return os << flush;
}

/////////////////////////////////////////////////////////// load
int CTime::load(ifstream &source)
{
    string line;

    do
    {
        getline(source, line);

        if (line.find("<Hour>") != string::npos)
        {
            removeTags(line, "Hour");
            hour = stoi(line);
        }
        else if (line.find("<Minute>") != string::npos)
        {
            removeTags(line, "Minute");
            minute = stoi(line);
        }
        else if (line.find("<Second>") != string::npos)
        {
            removeTags(line, "Second");
            second = stoi(line);
        }

    } while (line.find("</Time>") == string::npos);

    return 0;
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

