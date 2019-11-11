#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

void save();
void saveCDs(FILE * Datei, TCD * cd);
void saveSong(FILE *Datei, TSong * song);
void load();
void loadCDs(FILE * Datei);
void loadSong(FILE * Datei, TSong * song);

#endif // DATABASE_H_INCLUDED
