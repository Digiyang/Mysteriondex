#ifndef CDATE_H
    #define CDATE_H CDATE_H

    #include <fstream>

    using namespace std;



    class CDate
    {
        int day;
        int month;
        int year;

        public:
            CDate(); 
            CDate(int d, int m, int y);

            int load(ifstream &source);
            void print() const;
    };

#endif
