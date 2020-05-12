#ifndef CCURRENTACCOUNT_H
    #define CCURRENTACCOUNT_H CCURRENTACCOUNT_H

    #include "caccount.h"
    #include "cmoney.h"



    class CCurrentAccount: virtual public CAccount
    {
        protected:
            CMoney *disposit;

            int loadCurrentAccountData(string &line, ifstream &source);

        public:
            CCurrentAccount();
            CCurrentAccount(CBank *bnk, string i, CCustomer *c, CMoney blnc, CMoney *d);
            ~CCurrentAccount();

            int load(ifstream &source, vector<CBank *> &bList, vector<CCustomer *> &cList);
            void print() const;
    };

#endif
