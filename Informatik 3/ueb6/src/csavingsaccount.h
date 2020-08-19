#ifndef CSAVINGSACCOUNT_H
    #define CSAVINGSACCOUNT_H CSAVINGSACCOUNT_H

    #include "caccount.h"



    class CSavingsAccount: virtual public CAccount
    {
        protected:
            float interestRate;

            int loadSavingsAccountData(string &line);

        public:
            CSavingsAccount();
            CSavingsAccount(CBank *bnk, string i, CCustomer *c, CMoney blnc, float r);
            ~CSavingsAccount();

            int load(ifstream &source, vector<CBank *> &bList, vector<CCustomer *> &cList);
            ostream &print(ostream &os) const;
    };

#endif
