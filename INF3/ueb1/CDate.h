#ifndef CDATE_H_INCLUDED
   #define CDATE_H_INCLUDED

   class CDate 
   {
      public:
         CDate();
         CDate(int dd, int mm, int yyyy);
         void print();

      private:
         int day;
         int month;
         int year;
   };

#endif
