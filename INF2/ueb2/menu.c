#include <stdio.h>
#include <unistd.h>
#include "tools.h"
#include "menu.h"
int getMenu(char * menuTitle, char * menuPoints[], int numberOfPoints) {

    int choice = 0;
    int scanErg;

    while(! choice) {

        clearScreen();                                              
        printf("%s\n",menuTitle);
        printLine('=', 20);
        printf("\n");

        for(int c = 0; c < numberOfPoints; c++) {                   
                if((printf("%d. %s\n",c+1 ,menuPoints[c])) == 0) break;
        }

        printf("\nIhre Wahl: ");                                  
        scanErg = scanf("%d", &choice);
        clearBuffer();

        
        if(choice > numberOfPoints || choice <= 0) {
            printf("ungueltige Eingabe!\n");
            sleep(1);
            choice = 0;
            continue;
        }
    }
    return choice;
}
