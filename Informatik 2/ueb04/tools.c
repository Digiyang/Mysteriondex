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

int getText(char * prompt, int allowedChars, int emptyAllowed, char ** target) {

    printf("%s", prompt);

    char * input = calloc(allowedChars, sizeof(prompt));
    int scanErg;
    
    scanErg = (scanf("%39[^\n]", input));

    if(scanErg > 0) {

        clearBuffer();
        int strLen = strlen(input);
        *target = calloc(strLen+1, sizeof(char));

        strcpy(*target, input);

        free(input);
        return 1;

    }else if(emptyAllowed) {

        clearBuffer();
        *target = NULL;
        free(input);
        return 1;

    }else{

        clearBuffer();
        free(input);
        return 0;

    }
}
void getNumber(char *Prompt, int *Number, int From, int To)
{
   int zahl;
   do
   {
      printf("%s", Prompt);
      zahl = 0;
      scanf("%d", &zahl);
      clearBuffer();
   } while (zahl < From || To < zahl);
   *Number = zahl;
}
void fclearBuffer(FILE * Datei)
{
   char Dummy;
   do
   {
      fscanf(Datei, "%c", &Dummy);
   } while (Dummy != '\n');
}

char * lineStart(char *Line)
{
   char * LineStart = Line;

   while ( (* LineStart == ' ') || (* LineStart == 9))
      LineStart ++;
   return LineStart;
}
