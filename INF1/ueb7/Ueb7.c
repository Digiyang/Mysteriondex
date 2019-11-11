#include<stdio.h>

int main ()
{
   double Op1;
   double Op2;
   double Erg;
   int GE;
   int Wahl;
   char Dummy;
   
   do
   {
        printf("Einfacher Taschenrechner      ");       
        printf("\n========================\n\n");
        printf("1. Addition\n2. Subtraktion\n"
               "3. Multiplikation\n4. Division\n\n"
               "9. Programmende         \n\n\n");
                                                   
        printf("Ihre Wahl: ");
       
        GE = scanf("%i", &Wahl );
        
        do
        {
           scanf("%c" , &Dummy);
        }   while ( Dummy != '\n');
        if( GE != 0 )
        {
           switch ( Wahl )
           {
              case 1: printf ("\n\nAddition\n===========\n");
                      break;
              case 2: printf ("\n\nSubstraktion\n==============\n");
                      break;
              case 3: printf ("\n\nMultiplikation\n===============\n");
                      break;
              case 4: printf ("\n\ndivision\n================\n\n\n");
                      break;
              default: GE = 0;
           }
            if ( GE != 0)
            {
               do
               {
                  printf("Geben Sie bitte den ersten Operanden ein: ");

                  GE = scanf( "%lf", &Op1);
                  do
                  {
                    scanf("%c" , &Dummy);
                  }   while ( Dummy != '\n');
                  if ( GE == 0)
                  {
                     printf("Falsche Eingabe /!\\");
                  }
               } while ( GE == 0 );

               do
               {
                  printf("Geben Sie bitte den zweiten Operanden ein: ");

                  GE = scanf( "%lf", &Op2);
                  do
                  {
                    scanf("%c" , &Dummy);
                  }   while ( Dummy != '\n');
                  if ( GE == 0 )
                  {
                     printf("Falsche Eingabe /!\\");
                  }
                  else 
                  { 
                    if ( Wahl == 4 && Op2 == 0 )
                    
                    {
                        printf(" Division durch 0 /!\\\n");
                        GE = 0;
                     
                     }
                  }
               } while ( GE == 0);

            }
            switch ( Wahl )
            { 
               case 1:  Erg = Op1 + Op2;
                        printf(" %.3f + %.3f = %.3f\n", Op1, Op2, Erg );
                        break;
               case 2:  Erg = Op1 - Op2;
                        printf(" %.3f - %.3f = %.3f\n", Op1, Op2, Erg );
                        break;
               case 3:  Erg = Op1 * Op2;
                        printf(" %.3f * %.3f = %.3f\n", Op1, Op2, Erg );
                        break;
               case 4:  Erg = Op1 / Op2;
                        printf(" %.3f / %.3f = %.3f\n", Op1, Op2, Erg );
                        break;
               case 9:  break;
               default: printf("Falsche Eingabe\n");
            }
            
             
             
            
                      
        }

        else
           printf( "Falsche Eingabe");
	printf("Bitte drücken Sie die Eingabetaste ...\n\n");
   }  while ( Wahl != 9);
   
   printf( "#############\nProgrammsEnde\n#############\n");
   return 0;
}
