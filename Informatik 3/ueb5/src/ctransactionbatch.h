#ifndef CTRANSACTIONBATCH_H
    #define CTRANSACTIONBATCH_H CTRANSACTIONBATCH_H

    #include <vector>
    #include <string>
    #include <fstream>
    #include "ctimestamp.h"
    #include "ctransaction.h"

    using namespace std;



    class CTransactionBatch
    {
        CTimestamp timestamp;
        vector<CTransaction *> transactionList;

        public:
            CTransactionBatch(string filename);
            ~CTransactionBatch();

            int load(ifstream &source);
            void resolveAccounts(vector<CBank *> *banks);
            void print() const;
    };

#endif
