#include <iostream>
#include "csavingsaccount.h"
#include "tools.h"



/////////////////////////////////////////////////////////// Kon- und Destruktoren
CSavingsAccount::CSavingsAccount()
: CAccount{}, interestRate{0.0} {}

CSavingsAccount::CSavingsAccount(CBank *bnk, string i, CCustomer *c, CMoney blnc, float r)
: CAccount{bnk, i, c, blnc}, interestRate{r} {}

CSavingsAccount::~CSavingsAccount()
{
    cout << "CSavingsAccount:      Konto ("; printIban(); cout << ") vernichtet!" << endl;
}

/////////////////////////////////////////////////////////// load
int CSavingsAccount::load(ifstream &source, vector<CBank *> &bList, vector<CCustomer *> &cList)
{
    string line;

    do
    {
        getline(source, line);

        loadAccountData(line, source, bList, cList);
        loadSavingsAccountData(line);

    } while (line.find("</SavingsAccount>") == string::npos);

    return 0;
}

/////////////////////////////////////////////////////////// loadSavingsAccountData
int CSavingsAccount::loadSavingsAccountData(string &line)
{
    if (line.find("<InterestRate>") != string::npos)
    {
        removeTags(line, "InterestRate");
        interestRate = stod(line);

        return 1;
    }

    return 0;
}

/////////////////////////////////////////////////////////// print
void CSavingsAccount::print() const
{
    CAccount::print();
    cout << "\nSparzinsen: " << interestRate << " %" << flush;
}
