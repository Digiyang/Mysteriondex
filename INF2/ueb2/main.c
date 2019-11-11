#include <stdlib.h>
#include <stdio.h>
#include "datastructure.h"
#include "tools.h"
#include "cds.h"
#include "menu.h"


int main(int argc, char * argv[]) {


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
                     

    do{
        choice = getMenu("CD-Verwaltung Deluxe", menu, 7);

        switch(choice) {

        case 1:
            printf("Neue CD anlegen\n");
            
            break;
        case 2:
            printf("CD bearbeiten\n");
           
            break;

        case 3:
            printf("CD loeschen\n");
            
            break;
        case 4:
            printf("Suchen\n");
            
            break;
        case 5:
            printf("Sortieren\n");
            
            break;
        case 6:
            printf("Auflisten\n");
            
            
            break;
        case 7:
            printf("Programm wird beendet!\n");
            break;
        }
        waitForEnter();

    }while(choice != 7);


}

