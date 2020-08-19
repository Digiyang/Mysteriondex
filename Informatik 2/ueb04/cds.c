#include "cds.h"

 int countCDs = 0;
 TCD CDData[MAXCDS];



 void createCD(){

	   TCD *newCD = CDData + countCDs;
	   char *title = "Erfassung einer neuen CD";
	   clearScreen();

	   printf("%s\n", title);
	   printLine('-', strlen(title));
	   printf("\n");

	    getText("\nGeben Sie bitte den Titel der CD ein:\n-> ", MAXLENGTH, 0, &(newCD->Titel));
	    getText("Geben Sie bitte den Interpreten ein\n(Dieses Feld leer lassen, wenn die Lieder von\n"
		    "unterschiedlichen Interpreten stammen!)\n-> ", MAXLENGTH, 0, &(newCD->Interpret));
	    getNumber("Geben Sie bitte das Erscheinungsjahr ein:\n(zwischen 1980 und"
		      " 2019)\n-> ", &(newCD->YearOfAppearance), 1980, 2019);

	    newCD->numberOfSongs = 0;

	    title = "Geben Sie bitte die Daten der Lieder ein";
	    printf("\n%s\n", title);
	    printLine('-', strlen(title));

	    do {
		printf("\nLied %i", newCD->numberOfSongs+1);
		createSong(newCD);
		newCD->numberOfSongs++;
	    } while (askYesOrNo("\nMoechten Sie noch ein weiteres Lied eingeben (j/n)? "));

	    countCDs++;
 }

void createSong(TCD * cd) {

	   TSong *song = cd->songs + cd->numberOfSongs;
	   getText("\n     Geben Sie bitte den Titel des Liedes ein:\n     -> ", MAXLENGTH, 0, &(song->Titel));
	   getText("\n     Geben Sie bitte den Interpreten ein:\n     -> ", MAXLENGTH, 0, &(song->Interpret));
	   getTime("\n     Geben Sie bitte die Dauer des Liedes ein\n      (Format mm:ss):\n      -> ", cd->numberOfSongs,cd);

}

 void editCD(){
     printf("CD bearbeiten\n");
 }

 void deleteCD(){
     printf("CD loeschen\n");
 }

 void searchSong(){
     printf("Suchen\n");
 }

void sortCDs(){
     printf("Sortieren\n");
 }

void listCDs(TCD * CD){
	   int i;

	   clearScreen();
	   char title[] = "Erfassung einer neuen CD";
	   printf("%s\n", title);
	   printLine('-', strlen(title));

	   if(countCDs == 0)
	      printf("\n\nkeine CD erstellt!\n\n");

	   else
	   {
	      for(i = 0; i < countCDs; i++)
	      {
		 listOneCD(CDData + i);
	      }
	   }
	   printf("\n\n");


 }


 void listOneCD(TCD * CD) {

	    printf("\nTitel:                : %s\n",CD->Titel);
	    if(CD->Interpret != NULL) {
	    printf("Interpret             : %s\n",CD->Interpret);
	    }
	    printf("Erscheinungsjahr      : %d\n", CD->YearOfAppearance);
	    printf("Anzahl Songs          : %d\n", CD->numberOfSongs);
	    printf("Lieder:\n");
	    for(int c = 0; c < CD->numberOfSongs; c++) {
		printf("\t%2d. ",c+1);
		listOneSong( CD->songs + c );
	    }
 }

 void listOneSong(TSong * song) {

	    printf("%s",song->Titel);
	    printf(" (%s",song->Interpret);
	    printf("; ");
	    printTime(&(song->Dauer));
	    printf(")\n");
 }
