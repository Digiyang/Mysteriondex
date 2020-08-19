#include <stdio.h>

int main()
{
	double Wert1=9.99, Wert2=19.99, Wert3=24.49;
	double Summe , Mehrwert,Brutto;

	printf("\nDieses Programm berechnet aus 3 Werten\n");
	printf("Die Nettosumme,dazu die Mehrwertsteuer ");
	printf("und schliesslich den Bruttobetrag.\n");
	printf("Die drei Werte: %.2f, %.2f, %.2f\n",Wert1,Wert2,Wert3);

	Summe=Wert1+Wert2+Wert3;
	printf("Nettoosumme: %.2f\n",Summe);
		
	Mehrwert=Summe*0.19;
	printf("Mehrwertsteuer: %.2f\n",Mehrwert);
	
	Brutto=Summe+Mehrwert;
	printf("Bruttobetrag: %.2f\n",Netto);

	return 0;
}
