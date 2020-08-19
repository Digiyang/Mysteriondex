#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <stdlib.h>

					//-----------dies Programm gibt die Username zurück------------
int main (){
	
	uid_t me;
	struct passwd *MeinID;
	
	// getuid in me speichern , und danach me in MeinID speichern.
	me = getuid ();
	MeinID = getpwuid (me);				
	
	

	puts(MeinID->pw_name); // Zeiger auf pw_name.


	return 0;

}
