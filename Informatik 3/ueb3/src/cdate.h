#ifndef CDATE_H
    #define CDATE_H CDATE_H

    class CDate
    {
        int day;
        int month;
        int year;

        public:
            CDate(); 
            CDate(int d, int m, int y);

            void print() const;
    };

#endif
