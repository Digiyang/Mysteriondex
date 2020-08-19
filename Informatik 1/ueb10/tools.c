#include <stdio.h>
#include "escapesequenzen.h"
#include "tools.h"

void clearBuffer(void)
{
    char dummy;
    do
    {
        scanf("%c", &dummy);
    } while (dummy != '\n');
}


int askAgain()
{
   char jn;
   int JaNein;
  
   printf("Moechten Sie noch einmal ?\n");
   do
   {
      scanf("%c", &jn);
      if (jn != '\n')
         clearBuffer();
      if (jn != ('j'||'J'||'n'||'N'))
      {
         
         printf("Geben sie bitte (J)a oder (N)ein ein.");
      }
   } while (jn!='j' && jn!='J' && jn!='n' && jn!='N');
   if (jn == 'j' || jn == 'J')
      JaNein = 1;
   else
      JaNein = 0;
   return JaNein;
}



