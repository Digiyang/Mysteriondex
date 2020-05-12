#ifndef CCUSTOMER_H
    #define CCUSTOMER_H CCUSTOMER_H

    #include <string>
    #include <vector>
    #include "cdate.h"
    #include "caddress.h"
    #include "caccount.h"

    using namespace std;



    class CCustomer
    {
        long id;
        string name;
        CDate birthday;
        CAddress address;
        vector<CAccount *> accountList;

        public:
            CCustomer(long i, string n, CDate b, CAddress a);

            void addAccount(CAccount *newAccount);
            void print() const;
            void printName() const;
    };

#endif
