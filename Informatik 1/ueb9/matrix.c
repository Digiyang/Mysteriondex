#include <stdio.h>
#include <string.h>
#include "escapesequenzen.h"
#include "matrix.h"
#include "tools.h"
#include <stdlib.h>


int const MaxRows = 10, MaxColumns = 10;

int getNumberOfRows(int Row, int Col, int MatrixNo){
   
   int eingabe, rows ;

   do{
      POSITION(Row, Col);
      CLEAR_LINE;
      printf("Geben Sie bitte die Zeilenanzahl der %d. Matrix ein (1..8): ____", MatrixNo);
      POSITION(Row, strlen("Geben Sie bitte die Zeilenanzahl der 1. Matrix ein (1..8): ____") - 3);
      eingabe = scanf("%d", &rows);
      clearBuffer();
      
      eingabe = fehlerMeldungRow(eingabe, Row, Col,rows); 

   }while(!eingabe);
   POSITION(Row+1, Col+1);
   CLEAR_LINE;
 return rows ;
}

int getNumberOfColumns(int Row, int Col, int MatrixNo){
   
   int eingabe, cols ;

   do{
      POSITION(Row, Col);
      CLEAR_LINE;
      printf("Geben Sie bitte die Spaltenanzahl der %d. Matrix ein (1..8): ____", MatrixNo);
      POSITION(Row, strlen("Geben Sie bitte die Spaltenanzahl der 1. Matrix ein (1..8): ____") - 3);
      eingabe = scanf("%d", &cols);
      clearBuffer();
      eingabe = fehlerMeldungCol(eingabe, Row, Col,cols);
   }while(!eingabe);
   POSITION(Row+1, Col+1);
   CLEAR_LINE;
 return cols ;
}

void printFrameMatrix(int Row, int Col, int RowCount, int ColCount){
   int i=0, j=0;
   POSITION(Row, Col);
   CLEAR_LINE;
   for (i = 0; i < RowCount; i++)
   {
      printf("| ");
      for (j = 0; j < ColCount; j++)
         printf("____ ");
      printf("|                                                \n");
   }

}


int getNumber(int Row, int Col, int richtigCol, int AnzahlCol, int rtigRow, int AnzahlRow){

   int number;
   int eingabe;

   do{
      
      POSITION(Row, Col);
      //printf("| Eingabe Zahl %d:                                                       |", i);
      //POSITION(Zeile, 19);
      eingabe = scanf("%i", &number);
      clearBuffer();
      eingabe = fehlerMeldung(eingabe, Row, Col, number, richtigCol, AnzahlCol, rtigRow, AnzahlRow);
     
   }while(!eingabe);

   return number;
}



void getMatrix(int Row, int Col, int RowCount, int ColCount, int Matrix[MaxRows][MaxColumns]){

   
   int i=0, j=0, k=0, indiceCol = 0;
   POSITION(Row, Col);
   CLEAR_LINE;
   printFrameMatrix(Row, Col, RowCount, ColCount);
   for (i = 0; i < RowCount; i++)
   {
      //printf("| ");
      indiceCol = Col + 2;
      for (j = 0; j < ColCount; j++){
         Matrix[i][j] = getNumber(Row + i, indiceCol, j, ColCount, i, RowCount);
         POSITION(Row + i, indiceCol);
         printf("%4i ", Matrix[i][j]);
         indiceCol = indiceCol + 5;
         
        // Form der Matrize wiederherstellen, Im Fall einer richtigen Eingabe in der falschen Zeile
         POSITION(Row + i, indiceCol);
         for ( k = j+1 ; k < ColCount ; k++){
            printf("____ ");
         }printf("|                                                ");
         printFrameMatrix(Row + i +1, 1,RowCount-i-1,ColCount);
        //
      }
      //printf("|\n");
   }

}

int breiteNum(int num){
   int b = 0;
   int zahl = num;
   (zahl > 0) ? b = 0 : b++ ;
   zahl = abs(zahl);
    //printf("%d  ", max);
   do{

      b+=1;
      zahl = zahl/10;
      
   }while(zahl >= 1);
   return b;
}


int breite(int RowCount, int ColCount, int Matrix[MaxRows][MaxColumns]){
 
  int i=0, j=0, b=0, max = 4);
   for (i = 0; i < RowCount; i++)
   {
      //printf("| ");
      for (j = 0; j < ColCount; j++){
         b = breiteNum(Matrix[i][j]);
         if( b > max)
            max = b;
      }
         
   }
   /*
   (max > 0) ? j = 0 : j++ ;
    //printf("%d  ", max);
   do{

      j+=1;
      max = max/10;
      
   }while(max >= 1);
    */
   return max;
}

void printMatrix(int Row, int Col, int RowCount, int ColCount, int Matrix[MaxRows][MaxColumns]){

   int i=0, j=0;
   int breit = breite(RowCount, ColCount, Matrix);
   POSITION(Row, Col);
   //CLEAR_LINE;
   for (i = 0; i < RowCount; i++)
   {  POSITION(Row + i, Col);
      printf("|");
      for (j = 0; j < ColCount; j++)
         printf(" %*d", breit, Matrix[i][j]);
      printf(" |");
   }
   //printf("%d", breit);
}


void calcMatrix(int RowCount1, int ColCount1, int ColCount2, int M1[MaxRows][MaxColumns], int M2[MaxRows][MaxColumns], int MErg[MaxRows][MaxColumns]){

   int i=0, j=0, k=0;
   for (i = 0; i < RowCount1; i++)
   {
      for (j = 0; j < ColCount2; j++)
      {
         MErg[i][j] = 0;
         for (k = 0; k < ColCount1; k++)
         {
           
             MErg[i][j] = MErg[i][j] + M1[i][k]*M2[k][j];

         }
      } 
   }

}


int askAgain(int Row, int Col){
   char antwort;
   
		do{
                        POSITION(Row, Col);
                        CLEAR_LINE;
			printf("\nMoechten Sie noch einmal (j/n)? ");
			
			// Einlesen der Antwort

			//scanf("%c", &antwort);

			// Anwort muss \n ungleich sein
                        do
			{
				scanf("%c", &antwort);
			}while(antwort == '\n');

			// Puffer leeren

			clearBuffer();
		
			// Fehlermeldung falls keiner der Zeichen j, J, n, N eingegeben wird

			if ( (antwort != 'n') && (antwort != 'N')  &&  (antwort != 'J') && (antwort != 'j') )
			{
				printf("\nFalsche Eingabe! Bitte 'j' oder 'n' eingeben! Eingabetaste drucken ...");
                                eingabeTasteDruck();
			}
                        
		// Die Frage nicht mehr stellen falls einer der Zeichen j, J, n, N eingegeben wird	

		}while( (antwort != 'n') && (antwort != 'N') && (antwort != 'J') && (antwort != 'j') );

		if ((antwort == 'n') || (antwort == 'N')){
		
		   return 0;
		}else{
		   return 1;
		}

}




























