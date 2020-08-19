#include <stdio.h>
#include "macros.h"

int main()
{

	int a = 2;
	int b = 4;
	int x = 7;//110 bin = 6 dez //http://gcc.gnu.org/onlinedocs/gcc/Binary-constants.html -> wie schreibt man binär in C ?
	printf("%d",x);
	 LSB(x);


	printf("\nder Wert in LSB()=%d  \n\n\n",x);
	
	printf("die Werte sind : a=%d , b=%d \n",a,b);
	SWP(a,b);
        printf("nach vertaschen : a=%d , b=%d \n",a,b);



return 0;



}
