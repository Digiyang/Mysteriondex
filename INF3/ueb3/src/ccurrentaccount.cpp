#include <iostream>
#include "ccurrentaccount.h"



/////////////////////////////////////////////////////////// Kon- und Destruktoren
CCurrentAccount::CCurrentAccount(CBank *bnk, string i, CCustomer *c, CMoney blnc, CMoney *d)
: CAccount{bnk, i, c, blnc}, disposit{d} {}

CCurrentAccount::~CCurrentAccount()
{
    cout << "CCurrentAccount:      Konto ("; printIban(); cout << ") vernichtet!" << endl;
}

/////////////////////////////////////////////////////////// print
void CCurrentAccount::print() const
{
    CAccount::print();
    cout << "\nDispo     : "; disposit->print();
}
