#include <stdio.h>
#include <unistd.h>
#include "tools.h"
#include "menu.h"

int getMenu(char * menuTitle, char * menuPoints[], int numberOfPoints) {

    int choice = 0;
    

    while(! choice) {

        clearScreen();                                              
        printf("%s\n",menuTitle);
        printLine('=', 20);
        printf("\n");

        for(int c = 0; c < numberOfPoints; c++) {                   
                if((printf("%d. %s\n",c+1 ,menuPoints[c])) == 0) break;
        }

        printf("\nIhre Wahl: ");                                  
        scanf("%d", &choice);
        clearBuffer();
    }
    return choice;
}
