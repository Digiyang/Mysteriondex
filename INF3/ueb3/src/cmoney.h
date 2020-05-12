#ifndef CMONEY_H
    #define CMONEY_H CMONEY_H

    #include <string>

    using namespace std;



    class CMoney
    {
        double amount;
        string currency;

        public:
            CMoney();
            CMoney(double a, string c = "EUR");

            void print() const;
    };

#endif
