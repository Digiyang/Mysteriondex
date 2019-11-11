#include <stdio.h>

int main()
{
	double R1 = 0.0, // Widerstandswert
               R2 = 0.0,
               R3 = 0.0;   
	double GWP,
               GWR,
               UW;

	// Die Widerstände R1,R2 und R3 eingeben 
	
	printf("geben sie bitte R1,R2 und R3 ein:");
	scanf("%lf %lf %lf", &R1, &R2, &R3); 
	printf("\nWiderstand R1= %lf ohm\nWiderstand R2= %lf ohm\nWiderstand R3= %lf ohm\n\n", R1, R2, R3);

	// Gesamtwiderstand bei Reihenschaltung
	
	GWR = R1 + R2 + R3;
       	
	printf("Gesamtwiderstand bei Reihenschaltung=       %f ohm\n",GWR);
	// Gesamtwiderstand bei Parallelschaltung 

	GWP = 1 / ( (1/R1) +  (1/R2) + (1/R3) );

	printf("Gesamtwiderstand bei Parallelschaltung=     %f ohm\n",GWP);

	// Wheatstonesche Messbrücke
	
	UW = R3*R1 / R2;

	printf("Wheatstonesche Messbrücke=                  %f ohm\n",UW);


	return 0; 

}
