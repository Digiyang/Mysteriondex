                                                                        #include <stdio.h>
                                                                        #include <string.h>
                                                                        #include "datastructure.h"
                                                                        #include <stdlib.h>
                                                                        #include "tools.h"
                                                                        #include "cds.h"
                                                                        #include "datetime.h"


                                                                        void saveSong(FILE *Datei, TSong * song)
                                                                        {



                                                                           fprintf(Datei, " <Song>\n");
                                                                           fprintf(Datei, "  <Title>%s</Title>\n", song->Titel);
                                                                           if(song->Interpret != NULL){
                                                                           fprintf(Datei, " <Interpret>%s</Interpret>\n",song->Interpret);
                                                                           }
                                                                           fprintf(Datei, "  <Duration>%02d:%02d</Duration>\n",song->Dauer.Minute, song->Dauer.Second);
                                                                           fprintf(Datei, " </Song>\n");

                                                                        }

                                                                        void saveCDs(FILE * Datei, TCD * cd)
                                                                        {
                                                                           int songsNum;

                                                                           fprintf(Datei, "<CD>\n");
                                                                           fprintf(Datei, " <Title>%s</Title>\n", cd->Titel);
                                                                           if(cd->Interpret != NULL){
                                                                           fprintf(Datei, " <Interpret>%s</Interpret>\n", cd->Interpret);
                                                                           }
                                                                           fprintf(Datei, " <YearOfAppearance>%d</YearOfAppearance>\n", cd->YearOfAppearance);
                                                                           for(songsNum = 0; songsNum<cd->numberOfSongs; songsNum++)
                                                                              saveSong(Datei, (cd->songs)+songsNum);
                                                                           fprintf(Datei, "</CD>\n\n");
                                                                        }

                                                                        void save()
                                                                        {
                                                                           FILE * Datei = fopen("CD-Verwaltungsdatenbank.xml", "wt");
                                                                           int cdNumber;

                                                                           fprintf(Datei, "<Daten>\n");
                                                                           for (cdNumber = 0; cdNumber < countCDs; cdNumber++)
                                                                              saveCDs(Datei, CDData+cdNumber);
                                                                           fprintf(Datei, "</Daten>\n");
                                                                           fclose(Datei);
                                                                        }

                                                                        void loadSong(FILE * Datei, TSong * song)
                                                                        {
                                                                           char Zeile [101];
                                                                           char * pZeile;
                                                                           int Len;
                                                                           TTime  D;

                                                                           int i;

                                                                           if ( Datei )
                                                                           {
                                                                              do
                                                                              {
                                                                                 for (i=0; i<101; i++)
                                                                                    Zeile[i]=0;
                                                                                 fscanf( Datei, "%100[^\n]", Zeile);
                                                                                 fclearBuffer(Datei);
                                                                                 pZeile = lineStart(Zeile);
                                                                                 if (strncmp (pZeile, "<Title>", 7) == 0)
                                                                                 {
                                                                                    Len = strlen( pZeile + 7 ) - 8;
                                                                                    if ( strncmp( pZeile + 7 + Len, "</Title>", 8) == 0 )
                                                                                    {
                                                                                       song->Titel = calloc (Len +1, sizeof(char));
                                                                                       if (song->Titel)
                                                                                          strncpy (song->Titel, pZeile + 7, Len);
                                                                                    }
                                                                                 }
                                                                                 if (strncmp (pZeile, "<Interpret>", 11) ==0)
                                                                                 {
                                                                                     Len = strlen( pZeile + 11 ) - 12;
                                                                                     if ( strncmp( pZeile + 11 + Len, "</Interpret>", 12) == 0 )
                                                                                     {
                                                                                        song->Interpret = calloc (Len +1, sizeof(char));
                                                                                        if (song->Interpret)
                                                                                       strncpy (song->Interpret, pZeile+11, Len);
                                                                                     }
                                                                                 }
                                                                                 if (strncmp (pZeile, "<Duration>", 10) ==0)
                                                                                 {
                                                                                    Len = strlen( pZeile + 10 ) - 11;
                                                                                    if ( strncmp( pZeile + 10 + Len, "</Duration>", 11) == 0 )
                                                                                    {

                                                                                      if (&(song->Dauer))
                                                                                         if (getTimeFromString(pZeile+10, &D))
                                                                                         {

                                                                                         song-> Dauer.Minute=D.Minute;
                                                                                         song-> Dauer.Second=D.Second;

                                                                                        }
                                                                                    }
                                                                                 }

                                                                                 if (feof ( Datei ))
                                                                                    break;
                                                                              } while (strncmp (pZeile, "</Song>", 7) != 0);
                                                                           }
                                                                        }

                                                                        void loadCDs(FILE * Datei)
                                                                        {
                                                                           char Zeile [101];
                                                                           char * pZeile;
                                                                           int Len;
                                                                           TCD *cd = CDData+countCDs;
                                                                           cd->numberOfSongs = 0;
                                                                           int i;

                                                                           do
                                                                           {
                                                                              for (i=0; i<101; i++)
                                                                                  Zeile[i]=0;
                                                                              fscanf( Datei, "%100[^\n]", Zeile);
                                                                              fclearBuffer(Datei);
                                                                              pZeile = lineStart(Zeile);

                                                                              printf ("%s \n", pZeile);
                                                                              if (strncmp (pZeile, "<Title>", 7) == 0)
                                                                                 {
                                                                                    Len = strlen( pZeile + 7 ) - 8;
                                                                                    if ( strncmp( pZeile + 7 + Len, "</Title>", 8) == 0 )
                                                                                    {
                                                                                       cd->Titel = calloc (Len +1, sizeof(char));
                                                                                       if (cd->Titel)
                                                                                          strncpy (cd->Titel, pZeile + 7, Len);
                                                                                    }
                                                                                 }
                                                                              if (strncmp (pZeile, "<Interpret>", 11) ==0)
                                                                              {
                                                                                 Len = strlen( pZeile + 11 ) - 12;
                                                                                 if ( strncmp( pZeile + 11 + Len, "</Interpret>", 11) == 0 )
                                                                                 {
                                                                                    cd->Interpret = calloc (Len +1, sizeof(char));
                                                                                    if (cd->Interpret)
                                                                                       strncpy (cd->Interpret, pZeile+11, Len);
                                                                                 }
                                                                              }
                                                                              if (strncmp (pZeile, "<YearOfAppearance>", 18) ==0)
                                                                                   cd->YearOfAppearance = atoi(pZeile+18);

                                                                              if ( (strncmp (pZeile, "<Song>", 6) ==0) && cd->numberOfSongs >= 23 )
                                                                              {
                                                                                 do
                                                                                 {
                                                                                    for (i=0; i<101; i++)
                                                                                       Zeile[i]=0;
                                                                                    fscanf( Datei, "%100[^\n]", Zeile);
                                                                                    fclearBuffer(Datei);
                                                                                    pZeile=lineStart(Zeile);
                                                                                    if (strncmp (pZeile, "<Titel>", 7) ==0)
                                                                                       printf("%s", pZeile);
                                                                                    if (strncmp (pZeile, "<Interpret>", 11) ==0)
                                                                                       printf("%s", pZeile);
                                                                                    if (strncmp (pZeile, "<Duration>", 10) ==0)
                                                                                       printf("%s", pZeile);
                                                                                 }while (strncmp (pZeile, "</Song>", 7) != 0);
                                                                              }
                                                                              if ( (strncmp (pZeile, "<Song>", 6) ==0) && cd->numberOfSongs < 23 )
                                                                              {
                                                                                 loadSong(Datei, (cd->songs)+(cd->numberOfSongs));
                                                                                 cd->numberOfSongs++;
                                                                              }
                                                                              if ( feof(Datei) )
                                                                                 break;
                                                                           } while (strncmp (pZeile, "</CD>", 5) != 0);
                                                                        }

                                                                        void load()
                                                                        {
                                                                           FILE *Datei = fopen("CD-Verwaltungsdatenbank.xml", "rt");
                                                                           char Zeile [101];
                                                                           char * pZeile;
                                                                           int i;

                                                                           if ( Datei )
                                                                           {
                                                                              do
                                                                              {
                                                                                 for (i=0; i<101; i++)
                                                                                    Zeile[i]=0;
                                                                                 fscanf( Datei, "%100[^\n]", Zeile);
                                                                                 fclearBuffer(Datei);
                                                                                 pZeile = lineStart(Zeile);
                                                                                 printf ("%s \n", pZeile);

                                                                                 if (strncmp (pZeile, "<CD>", 4) == 0)
                                                                                 {
                                                                                    loadCDs(Datei);
                                                                                    countCDs++;
                                                                                 }
                                                                                 if (feof ( Datei ))
                                                                                    break;

                                                                              } while (strncmp (pZeile, "</Daten>", 8) != 0);
                                                                              fclose(Datei);
                                                                           }
                                                                        }

