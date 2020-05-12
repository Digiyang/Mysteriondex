#ifndef CACCOUNT_H
    #define CACCOUNT_H CACCOUNT_H

    #include <string>
    #include <fstream>
    #include <vector>
    #include "cmoney.h"

    class CCustomer;        // forward-declare
    class CBank;

    using namespace std;



    class CAccount
    {
        protected:
            CBank *bank;
            string iban;
            CCustomer *customer;
            CMoney balance;

            int loadAccountData(string &line, ifstream &source, vector<CBank *> &bList, vector<CCustomer *> &cList);

        public:
            CAccount();
            CAccount(string i);
            CAccount(CBank *bnk, string i, CCustomer *c, CMoney blnc);
            virtual ~CAccount();

            friend ostream &operator<< (ostream &os, const CAccount &a);

            void setBank(CBank *b);
            void setCustomer(CCustomer *c);

            string getIBAN()            const {return iban;}
            CCustomer *getCustomer()    const {return customer;}
            CMoney getBalance()         const {return balance;}

            void payIntoAccount(CMoney);
            void disburseFromAccount(CMoney);
            virtual int load(ifstream &source, vector<CBank *> &bList, vector<CCustomer *> &cList);
            virtual ostream &print(ostream &os) const;
            void printIban() const;
    };

#endif
