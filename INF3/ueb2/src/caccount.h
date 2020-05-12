#ifndef CACCOUNT_H
    #define CACCOUNT_H CACCOUNT_H

    #include <string>
    #include "cmoney.h"

    class CCustomer;        // forward-declare

    using namespace std;



    class CAccount
    {
        string iban;
        CCustomer *customer;
        CMoney balance;

        public:
            CAccount(string i, CCustomer *c, CMoney b);

            void print() const;
            void printIban() const;
    };

#endif
