#include <iostream>
#include "cbank.h"
#include "ccustomer.h"



//////////////////////////////////////////////////////////// Konstruktoren
CBank::CBank(string n, string b)
: name{n}, BIC{b} {}

//////////////////////////////////////////////////////////// addAccount
void CBank::addAccount(CAccount *newAccount)
{
    accountList.push_back(newAccount);
}

//////////////////////////////////////////////////////////// print
void CBank::print() const
{
    cout << name
         << "\nBIC " << BIC
         << "\nAnzahl der Konten: " << accountList.size()
         << "\nKontenliste: \n"
         << "IBAN                        | Kundenname           | Anz.Buchungen | Kontostand     \n"
         << "----------------------------|----------------------|---------------|----------------" << endl;

    for (auto elem: accountList)
    {
        elem->printIban(); cout << " | ";
        cout.width(20); cout << left << (elem->getCustomer())->getName() << " | ";
        cout.width(13); cout << right << 0 << " | ";    // Platzhalter, bookings sind noch nicht implementiert
        cout.width(10); (elem->getBalance()).print();
        cout << endl;
    }
}
