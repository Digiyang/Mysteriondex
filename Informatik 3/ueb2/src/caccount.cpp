#include <iostream>
#include "caccount.h"
#include "ccustomer.h"



/////////////////////////////////////////////////////////// Konstruktoren
CAccount::CAccount(string i, CCustomer *c, CMoney b)
: iban{i}, customer{c}, balance{b}
{
    customer->addAccount(this);
}

/////////////////////////////////////////////////////////// print
void CAccount::print() const
{
    cout << "Kunde:      "; customer->printName(); cout << endl;
    cout << "IBAN:       "; printIban(); cout << endl;
    cout << "Kontontand: "; balance.print();
}

/////////////////////////////////////////////////////////// printIban
void CAccount::printIban() const
{
    string separatedIban = iban;
    int size = separatedIban.size();

    for (int i = 0; (i+1)*4 < size; i++)
        separatedIban.insert((i+1)*4+i, " ");

    cout << separatedIban;
}
