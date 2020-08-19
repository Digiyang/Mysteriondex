#ifndef CTIME_H
    #define CTIME_H CTIME_H

    #include <fstream>

    using namespace std;



    class CTime
    {
        int hour;
        int minute;
        int second;

        public:
            CTime(); 
            CTime(int h, int m, int s = 0);

            friend ostream &operator<< (ostream &os, const CTime &t);

            int load(ifstream &source);
    };

#endif
