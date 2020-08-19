#include <stdlib.h>
#include "datastructure.h"
#include "time.h"


/********************************************************************
 * Funktion:      isTimeValid
 * Beschreibung:  Überprüft, ob die als Argument übergebene Zeit
 *                gültig ist
 * Paramater:     Eine Struktur, die die Zeit beinhaltet
 * Ergebnis:      1, wenn die Zeit gültig ist
 *                0, wenn nicht
 *******************************************************************/
int isTimeValid (TTime Time)
{
   if (Time.Hour >= 0 && Time.Hour <= 23 &&
       Time.Minute >= 0 && Time.Minute <= 59 &&
       Time.Second >= 0 && Time.Second <= 59)
      return 1;
   else
      return 0;
}

/********************************************************************
 * Funktion:      getTimeFromString
 * Beschreibung:  Eine in Stringform eingegebene Zeit wird in Int
 *                umgewandelt, überprüft und wenn korrekt in eine
 *                Struktur gespeichert.
 * Paramater:     - Der String, der die Zeit enthalten soll
 *                - Zeiger auf eine Struktur, in die die Zeit
 *                  gespeichert werden soll
 * Ergebnis:      1, wenn der String eine gültige Zeit enthielt
 *                0, wenn nicht
 *******************************************************************/
short getTimeFromString(char *input, TTime *time)
{
   char  *pHour = input,         // Zeiger für Stunden
         *pMinute = NULL,        // Zeiger für Minuten
         *pSecond = NULL,        // Zeiger für Sekunden
         *pSearch = input;       // Suchzeiger

   TTime toValid;                // Struktur zum Validieren der Zeit

   while (*pSearch)                                   // String nach Doppelpunkten durchsuchen und Pointer
   {                                                  // für Minute und Sekunde hinter die Doppelpunkte setzen
      if ( *pSearch == ':')
      {
         if (!pMinute)
            pMinute = pSearch+1;
         else
         {
            pSecond = pSearch+1;
            break;                                    // Wenn Pointer für Sekunde gesetzt: Suchschleife verlassen
         }
      }

      pSearch++;
   }

   if ( *pHour >= '0' && *pHour <= '9' )              // Überprüfen, ob eine Zahl eingegeben wurde
      toValid.Hour = atoi(pHour);                     // Zeit in die Validierungs-Struktur einspeichern
   else
      return 0;

   if (!pMinute)                                      // Falls keine Minute und/oder Sekunde eingegeben: 0 setzen
      toValid.Minute = 0;                             // Ansonsten eingegebene Daten übertragen
   else
      toValid.Minute = atoi(pMinute);

   if (!pSecond)
      toValid.Second = 0;
   else
      toValid.Second = atoi(pSecond);

   if (isTimeValid(toValid))                          // Wenn Die eingegebene Zeit korrekt ist,
   {                                                  // Validierungs-Struktur in Zeitstruktur kopieren
      time->Hour = toValid.Hour;                      // und die Funktion mit 1 beenden
      time->Minute = toValid.Minute;
      time->Second = toValid.Second;
      return 1;
   }
   else
      return 0;                                       // Ansonsten die Funktion mit 0 beenden
}
//hier
