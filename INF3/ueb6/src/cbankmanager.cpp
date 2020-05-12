#include <iostream>
#include "cbankmanager.h"
#include "caccount.h"
#include "ccurrentaccount.h"
#include "csavingsaccount.h"
#include "cfixeddepositaccount.h"



/////////////////////////////////////////////////////////// Kon- und Destruktoren
CBankManager::CBankManager(string filename)
{
    ifstream source;
    string path = "database/";

    source.open(path+filename);
    if (!source)
    {
        cerr << "Die Datei '" << filename << "' konnte nicht geoeffnet werden ..." << endl;
        return;
    }

    cout << "Die Datei '" << filename << "' wurde erfolgreich geoeffnet und wird eingelesen ..." << endl;
    if (load(source))
        cerr << "Fehler beim Einlesen der Daten ..." << endl;
    else
        cout << "Die Datei wurde eingelesen" << endl;

    source.close();
}

CBankManager::~CBankManager()
{
    for (auto elem: customerList)
        delete elem;

    for (auto elem: bankList)
        delete elem;

    for (auto elem: transactionsList)
        delete elem;
}

/////////////////////////////////////////////////////////// Operatoren
void CBankManager::operator+= (CTransactionBatch *batch)
{
    transactionsList.push_back(batch);
    batch->bookTransactions(&bankList);
}

/////////////////////////////////////////////////////////// load
int CBankManager::load(ifstream &source)
{
    string line;
    CAccount *newAccount = NULL;

    do
    {
        getline(source, line);

        if (source.eof())
            return -1;

    } while (line.find("<Data>") == string::npos);

    do
    {
        getline(source, line);

        if (line.find("<Customer>") != string::npos)
        {
            customerList.push_back(new CCustomer);
            customerList.back()->load(source);
        }
        else if (line.find("<Bank>") != string::npos)
        {
            bankList.push_back(new CBank);
            bankList.back()->load(source);
        }
        else if (line.find("<Account>") != string::npos)
        {
            newAccount = new CAccount;
            newAccount->load(source, bankList, customerList);
        }
        else if (line.find("<CurrentAccount>") != string::npos)
        {
            newAccount = new CCurrentAccount;
            newAccount->load(source, bankList, customerList);
        }
        else if (line.find("<SavingsAccount>") != string::npos)
        {
            newAccount = new CSavingsAccount;
            newAccount->load(source, bankList, customerList);
        }
        else if (line.find("<FixedDepositAccount>") != string::npos)
        {
            newAccount = new CFixedDepositAccount;
            newAccount->load(source, bankList, customerList);
        }
    } while (line.find("</Data>") == string::npos);

    return 0;
}


/////////////////////////////////////////////////////////// prints
void CBankManager::printCustomerList() const
{
    if (customerList.size() == 0)
    {
        cout << "Keine Kunden vorhanden..." << endl;
        return;
    }

    for (auto elem: customerList)
    {
        elem->print();
        cout << '\n' << endl;
    }
}

void CBankManager::printBankList() const
{
    if (bankList.size() == 0)
    {
        cout << "Keine Banken vorhanden..." << endl;
        return;
    }

    for (auto elem: bankList)
    {
        elem->print();
        cout << '\n' << endl;
    }
}

void CBankManager::printTransactions() const
{
    if (transactionsList.size() == 0)
    {
        cout << "Keine Transaktionen vorhanden..." << endl;
        return;
    }

    for (auto elem: transactionsList)
        elem->print();
}
