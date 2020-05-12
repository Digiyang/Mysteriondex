#include <iostream>
#include "ccustomer.h"



/////////////////////////////////////////////////////////// Konstruktoren
CCustomer::CCustomer(long i, string n, CDate b, CAddress a)
: id{i}, name{n}, birthday{b}, address{a} {}

/////////////////////////////////////////////////////////// addAccount
void CCustomer::addAccount(CAccount *newAccount)
{
    accountList.push_back(newAccount);
}

/////////////////////////////////////////////////////////// print
void CCustomer::print() const
{
    printName(); cout << endl;
    address.print(); cout << endl;
    cout << "geboren am: "; birthday.print();
    cout << "\nKonten:";
    for (auto elem: accountList)
    {
        cout << "\n- Kontonr.: "; elem->printIban();
    }
}

/////////////////////////////////////////////////////////// printName
void CCustomer::printName() const
{
    cout << name << " (Kd-Nr. " << id << ")";
}
