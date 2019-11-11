#include <stdio.h>
#include "escapesequenzen.h"
#include "tools.h"
#include "matrix.h"

/**********************************************************
 * Funktion:     clearBuffer
 * Beschreibung: loescht den Tastaturpuffer
 * Parameter:    /
 * Ergebnis:     /
 **********************************************************/
void clearBuffer(){
   char dummy;
   do{
       scanf("%c", &dummy);
   }while(dummy!='\n');
}




/**********************************************************
 * Funktion:     fehlerMeldung
 * Beschreibung: meldet einen Fehler beim Eingeben eines
 *               Elements
 * Parameter:    int eingabe: die Eingabe zu ueberpruefen
 *               int rows, cols:Zeile und Spalte fuers Anzeigen der Fehlermeldung
 *               int zahl : element der Matrice zu uberpruefen
 *               int richtigCol und AnzahlCol: die Spalte wo der Cursor ist und die gesamte Spaltenanzahl
 * Ergebnis:     /
 **********************************************************/

int fehlerMeldung( int eingabe,int rows, int cols, int zahl, int richtigCol, int AnzahlCol,int rtigRow, int AnzahlRow){
   int k=0;
   if(!eingabe){

      POSITION(rows - rtigRow + AnzahlRow + 1, 1);
      CLEAR_LINE;
      //POSITION(7, 3);
      printf("Falsche Eingabe!Datatype ungueltig! Die Eingabetaste drucken...");
      //POSITION(7, 49);
      eingabeTasteDruck();
      POSITION(rows - rtigRow + AnzahlRow + 1, 1);
      CLEAR_LINE;

      // Form der Matrize wiederherstellen, Im Fall eines Fehlers
      POSITION(rows, cols);
      for ( k = richtigCol ; k < AnzahlCol ; k++){
         printf("____ ");
      }printf("|                                                ");
      printFrameMatrix(rows + 1, 1,AnzahlRow-rtigRow-1,AnzahlCol);
      //

   }else if((zahl < -999) || (zahl > 9999)){

      POSITION(rows - rtigRow + AnzahlRow + 1, 1);
      CLEAR_LINE;
      //POSITION(7, 3);
      printf("Falsche Eingabe!Asser Wertbereich! Die Eingabetaste drucken...");
      //POSITION(7, 49);
      eingabeTasteDruck();
      POSITION(rows - rtigRow + AnzahlRow + 1, 1);
      CLEAR_LINE;


      eingabe = 0;

      // Form der Matrize wiederherstellen, Im Fall eines Fehlers
      POSITION(rows, cols);
      for ( k = richtigCol ; k < AnzahlCol ; k++){
         printf("____ ");
      }printf("|                                                ");
      printFrameMatrix(rows + 1, 1,AnzahlRow-rtigRow-1,AnzahlCol);
      //

   }
   return eingabe ;
}

/**********************************************************
 * Funktion:     fehlerMeldungRow
 * Beschreibung: meldet einen Fehler beim Eingeben eines
 *               Elements
 * Parameter:    int eingabe: die Eingabe zu ueberpruefen
 *               int rows, cols:Zeile und Spalte fuers Anzeigen der Fehlermeldung
 *               int zahl : Anzahl von Zeile,die ueberprueft werden soll
 *                          (Darf weder negativ noch groesser als MaxRows)
 * Ergebnis:     /
 **********************************************************/
int fehlerMeldungRow( int eingabe,int rows, int cols, int zahl){

   if(!eingabe){

      POSITION(rows+1, cols);
      CLEAR_LINE;
      //POSITION(7, 3);
      // Nochmals zu ueberpruefen und richtig anpassen
      printf("Falsche Eingabe !! Datatype ungueltig! Die Eingabetaste drucken...");
      //POSITION(7, 49);
      eingabeTasteDruck();
      POSITION(rows+1, cols);
      CLEAR_LINE;
   }else if((zahl <=0)||(zahl > MaxRows)){
      POSITION(rows+1, cols);
      CLEAR_LINE;
      //POSITION(7, 3);
      // Nochmals zu ueberpruefen und richtig anpassen
      printf("Falsche Eingabe! Ausserhalb des Gueltigkeitsbereichs! Die Eingabetaste drucken...");
      //POSITION(7, 49);
      eingabeTasteDruck();
      POSITION(rows+1, cols);
      CLEAR_LINE;

      eingabe = 0;
   }
  return eingabe;
}
int fehlerMeldungCol( int eingabe,int rows, int cols, int zahl){

   if(!eingabe){

      POSITION(rows+1, cols);
      CLEAR_LINE;
      //POSITION(7, 3);
      printf("Falsche Eingabe! Datatype ungueltig! Die Eingabetaste drucken...");
      //POSITION(7, 49);
      eingabeTasteDruck();
      POSITION(rows+1, cols);
      CLEAR_LINE;
   }else if((zahl <=0)||(zahl > MaxColumns)){
      POSITION(rows+1, cols);
      CLEAR_LINE;
      //POSITION(7, 3);
      // Nochmals zu ueberpruefen und richtig anpassen
      printf("Falsche Eingabe! Ausserhalb des Gueltigkeitsbereichs! Die Eingabetaste drucken...");
      //POSITION(7, 49);
      eingabeTasteDruck();
      POSITION(rows+1, cols);
      CLEAR_LINE;


      eingabe = 0;
   }
  return eingabe;
}
/**********************************************************
 * Funktion:     eingabeTasteDruck
 * Beschreibung: pausiert den Verlauf des Programms
 * Parameter:    /
 * Ergebnis:     /
 **********************************************************/
void eingabeTasteDruck(){
   char dummy;
   do{
       scanf("%c", &dummy);
   }while(dummy!='\n');
}
