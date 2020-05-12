#include <iostream>

using namespace std;

#include "ctimestamp.h"
#include "ctransactionbatch.h"
#include "cbankmanager.h"

void printNow()
{
   CTimestamp Now;

   cout << "Aktueller Zeitstempel: ";
   Now.print();
   cout << endl << endl;
}

int main()
{
   printNow();

   CBankManager BankManager("daten.xml");

   cout << endl;
   BankManager.printTransactions(); // sollte "keine Transaktionen vorhanden" ausgeben
   cout << endl;

   BankManager += new CTransactionBatch("transactions.xml");

   cout << endl;
   BankManager.printTransactions(); // gibt alle Stapel mit allen Transaktionen aus
   cout << endl;

   cout << endl;
   BankManager.printBankList(); // Übersicht der Konten mit geänderten Kontoständen
   cout << endl;

   printNow();

   return 0;
}

