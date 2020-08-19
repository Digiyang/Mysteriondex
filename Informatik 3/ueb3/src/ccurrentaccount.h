#ifndef CCURRENTACCOUNT_H
    #define CCURRENTACCOUNT_H CCURRENTACCOUNT_H

    #include "caccount.h"
    #include "cmoney.h"



    class CCurrentAccount: public CAccount
    {
        CMoney *disposit;

        public:
            CCurrentAccount(CBank *bnk, string i, CCustomer *c, CMoney blnc, CMoney *d);
            ~CCurrentAccount();

            void print() const;
    };

#endif
