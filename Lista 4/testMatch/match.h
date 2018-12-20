#ifndef MATCH_H_INCLUDED
#define MATCH_H_INCLUDED

char* bezPierwszejLitery(char* napis);
char * usunNiepotrzebneGwiazdki(char * wzor);
bool matchChar(char wzor, char porownywany);
bool match(char wzor[], char porownywany[], int poziom);

#endif // MATCH_H_INCLUDED
