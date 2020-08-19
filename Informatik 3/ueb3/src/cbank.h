#ifndef CBANK_H
    #define CBANK_H CBANK_H

    #include <string>
    #include <vector>
    #include "caccount.h"

    using namespace std;



    class CBank
    {
        string name;
        string BIC;
        vector<CAccount *> accountList;

        public:
            CBank(string n, string b);

            string getBIC() const {return BIC;}

            void addAccount(CAccount *newAccount);
            void print() const;
    };

#endif
