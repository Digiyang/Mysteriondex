#include <stdio.h>
#include "macros.h"

int main()
{

    double f ;
    double a,b,c,d,g,e ;
    a = 2 ;
    b = 4 ;
    f = _2_PI ;
    c = MULT(a+b, a+b);
    d = MULT2(a+b, a+b);
    e = ADD(a, b)*2;
    g = ADD2(a, b)*2;
    printf("\n\n---------------------------------Aufgabe 2.a---------------------------------------\n");

    printf(" Makron.1 (3.14 + 3.14) ist : %.2lf \n",f);

    printf("\n\n---------------------------------Aufgabe 2.b---------------------------------------\n");

    printf("\nwir führen operationen und schauen unsere Werte mit a = 2 , b = 4 \n");

    printf("\nmit Makron (a * b):\n");

    printf("a+b*a+b = %.2lf ,			c=MULT(a * b )		:	%.2lf \n",a+b*a+b,c);
    printf("\nmit Makron ((a) * (b)):\n");
    printf("(a+b)*(a+b): = %.2lf ,			d=MULT2((a) * (b))	:	%.2lf \n",(a+b)*(a+b),d);

    printf("\n\n---------------------------------Aufgabe 2.c---------------------------------------\n");

    printf("\nwir führen operationen und schauen unsere Werte mit a = 2 , b = 4 \n");

    printf("\nmit Makron (a) + (b):\n");

    printf("(a)+(b)*2 =%.2lf,				e=ADD(a) + (b)   : %.2lf \n",(a)+(b)*2,e);
    printf("\nmit Makron ((a) + (b)):\n");
    printf("((a)+(b))*2= %.2lf,				g=ADD2((a)+(b))  : %.2lf \n",((a)+(b))*2,g);




    return 0 ;
}
