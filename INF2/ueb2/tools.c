#include <stdio.h>
#include <stdlib.h>
#include "escapesequenzen.h"
#include "tools.h"



void clearBuffer()
{
	char Dummy;
	do
	{
          scanf("%c" , &Dummy);
	} while (Dummy != '\n');
}

void printLine(char c, int num) {
    for(int i = 0; i<num; i++) {
        printf("%c", c);
    }
    printf("\n");
}



void clearScreen() {

    system("clear");

}

int askYesOrNo(char * Question) {

    char Ans;
    do{
        printf("%s\n",Question);
        scanf("%c",&Ans);
        if (Ans != '\n')
            clearBuffer();
        if ( (Ans == 'J') || (Ans == 'j') )
        {
		return 1;
        }
        else if ( (Ans == 'N') || (Ans == 'n') )
        {
            return 0;
        }
    }while(1);
}

void waitForEnter()
{
   printf("\nBitte Eingabetaste druecken ...");
   clearBuffer();
}


