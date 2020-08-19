#ifndef CADDRESS_H
    #define CADDRESS_H CADDRESS_H

    #include <string>
    #include <fstream>

    using namespace std;



    class CAddress
    {
        string street;
        string postcode;
        string town;

        public:
            CAddress(string s, string p, string t);

            int load(ifstream &source);
            void print() const;
    };

#endif
