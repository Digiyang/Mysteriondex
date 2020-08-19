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

            int load(ifstream &source);
            void print() const;
    };

#endif
