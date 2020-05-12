#ifndef CTRANSACTION_H
    #define CTRANSACTION_H CTRANSACTION_H

    #include <string>
    #include "caccount.h"
    #include "cmoney.h"

    using namespace std;



    class CTransaction
    {
        long id;
        CAccount *account;
        CAccount *contraAccount;
        CMoney amount;
        CMoney transactionFee;
        string reasonForPayment;

        public:
            CTransaction();

            void setAccount(CAccount *a)        {account = a;}
            void setContraAccount(CAccount *a)  {contraAccount = a;}

            CAccount *getAccount()       const {return account;}
            CAccount *getContraAccount() const {return contraAccount;}

            int load(ifstream &source);
            void processTransaction();
            void print() const;
    };

#endif
