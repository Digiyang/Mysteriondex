#ifndef CTIME_H
    #define CTIME_H CTIME_H 

    class CTime
    {
        int hour;
        int minute;
        int second;

        public:
            CTime(); 
            CTime(int h, int m, int s = 0);

            void print() const;
    };

#endif
