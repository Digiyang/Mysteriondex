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

            int load(ifstream &source);
            void print() const;
    };

#endif
