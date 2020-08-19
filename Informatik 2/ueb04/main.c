#include <stdlib.h>
#include <stdio.h>
#include "datastructure.h"
#include "tools.h"
#include "cds.h"
#include "menu.h"
#include "database.h"

int main() {


    char * menu[] = {
       "Neue CD anlegen",
       "CD bearbeiten",
       "CD loeschen",
       "Suchen",
       "Sortieren",
       "Auflisten",
       "Programm beenden"
    };

    int choice;
    load();

    do{
        choice = getMenu("CD-Verwaltung Deluxe", menu, 7);

        switch(choice) {

        case 1:
            createCD();
            break;
        case 2:
            editCD();
            break;
        case 3:
            deleteCD();
            break;
        case 4:
            searchSong();
            break;
        case 5:
            sortCDs();
            break;
        case 6:
            listCDs();
            break;
        case 7:
			    if(askYesOrNo("\nMoechten Sie die Daten speichern (j/n) ?"));
                {
                    save();
                    printf("Daten werden gespeichert ... ok");

                }
				printf("\nProgramm beendet\n\n");
				return EXIT_SUCCESS;
		}
        waitForEnter();

    }while(choice != 7);
}
