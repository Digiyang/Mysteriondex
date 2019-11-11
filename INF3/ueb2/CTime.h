#ifndef CTIME_H_INCLUDED
   #define CTIME_H_INCLUDED

   class CTime 
   {
      public:
         CTime();
         CTime(int h, int m, ...);
         void print();

      private:
         int hour;
         int minute;
         int seconde;
   };

#endif
