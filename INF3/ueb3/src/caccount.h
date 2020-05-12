#ifndef CACCOUNT_H
    #define CACCOUNT_H CACCOUNT_H

    #include <string>
    #include "cmoney.h"

    class CCustomer;        // forward-declare
    class CBank;

    using namespace std;



    class CAccount
    {
        CBank *bank;
        string iban;
        CCustomer *customer;
        CMoney balance;

        public:
            CAccount(CBank *bnk, string i, CCustomer *c, CMoney blnc);
            ~CAccount();

            CCustomer *getCustomer()    const {return customer;}
            CMoney getBalance()         const {return balance;}

            void print() const;
            void printIban() const;
    };

#endif
