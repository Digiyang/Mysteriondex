#ifndef CBANKMANAGER_H
    #define CBANKMANAGER_H CBANKMANAGER_H

    #include <vector>
    #include <string>
    #include <fstream>
    #include "ccustomer.h"
    #include "cbank.h"
    #include "ctransactionbatch.h"

    using namespace std;



    class CBankManager
    {
        vector<CCustomer *> customerList;
        vector<CBank *> bankList;
        vector<CTransactionBatch *> transactionsList;

        public:
            CBankManager(string filename);
            ~CBankManager();

            void operator+= (CTransactionBatch *batch);

            int load(ifstream &source);
            void printCustomerList() const;
            void printBankList() const;
            void printTransactions() const;
    };

#endif
