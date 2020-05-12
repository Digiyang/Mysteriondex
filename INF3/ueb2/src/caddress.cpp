#include <iostream>
#include "caddress.h"

using namespace std;



/////////////////////////////////////////////////////////// Konstruktoren
CAddress::CAddress(string s, string p, string t)
: street{s}, postcode{p}, town{t} {}

/////////////////////////////////////////////////////////// print
void CAddress::print() const
{
    cout << street << endl;
    cout << postcode << ' ' << town;
}
