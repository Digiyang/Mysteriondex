#include <iostream>
#include "csavingsaccount.h"



/////////////////////////////////////////////////////////// Kon- und Destruktoren
CSavingsAccount::CSavingsAccount(CBank *bnk, string i, CCustomer *c, CMoney blnc, float r)
: CAccount{bnk, i, c, blnc}, interestRate{r} {}

CSavingsAccount::~CSavingsAccount()
{
    cout << "CSavingsAccount:      Konto ("; printIban(); cout << ") vernichtet!" << endl;
}

/////////////////////////////////////////////////////////// print
void CSavingsAccount::print() const
{
    CAccount::print();
    cout << "\nSparzinsen : " << interestRate << " %" << flush;
}
