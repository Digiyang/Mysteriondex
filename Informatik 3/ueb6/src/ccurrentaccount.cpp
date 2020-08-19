#include <iostream>
#include "ccurrentaccount.h"



/////////////////////////////////////////////////////////// Kon- und Destruktoren
CCurrentAccount::CCurrentAccount()
: CAccount{}, disposit{NULL} {}

CCurrentAccount::CCurrentAccount(CBank *bnk, string i, CCustomer *c, CMoney blnc, CMoney *d)
: CAccount{bnk, i, c, blnc}, disposit{d} {}

CCurrentAccount::~CCurrentAccount()
{
    delete disposit;
    cout << "CCurrentAccount:      Konto ("; printIban(); cout << ") vernichtet!" << endl;
}

/////////////////////////////////////////////////////////// load
int CCurrentAccount::load(ifstream &source, vector<CBank *> &bList, vector<CCustomer *> &cList)
{
    string line;

    do
    {
        getline(source, line);

        loadAccountData(line, source, bList, cList);
        loadCurrentAccountData(line, source);

    } while (line.find("</CurrentAccount>") == string::npos);

    return 0;
}

/////////////////////////////////////////////////////////// loadCurrentAccountData
int CCurrentAccount::loadCurrentAccountData(string &line, ifstream &source)
{
    if (line.find("<Dispo>") != string::npos)
    {
        disposit = new CMoney();
        disposit->load(source);

        return 1;
    }

    return 0;
}

/////////////////////////////////////////////////////////// print
ostream &CCurrentAccount::print(ostream &os) const
{
    CAccount::print(os) << "\nDispo     : "; disposit->print();

    return os << flush;
}
