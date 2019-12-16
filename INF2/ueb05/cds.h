#ifndef CDS_H
#define CDS_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "datastructure.h"
#include "tools.h"
#include "datetime.h"
#include "menu.h"


void createCD();

void createSong(TCD * cd);

void editCD();

void deleteCD();

void searchSong();

void sortCDs();

int listCDs();

void listOneCD(TCD * CD);

void listOneSong(TSong * song);




#endif