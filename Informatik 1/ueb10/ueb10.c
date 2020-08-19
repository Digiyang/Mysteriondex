#include <stdio.h>
#include "Funktionen.h"
#include "escapesequenzen.h"
#include "tools.h"


int main()
{
    int const input = 151,maxinput = 256;
    char Text[input];
    int Index[maxinput];
    int ja_nein; 
    
    do
    {
        CLEAR;
        HOME;
        resetArray(Index, maxinput);
        printTitle();
        getText(Text, input);
        countChar(Text, Index);
        setUpper2Lower(Index, maxinput);
        printTable(Index, maxinput);
       ja_nein = askAgain();
    } while (ja_nein != 0);
    CLEAR;
    HOME;
    printf("Programm wurde beendet!\n\n");
    return 0;
}
