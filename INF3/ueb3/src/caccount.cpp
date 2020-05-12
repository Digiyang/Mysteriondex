#include <iostream>
#include "caccount.h"
#include "ccustomer.h"
#include "cbank.h"



/////////////////////////////////////////////////////////// Kon- und Destruktoren
CAccount::CAccount(CBank *bnk, string i, CCustomer *c, CMoney blnc)
: bank{bnk}, iban{i}, customer{c}, balance{blnc}
{
    customer->addAccount(this);
    bank->addAccount(this);
}

CAccount::~CAccount()
{
    cout << "CAccount:             Konto ("; printIban(); cout << ") vernichtet!" << endl;
}

/////////////////////////////////////////////////////////// print
void CAccount::print() const
{
    cout << "Kunde     : "; customer->printName();
    cout << "\nIBAN / BIC: "; printIban(); cout << " / " << bank->getBIC()
         << "\nKontontand: "; balance.print();
}

/////////////////////////////////////////////////////////// printIban
void CAccount::printIban() const
{
    string separatedIban = iban;
    int size = separatedIban.size();

    for (int i = 0; (i+1)*4 < size; i++)
        separatedIban.insert((i+1)*4+i, " ");

    cout << separatedIban << flush;
}
