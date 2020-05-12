#include <ctime>
#include <iostream>
#include "cdate.h"
#include "tools.h"

using namespace std;

static int is_date_valid(const int day, const int month, const int year);



/////////////////////////////////////////////////////////// Konstruktoren
CDate::CDate()
{
    time_t rawtime = time(NULL);
    struct tm *time = localtime(&rawtime);

    day = time->tm_mday;
    month = time->tm_mon + 1;
    year = time->tm_year + 1900;
}

CDate::CDate(int d, int m, int y)
: day{d}, month{m}, year{y}
{
    if (!is_date_valid(day, month, year))
    {
        cerr << "invalid date" << endl;
        throw "invalid date";
    }
}

/////////////////////////////////////////////////////////// load
int CDate::load(ifstream &source)
{
    string line;

    do
    {
        getline(source, line);

        if (line.find("<Day>") != string::npos)
        {
            removeTags(line, "Day");
            day = stoi(line);
        }
        else if (line.find("<Month>") != string::npos)
        {
            removeTags(line, "Month");
            month = stoi(line);
        }
        else if (line.find("<Year>") != string::npos)
        {
            removeTags(line, "Year");
            year = stoi(line);
        }

    } while (line.find("</Birthday>") == string::npos);

    return 0;
}

/////////////////////////////////////////////////////////// print
void CDate::print() const
{
    char oldFillchar = cout.fill('0');                  // normale Variante
    cout.width(2);
    cout << day << '.';
    cout.width(2);
    cout << month << '.' << year << flush;
    cout.fill(oldFillchar);
}



/////////////////////////////////////////////////////////// is_leap_year
static int is_leap_year(const int year)
{
    if (year%400 == 0)
        return 1;
    if (year%100 == 0)
        return 0;
    if (year%4 == 0)
        return 1;

    return 0;
}

/////////////////////////////////////////////////////////// is_date_valid
static int is_date_valid(const int day, const int month, const int year)
{
    int days_per_month;

    switch (month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: days_per_month = 31;  break;
        case 4:
        case 6:
        case 9:
        case 11: days_per_month = 30;  break;
        case 2:  days_per_month = 28;  break;
        default: return 0;
    }
    if ( (days_per_month == 28) && is_leap_year(year) )
        days_per_month++;

    if (day > days_per_month || day <= 0
     || year > 2117 || year < 1917)
        return 0;

    return 1;
}

