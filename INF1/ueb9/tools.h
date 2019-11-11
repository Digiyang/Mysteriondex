#ifndef TOOLS_H
   #define TOOLS_H TOOLS_H

/**********************************************************
 * Funktion:     clearBuffer
 * Beschreibung: loescht den Tastaturpuffer
 * Parameter:    /
 * Ergebnis:     /
 **********************************************************/
void clearBuffer();

/**********************************************************
 * Funktion:     fehlerMeldung
 * Beschreibung: meldet einen Fehler beim Eingeben eines
 *               Operands
 * Parameter:    int eingabe: die Eingabe zu ueberpruefen
 *               int rows, cols:Zeile und Spalte fuers Anzeigen der Fehlermeldung
 * Ergebnis:     /
 **********************************************************/
int fehlerMeldung(int eingabe,int rows, int cols, int Num, int richtigCol, int AnzahlCol,int rtigRow, int AnzahlRow);
int fehlerMeldungRow( int eingabe,int rows, int cols, int Row);
int fehlerMeldungCol( int eingabe,int rows, int cols, int Col);

/**********************************************************
 * Funktion:     eingabeTasteDruck
 * Beschreibung: pausiert den Verlauf des Programms
 * Parameter:    /
 * Ergebnis:     /
 **********************************************************/
void eingabeTasteDruck();

#endif
