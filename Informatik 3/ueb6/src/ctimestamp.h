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



    ostream &printOnlyDate(ostream &os);
    ostream &printDateTime(ostream &os);



    class CTimestamp: public CDate, public CTime
    {
        CWeekday weekday;

        public:
            static bool printTime;

            CTimestamp();

            friend ostream &operator<< (ostream &os, const CTimestamp &ts);
    };

#endif
