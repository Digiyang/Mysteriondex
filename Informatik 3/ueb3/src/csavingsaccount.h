#ifndef CSAVINGSACCOUNT_H
    #define CSAVINGSACCOUNT_H CSAVINGSACCOUNT_H

    #include "caccount.h"



    class CSavingsAccount: public CAccount
    {   protected:
        float interestRate;

        public:
            CSavingsAccount(CBank *bnk, string i, CCustomer *c, CMoney blnc, float r);
            ~CSavingsAccount();

            void print() const;
    };

#endif
