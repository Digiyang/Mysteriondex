#include <iostream>
#include "ctransactionbatch.h"
#include "cbank.h"



/////////////////////////////////////////////////////////// Kon- und Destruktoren
CTransactionBatch::CTransactionBatch(string filename)
: timestamp{}
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

CTransactionBatch::~CTransactionBatch()
{
    for (auto elem: transactionList)
        delete elem;
}

/////////////////////////////////////////////////////////// load
int CTransactionBatch::load(ifstream &source)
{
    string line;

    do
    {
        getline(source, line);

        if (source.eof())
            return -1;

    } while (line.find("<TransactionBatch>") == string::npos);

    do
    {
        getline(source, line);

        if (line.find("<Transaction>") != string::npos)
        {
            transactionList.push_back(new CTransaction);
            transactionList.back()->load(source);
        }

    } while (line.find("</TransactionBatch>") == string::npos);

    return 0;
}

/////////////////////////////////////////////////////////// resolveAccounts
void CTransactionBatch::resolveAccounts(vector<CBank *> *banks)
{
    string tempIBAN;
    string tempContraIBAN;
    CAccount *account;
    CAccount *contraAccount;

    for (auto elem: transactionList)
    {
        tempIBAN = elem->getAccount()->getIBAN();
        delete elem->getAccount();
        elem->setAccount(NULL);

        tempContraIBAN = elem->getContraAccount()->getIBAN();
        delete elem->getContraAccount();
        elem->setContraAccount(NULL);

        for (auto bank: *banks)
        {
            if ((account = bank->findAccount(tempIBAN)) != NULL)
                elem->setAccount(account);

            if ((contraAccount = bank->findAccount(tempContraIBAN)) != NULL)
                elem->setContraAccount(contraAccount);
        }
    }
}

/////////////////////////////////////////////////////////// print
void CTransactionBatch::print() const
{
    cout << "Transaktionen (";
    timestamp.print();
    cout << "):";

    if (transactionList.size() == 0)
    {
        cout << "\nKeine Transaktionen verbucht..." << flush;
        return;
    }

    for (auto elem: transactionList)
    {
        cout << '\n' << endl;
        elem->print();
        elem->processTransaction();
    }
    cout << flush;
}
