#ifndef CTIMESTAMP_H
    #define CTIMESTAMP_H CTIMESTAMP_H

    #include "cdate.h"
    #include "ctime.h"

    typedef enum
    {
        SUNDAY,
        MONDAY,
        TUESDAY,
        WEDNESDAY,
        THURSDAY,
        FRIDAY,
        SATURDAY
    } CWeekday;



    class CTimestamp: public CDate, public CTime 
    {
        CWeekday weekday;

        public:
            CTimestamp();

            void print() const;
    };

#endif
