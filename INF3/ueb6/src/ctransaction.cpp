#include <iostream>
#include "ctransaction.h"
#include "tools.h"



/////////////////////////////////////////////////////////// Konstruktoren
CTransaction::CTransaction()
: id{0}, account{NULL}, contraAccount{NULL}, amount{}, transactionFee{}, reasonForPayment{""} {}

/////////////////////////////////////////////////////////// load
int CTransaction::load(ifstream &source)
{
    string line;

    do
    {
        getline(source, line);

        if (line.find("<IBAN-Account>") != string::npos)
        {
            removeTags(line, "IBAN-Account");
            account = new CAccount(line);
        }
        else if (line.find("<IBAN-ContraAccount>") != string::npos)
        {
            removeTags(line, "IBAN-ContraAccount");
            contraAccount = new CAccount(line);
        }
        else if (line.find("<ID>") != string::npos)
        {
            removeTags(line, "ID");
            id = stol(line);
        }
        else if (line.find("<Amount>") != string::npos)
        {
            removeTags(line, "Amount");
            amount.setAmount(stod(line));
        }
        else if (line.find("<ReasonForPayment>") != string::npos)
        {
            removeTags(line, "ReasonForPayment");
            reasonForPayment = line;
        }

    } while (line.find("</Transaction>") == string::npos);

    return 0;
}

/////////////////////////////////////////////////////////// processTransaction
void CTransaction::processTransaction()
{
    account->disburseFromAccount(amount);
    contraAccount->payIntoAccount(amount);
}

/////////////////////////////////////////////////////////// print
void CTransaction::print() const
{
    cout << "Buchung ueber "; amount.print();
    cout << "\n--- von ---\n";
    if (account)
        cout << *account;
    cout << "\n--- an ---\n";
    if (contraAccount)
        cout << *contraAccount;
    cout << "\n--- Verwendungszweck: " << reasonForPayment << " ---" << flush;
}
