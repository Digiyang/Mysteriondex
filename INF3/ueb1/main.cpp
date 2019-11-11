#include <stdio.h>
#include "CDate.h"
int main()
{
   CDate D1, D2(4, 10, 2019);
   printf("\nKlasse CDate:\n");
   printf("Standardkonstruktor Heutiges Datum (D1):    ");
   D1.print();
   printf("\n");
   printf("Konstruktor         Erster SU-Tag (D2):     ");
   D2.print();
   printf("\n");
   return 0;
}
