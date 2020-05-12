#include <iostream>
#include "caddress.h"
#include "tools.h"

using namespace std;



/////////////////////////////////////////////////////////// Konstruktoren
CAddress::CAddress(string s, string p, string t)
: street{s}, postcode{p}, town{t} {}

/////////////////////////////////////////////////////////// load
int CAddress::load(ifstream &source)
{
    string line;

    do
    {
        getline(source, line);

        if (line.find("<Street>") != string::npos)
        {
            removeTags(line, "Street");
            street = line;
        }
        else if (line.find("<Postcode>") != string::npos)
        {
            removeTags(line, "Postcode");
            postcode = line;
        }
        else if (line.find("<Town>") != string::npos)
        {
            removeTags(line, "Town");
            town = line;
        }

    } while (line.find("</Address>") == string::npos);

    return 0;
}

/////////////////////////////////////////////////////////// print
void CAddress::print() const
{
    cout << street << '\n'
         << postcode << ' ' << town << flush;
}
