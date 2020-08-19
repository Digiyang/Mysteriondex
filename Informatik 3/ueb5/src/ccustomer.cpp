#include <iostream>
#include "ccustomer.h"
#include "tools.h"



/////////////////////////////////////////////////////////// Kon- und Destruktoren
CCustomer::CCustomer()
: id{0}, name{""}, birthday{}, address{"", "", ""} {}

CCustomer::CCustomer(long i, string n, CDate b, CAddress a)
: id{i}, name{n}, birthday{b}, address{a} {}

CCustomer::~CCustomer()
{
    cout << "Kunde " << name << " wird vernichtet." << endl;
}

/////////////////////////////////////////////////////////// addAccount
void CCustomer::addAccount(CAccount *newAccount)
{
    accountList.push_back(newAccount);
}

/////////////////////////////////////////////////////////// load
int CCustomer::load(ifstream &source)
{
    string line;

    do
    {
        getline(source, line);

        if (line.find("<ID>") != string::npos)
        {
            removeTags(line, "ID");
            id = stol(line);
        }
        else if (line.find("<Name>") != string::npos)
        {
            removeTags(line, "Name");
            name = line;
        }
        else if (line.find("<Birthday>") != string::npos)
            birthday.load(source);
        else if (line.find("<Address>") != string::npos)
            address.load(source);

    } while (line.find("</Customer>") == string::npos);

    return 0;
}

/////////////////////////////////////////////////////////// print
void CCustomer::print() const
{
    printName(); cout << '\n';
    address.print();
    cout << "\ngeboren am: "; birthday.print();
    cout << "\nKonten:";
    for (auto elem: accountList)
    {
        cout << "\n- Kontonr.: "; elem->printIban();
    }
}

/////////////////////////////////////////////////////////// printName
void CCustomer::printName() const
{
    cout << name << " (Kd-Nr. " << id << ")" << flush;
}
