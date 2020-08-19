#include <iostream>
#include "cbank.h"
#include "ccustomer.h"
#include "tools.h"



//////////////////////////////////////////////////////////// Kon- und Destruktoren
CBank::CBank()
: name{""}, BIC{""} {}

CBank::CBank(string n, string b)
: name{n}, BIC{b} {}

CBank::~CBank()
{
    for (auto elem: accountList)
        delete elem;

    cout << "Bank " << name << " wird vernichtet." << endl;
}

//////////////////////////////////////////////////////////// addAccount
void CBank::addAccount(CAccount *newAccount)
{
    accountList.push_back(newAccount);
}

/////////////////////////////////////////////////////////// load
int CBank::load(ifstream &source)
{
    string line;

    do
    {
        getline(source, line);

        if (line.find("<Name>") != string::npos)
        {
            removeTags(line, "Name");
            name = line;
        }
        else if (line.find("<BIC>") != string::npos)
        {
            removeTags(line, "BIC");
            BIC = line;
        }

    } while (line.find("</Bank>") == string::npos);

    return 0;
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
