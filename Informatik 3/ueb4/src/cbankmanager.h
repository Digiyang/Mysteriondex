#ifndef CBANKMANAGER_H
    #define CBANKMANAGER_H CBANKMANAGER_H

    #include <vector>
    #include <string>
    #include <fstream>
    #include "ccustomer.h"
    #include "cbank.h"

    using namespace std;



    class CBankManager
    {
        vector<CCustomer *> customerList;
        vector<CBank *> bankList;

        public:
            CBankManager(string filename);
            ~CBankManager();

            int load(ifstream &source);
            void printCustomerList() const;
            void printBankList() const;
    };

#endif
