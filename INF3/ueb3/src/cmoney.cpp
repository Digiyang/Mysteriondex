#include <iostream>
#include <iomanip>
#include "cmoney.h"

using namespace std;



/////////////////////////////////////////////////////////// Konstruktoren
CMoney::CMoney()
: amount{0.0}, currency{"EUR"} {}

CMoney::CMoney(double a, string c)
: amount{a}, currency{c} {}

/////////////////////////////////////////////////////////// print
void CMoney::print() const
{
    cout << fixed << setprecision(2)                    // mit manipulatoren (include iomanip)
         << amount << ' ' << currency << flush;
}
