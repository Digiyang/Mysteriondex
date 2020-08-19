#ifndef DATASTRUCTURE_H_INCLUDED
#define DATASTRUCTURE_H_INCLUDED

#define MAXSONGS 30
#define MAXCDS 100



typedef struct {

    int Second;
    int Minute;
    int Hour;

} TTime;

typedef struct {

    char * Titel;
    char * Interpret;
    TTime * Dauer;

} TSong;


typedef struct {

    char * Titel;
    char * Interpret;
    int numberOfSongs;
    TSong songs[MAXSONGS];

} TCD;

extern TCD * countCDs;
extern TCD * CDData[];

#endif // DATASTRUCTURE_H_INCLUDED
