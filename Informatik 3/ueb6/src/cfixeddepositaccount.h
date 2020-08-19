#ifndef CFIXEDDEPOSITACCOUNT_H
    #define CFIXEDDEPOSITACCOUNT_H CFIXEDDEPOSITACCOUNT_H

    #include "ccurrentaccount.h"
    #include "csavingsaccount.h"



    class CFixedDepositAccount: public CCurrentAccount, public CSavingsAccount
    {
        public:
            CFixedDepositAccount();
            ~CFixedDepositAccount();

            int load(ifstream &source, vector<CBank *> &bList, vector<CCustomer *> &cList);
            ostream &print(ostream &os) const;
    };

#endif
