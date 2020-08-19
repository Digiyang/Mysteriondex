#include<stdio.h>
#include"escapesequenzen.h"
#include<string.h>

void drawLine();
void drawSpace(int);
short getNumber(int);
void printFrame();

char getOperator();
short calcResult(short , short ,char );
void PrintNumber(int , short);
void printBinary( int , short );
void printResultOperator( char );
int askAgain();
void clearBuffer();

int main ()
{
   short a;
   short b;
   short Ergebnis;
   char c;
   int wiederholung;

   do
   {
      CLEAR;
      HOME;
      printFrame();
      a = getNumber(5);
      c = getOperator();
      b = getNumber(7);
      POSITION(24,0);
      
      PrintNumber( 12 , a);
      printBinary( 12 , a);
      printResultOperator(c);
      PrintNumber(14 , b);
      printBinary( 14 , b);
      Ergebnis = calcResult( a, b, c);
      PrintNumber( 17 , Ergebnis);
      printBinary( 17 , Ergebnis);
      
      wiederholung = askAgain();
      

      
   } while (wiederholung);
   CLEAR;
   HOME;
   printf("Programm wurde beendet!\n\n");
return 0;
}

void drawLine()
{  
    printf("|");
    for(int i=0; i<60; i++)
    {                   
       printf("-");
    }
    printf("|\n");
}

void drawSpace(int size )
{
    if (size == 0)
    {
       printf("|");
       size++;
    }
    for(int i=size ; i<61 ; i++ ) 
    {
       printf(" ");
    }
        printf("|\n");
}

void printFrame()
{
    CLEAR;
    HOME;
    char* c;
    drawLine();
    c="| Bitoperatoren-Rechner";
    printf("%s",c);
    drawSpace(strlen(c) );
    drawSpace(0);
    drawSpace(0);
    c= "| Eingabe Zahl 1: ";
    printf("%s", c);
    drawSpace(strlen(c));
    c="| Operator : ";
    printf("%s",c);
    drawSpace(strlen(c));
    c= "| Eingabe Zahl 2: ";
    printf("%s", c);
    drawSpace(strlen(c));
    drawSpace(0);
    drawLine();
    drawSpace(0);
    c="|          \tDezi \t Okta  \t hexadi  \t  binär";
    printf("%s",c);
    drawSpace(strlen(c)+11);
    c = "| Zahl 1   |\t    |  \t     |  \t|";
    printf("%s",c);
    drawSpace(strlen(c)+10);
    c = "| Operator |\t    |  \t     |  \t|";
    printf("%s",c);
    drawSpace(strlen(c)+10);  
    c = "| Zahl 2   |\t    |  \t     |  \t|";
    printf("%s",c);
    drawSpace(strlen(c)+10);
    drawLine();
    drawSpace(0);
    c = "| Ergebnis |\t    |  \t     |  \t|";
    printf("%s",c);
    drawSpace(strlen(c)+10);
    drawSpace(0);
    drawLine(0 );
}

short getNumber ( int Zeile  ) //gibt eingegebene
                                            //n Operanden in 						                           //derangegebener Zeile aus
{  
   short Zahl;
   int GE;
   do
   {
      
      POSITION(Zeile,21);
      GE = scanf("%hi", &Zahl);
	clearBuffer();

      if ( GE == 0)
         {
            POSITION(20,21);
            printf("Falsche eingabe ! bitte nochmal....");
		POSITION(Zeile , 21);
	for(int i=21 ; i<41 ; i++ ) 
    	{
     	  printf(" ");
    	}
       	 
        }
	
   } while (GE == 0);
   
   return Zahl;
}
char getOperator() //liest das erste Zeichen des Operators ein
{
   char c;
  
   do
   {
      POSITION(6,21);
      scanf("%c", &c);
   	clearBuffer();
      if( c != '<' && c != '>' && c != '^' && c != '|' && c != '&' && c != '%')
         {

            POSITION(20,17);
            
            printf("Falsche eingabe ! bitte nochmal...");
		POSITION(6,21);
	for(int i=21 ; i<41 ; i++ ) 
    	{
     	  printf(" ");
    	}
         }
       
       else
           break;
   }  while (1);
   if(c == '<' || c == '>')
	{
	POSITION(6,21);
	for(int i=21 ; i<41 ; i++ ) 
    	{
     	  printf(" ");
    	}
		POSITION(6,21);
		printf("%c%c", c,c);
	}
   return c;
}
short calcResult(short a, short b, char c)// berechnet Ergebnis
{
   short Ergebniss;
   switch (c)
   {
      case '|': Ergebniss = a |  b;    break;
      case '&': Ergebniss = a &  b;    break;
      case '^': Ergebniss = a ^  b;    break;
      case '<': Ergebniss = a << b;    break;
      case '>': Ergebniss = a >> b;    break;
      case '%': Ergebniss = a %  b;    break;
   }
   return Ergebniss;
}
void PrintNumber(int zeile, short Zahl) //gibt die Ergebnisse (dez		                                             //,oktal und hex.) aus
{
   POSITION(zeile,15);
   printf("%6.0hd", Zahl);
   RIGHT(3);
   printf("%#6.0ho", Zahl);
   RIGHT(5);
   printf("%#6.0hx", Zahl);
}

void printBinary(int Zeile, short zahl) //gibt Zahl als Binärzahl aus
{

    int i;
	POSITION(Zeile, 44);

	for(i = 15 ; i >= 0 ; i--)
	{	
		if((zahl &(1<<i)) !=0)
		printf("1");
		else
		printf("0");
	}
   
   
		

}

void printResultOperator(char c) //gibt Operator im Ergebnisbereich aus
{

	if(c == '<' || c == '>')
	{
		
		POSITION( 13 ,19 );
		printf("%c%c", c,c);
		RIGHT (7);
		printf("%c%c", c,c);
		   
		RIGHT(8);
		printf("%c%c", c,c);
		RIGHT (17);
		printf("%c%c", c,c);
	}
	else
	{
	   POSITION( 13 ,20 );
	   printf("%c",c);
	   RIGHT (8);
	   printf("%c",c);
	   
	   RIGHT(10);
	   printf("%c",c);
	   RIGHT (19);
	   printf("%c",c);
	}
}

int askAgain() //Ja-Nein-Abfrage
{
   char c;
   
   POSITION(20,16);
   printf("\nMoechten Sie noch einmal (j/n)? ");
   do
   {
       
       scanf("%c", &c);
       if (c != '\n')
          clearBuffer();
       
       if(c !='J' && c!= 'j' && c != 'N' && c != 'n')
          
       {
	
          POSITION(21,16);
          printf("\nEingabe ungültig bitte nochmal: ");
       }
         
     
    } while (  ( c != 'j' && c != 'J' && c != 'N' && c != 'n'));
 
    if ( c == 'J' || c == 'j' )
       return 1;
    else
       return 0;
}
 
void clearBuffer() //Tastaturpuffer leeren
{
   char Dummy;
   do
   {
      scanf("%c", &Dummy);
   } while ( Dummy != '\n');
}
