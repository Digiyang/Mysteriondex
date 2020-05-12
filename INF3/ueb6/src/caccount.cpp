#include <iostream>
#include "caccount.h"
#include "ccustomer.h"
#include "cbank.h"
#include "tools.h"



/////////////////////////////////////////////////////////// Kon- und Destruktoren
CAccount::CAccount()
: bank{NULL}, iban{""}, customer{NULL}, balance{} {}

CAccount::CAccount(string i)
: bank{NULL}, iban{i}, customer{NULL}, balance{} {}

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

/////////////////////////////////////////////////////////// Operatoren
ostream &operator<< (ostream &os, const CAccount &a)
{
    return a.print(os);
}

/////////////////////////////////////////////////////////// setter
void CAccount::setBank(CBank *b)
{
    bank = b;     
    bank->addAccount(this);
}

void CAccount::setCustomer(CCustomer *c)
{
    customer = c;
    customer->addAccount(this);
}

/////////////////////////////////////////////////////////// payIntoAccount
void CAccount::payIntoAccount(CMoney amount)
{
    balance += amount;
}

/////////////////////////////////////////////////////////// disburseFromAccount
void CAccount::disburseFromAccount(CMoney amount)
{
    balance -= amount;
}

/////////////////////////////////////////////////////////// load
int CAccount::load(ifstream &source, vector<CBank *> &bList, vector<CCustomer *> &cList)
{
    string line;

    do
    {
        getline(source, line);
        loadAccountData(line, source, bList, cList);

    } while (line.find("</Account>") == string::npos);

    return 0;
}

/////////////////////////////////////////////////////////// loadAccountData
int CAccount::loadAccountData(string &line, ifstream &source, vector<CBank *> &bList, vector<CCustomer *> &cList)
{
    if (line.find("<Bank>") != string::npos)
    {
        removeTags(line, "Bank");

        for (auto elem: bList)
            if (elem->getBIC() == line)
                setBank(elem);

        return 1;
    }
    else if (line.find("<IBAN>") != string::npos)
    {
        removeTags(line, "IBAN");
        iban = line;

        return 1;
    }
    else if (line.find("<Customer>") != string::npos)
    {
        removeTags(line, "Customer");

        for (auto elem: cList)
            if (elem->getID() == stol(line))
                setCustomer(elem);

        return 1;
    }
    else if (line.find("<Balance>") != string::npos)
    {
        balance.load(source);

        return 1;
    }

    return 0;
}

/////////////////////////////////////////////////////////// print
ostream &CAccount::print(ostream &os) const
{
    os << "Kunde     : "; customer->printName();
    os << "\nIBAN / BIC: "; printIban(); os << " / " << bank->getBIC()
       << "\nKontontand: "; balance.print();

    return os << flush;
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
