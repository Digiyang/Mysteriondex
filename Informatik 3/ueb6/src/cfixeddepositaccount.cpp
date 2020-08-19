#include <iostream>
#include "cfixeddepositaccount.h"



/////////////////////////////////////////////////////////// Kon- und Destruktoren
CFixedDepositAccount::CFixedDepositAccount()
: CAccount{}, CCurrentAccount{}, CSavingsAccount{} {}

CFixedDepositAccount::~CFixedDepositAccount()
{
    cout << "CFixedDepositAccount: Konto ("; printIban(); cout << ") vernichtet!" << endl;
}

/////////////////////////////////////////////////////////// load
int CFixedDepositAccount::load(ifstream &source, vector<CBank *> &bList, vector<CCustomer *> &cList)
{
    string line;

    do
    {
        getline(source, line);

        loadAccountData(line, source, bList, cList);
        loadCurrentAccountData(line, source);
        loadSavingsAccountData(line);

    } while (line.find("</FixedDepositAccount>") == string::npos);

    return 0;
}

/////////////////////////////////////////////////////////// print
ostream &CFixedDepositAccount::print(ostream &os) const
{
    CAccount::print(os) << "\nDispo     : "; disposit->print();
    os << "\nSparzinsen: " << interestRate << " %";

    return os << flush;
}
