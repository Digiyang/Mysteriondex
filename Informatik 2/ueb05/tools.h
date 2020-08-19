#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED
#include <string.h>

	void clearBuffer();
	void clearScreen();
	int askYesOrNo(char * phrase);
	void printLine(char c, int num);
	void waitForEnter();
	int getText(char * prompt, int allowedChars, int emptyAllowed, char ** target);
	void getNumber(char *t, int *, int, int);
    void fclearBuffer(FILE * Datei);
char * lineStart(char * Line);

#endif // TOOLS_H_INCLUDED
