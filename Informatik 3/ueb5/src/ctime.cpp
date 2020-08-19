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

/////////////////////////////////////////////////////////// print
void CTime::print() const
{
    char oldFillchar = cout.fill('0');                  // normale Variante
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
    cout << flush;
    cout.fill(oldFillchar);
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

