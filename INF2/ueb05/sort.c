#include <stdio.h>
#include <string.h>
#include "datastructure.h"
#include "tools.h"
#include "sort.h"
#include "cds.h"

void Tausche(TCD * A, TCD * B)
{
	TCD temp;

	memcpy(&temp, A, sizeof(TCD));
	memcpy(A, B, sizeof(TCD));
	memcpy(B, &temp, sizeof(TCD));
}

int partition(TCD * Array, int ui, int oi, int (*Fkt)(TCD *, TCD *))
{
	int i = ui, j = oi, comp = ui;
	while(i <= j) 		// prueft ob die untere graenze kleiner oder gleich der oberen graenze ist
	{
		while((i <= j) && (Fkt( Array+i, Array+comp) <= 0))
			i++;
		while((j >= i) && (Fkt( Array+j, Array+comp) >= 0))
			j--;
		if(i < j) // prueft ob untere gerenze kleiner der oberen graenze
		{
			Tausche(Array + i, Array + j);
			i++;
			j--;
		}
	}
	i--;
	Tausche(Array + i, Array + comp);

	return i; // gibt den zaehler i zurueck
}

void qSort(TCD * Array, int ui, int oi, int (*Fkt)(TCD *, TCD *))
{
	int idx;

	if(ui >= oi)					    // prueft ob untere gerenze groesser oder gleich der oberen gerenze
        return ;					    // beendet die funktion gegebenfalls
	idx = partition(Array, ui ,oi, Fkt);	// laesst zwischen der oberen und der unteren gerenze sortieren
	qSort(Array, ui, idx - 1, Fkt);		// ruft sich selbst auf
	qSort(Array, idx + 1, oi, Fkt);		// ruft sich selbst auf
}

void QSort(TCD * Array, int Anz, int (*Fkt)(TCD *, TCD *))
{
	qSort(Array, 0, Anz - 1, Fkt);
}


int VerglJahr(TCD * A, TCD * B)
{

		return( A->YearOfAppearance - B->YearOfAppearance);

}

int VerglLieder(TCD * A, TCD * B)
{

		return( B->numberOfSongs - A->numberOfSongs);

}

int VerglTitel(TCD * A, TCD * B)
{
	int i = 0;
	char c;

	while( (c = toupper(*(A->Titel + i)) - toupper(*(B->Titel + i)) ) == 0 && (*(A->Titel + i) != '\0') )
		i++;


		return c;

}


int VerglIntr(TCD * a, TCD * b)
{
	int i = 0;
	char c;




	if ( (a->Interpret == NULL) && (b->Interpret == NULL))
        return 0;
    if (a->Interpret == NULL)
        return -1;
    if (b->Interpret == NULL)
        return 1;
while( (c = toupper(*(a->Interpret + i)) - toupper(*(b->Interpret + i)) ) == 0 && (*(b->Interpret + i) != '\0') )
		i++;
    return c;

}
