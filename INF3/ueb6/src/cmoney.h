#ifndef CMONEY_H
    #define CMONEY_H CMONEY_H

    #include <string>
    #include <fstream>

    using namespace std;



    class CMoney
    {
        double amount;
        string currency;

        public:
            CMoney();
            CMoney(double a, string c = "EUR");

            void operator+= (CMoney a);
            void operator-= (CMoney a);

            void setAmount(double a) {amount = a;}

            int load(ifstream &source);
            void print() const;
    };

#endif
