#ifndef DATASTRUCTURE_H_INCLUDED
#define DATASTRUCTURE_H_INCLUDED

#define MAXSONGS 30
#define MAXCDS 100
#define MAXLENGTH 40


typedef struct {

    int Second;
    int Minute;
    int Hour;

} TTime;

typedef struct {

    char * Titel;
    char * Interpret;
    TTime Dauer;

} TSong;

typedef struct TCD TCD;

struct TCD
{

    char * Titel;
    char * Interpret;
    int numberOfSongs;
    int YearOfAppearance;
    TSong songs[MAXSONGS];

};

extern int countCDs;
extern TCD CDData[];

#endif // DATASTRUCTURE_H_INCLUDED
