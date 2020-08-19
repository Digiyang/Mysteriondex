#ifndef CBANK_H
    #define CBANK_H CBANK_H

    #include <string>
    #include <fstream>
    #include "caccount.h"
    #include "clist.h"

    using namespace std;



    class CBank
    {
        string name;
        string BIC;
        CList<CAccount *> accountList;

        public:
            CBank();
            CBank(string n, string b);
            ~CBank();

            string getBIC() const {return BIC;}

            void addAccount(CAccount *newAccount);
            CAccount *findAccount(string iban);
            int load(ifstream &source);
            void print() const;
    };

#endif
