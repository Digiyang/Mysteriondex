#include <iostream>
#include <iomanip>
#include "cmoney.h"
#include "tools.h"

using namespace std;



/////////////////////////////////////////////////////////// Konstruktoren
CMoney::CMoney()
: amount{0.0}, currency{"EUR"} {}

CMoney::CMoney(double a, string c)
: amount{a}, currency{c} {}

/////////////////////////////////////////////////////////// load
int CMoney::load(ifstream &source)
{
    string line;

    do
    {
        getline(source, line);

        if (line.find("<Amount>") != string::npos)
        {
            removeTags(line, "Amount");
            amount = stod(line);
        }
        else if (line.find("<Currency>") != string::npos)
        {
            removeTags(line, "Currency");
            currency = line;
        }

    } while (line.find("</Balance>") == string::npos &&
             line.find("</Dispo>") == string::npos    );

    return 0;
}

/////////////////////////////////////////////////////////// print
void CMoney::print() const
{
    cout << fixed << setprecision(2)                    // mit manipulatoren (include iomanip)
         << amount << ' ' << currency << flush;
}
