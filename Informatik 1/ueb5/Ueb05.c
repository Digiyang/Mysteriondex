#include<stdio.h>

int main ()
{
   char c;
   int Zahl;
   int Anz;
   char Dummy;
   do
   
   {
     
      printf("Bitte ein dezimal Zahl eingeben: ");
     
      Anz = scanf("%d", &Zahl);
      
      do
      {
         scanf("%c" , &Dummy);

      }  while (Dummy != '\n');

      if ( Anz != 0)
      {
         
         printf ("Sie haben eine ganze Zahl: "
                 "%d eingegeben\n", Zahl);
      }
      else
      {
         printf("Falsche eingabe! xxxx ");
      }

      printf("wenn Sie wiederholen Wollen\n"
             "drücken Sie j/J!\n"
             "wenn nicht Drücken Sie n/N \n");
    
        
      scanf("%c" , &c);
    
      if (c != '\n')
      {
         do
         {
            scanf("%c" , &Dummy);
         } while (Dummy != '\n');
      }
    
      if( c != 'j' && c != 'n' && c != 'J' && c != 'N')
      {
         do
         {
            printf("Falsche eingabe!"
                   "Bitte geben noch mal entweder\n"
                   " j für wiederholen \n"
                   "oder n um Program zu enden!\n");
            scanf("%c" , &c);
            do
            {
               scanf("%c" , &Dummy);
            } while ( Dummy != '\n');
          } while ( c != 'j' && c != 'n' && c != 'J' && c != 'N' );
      }
  } while ( c == 'j' || c == 'J');
 printf("\n###################\n");
 printf("## Programmsende ##\n");
 printf("###################\n");
     
  
  
  return 0;
}
