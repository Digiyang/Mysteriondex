#include <stdio.h>
#include "tools.h"
#include "escapesequenzen.h"


void printTitle()
{
    
    
    printf("========================\n");
    printf("||                    ||\n");
    printf("||   Zeichenzaehler   ||\n");
    printf("||                    ||\n");
    printf("========================\n\n\n");
}

void getText(char *T, int Size)
{
   
    printf("Geben Sie bitte den Text ein (mind. 1 Zeichen / max. 150 Zeichen),\n"
           "dessen Zeichen gezaehlt werden sollen:  ");

    int Input;
    char *Count = T;

    do
    {
       

        do
        {
            Input = scanf("%c", T);
            if (*T == '\n') break;
            T++;
        } while ((Input) && (T - Count < Size - 1));

       
        if ((*T == '\n') && (T - Count == 0))
        {
            
           printf("Sie haben keinen Text eingegeben!");
        }
    } while ((*T == '\n') && (T - Count == 0));
    *T = '\0';
    
}


void resetArray(int *A, int Anz)
{
    int i;

    for (i = 0; i < Anz; i++)
    {
        *(A + i) = 0;
    }
}

void countChar(char *T, int *A)
{
    int i = 0;

    while (*(T + i) != '\0')
    {
        if (*(T + i) < 0) 
            *(A + 256 + *(T + i)) += 1;
        else
            *(A + *(T + i)) += 1;
        i++;
    }
}


void setUpper2Lower(int *A, int Size)
{
    int i;
    for (i = 0; i < Size; i++)
    {
        if ((('A' <= i) && (i <= 'Z')) )
        {
            if (*(A + i) > 0)
            {
                *(A + i + 32) += *(A + i);
                *(A + i) = 0;
            }
        }
    }
}

void printTable(int *A, int Size)
{
   
    int i, j = 0;
    printf("\n\n\n"); 
    printf("Anzahl der Zeichen:\n");
    printf("-----------------------------------------------------------------\n");
    for (i = 0; i < Size; i++)
    {    
        if (*(A + i) > 0) 
        {
            
            if (i < 32)
                printf("|   (%#04x): %3i ", i, *(A + i));
            else
                printf("| %c (%#04x): %3i ", i, i, *(A + i));
            j++;
            if (j % 4 == 0) printf("|\n");
        }
    }
    if (j % 4 != 0)
    {
        for ( ; j % 4 != 0; j++)
            printf("|               \n");
        
    }
  
    printf("-----------------------------------------------------------------\n");
}
