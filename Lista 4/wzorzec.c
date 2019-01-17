#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define maxDlugosc 100

bool DEBUG = false;

char* bezPierwszejLitery(char* napis){
    char* wynik;
    wynik = napis+1;
    return wynik;
}

char * usunNiepotrzebneGwiazdki(char * wzor){
    if(wzor[0]=='*' && wzor[1]=='*')
        return usunNiepotrzebneGwiazdki(wzor+1);
    else return wzor;
}

bool matchChar(char wzor, char porownywany){
    if(wzor=='?')
        return true;
    else return wzor==porownywany;
}

bool match(char wzor[], char porownywany[], int poziom){
    if(DEBUG){
        for(int i=0;i<poziom;i++)
                    printf("     ");
        printf("%s - %s\n",wzor, porownywany);
    }


    wzor = usunNiepotrzebneGwiazdki(wzor);
    //TERMINACJA
    if(strcmp(wzor,"*")==0) //czy wzor == '*'
        return true;
    else if(strlen(wzor)==0 && strlen(porownywany)==0) //oba puste
        return true;
    else if (strlen(wzor)==0 || strlen(porownywany)==0) //jeden pusty a drugi nie
        return false;
    if(wzor[0]!='*'){ //jesli nie mamy gwiazdki na poczatku wzoru
        if(matchChar(wzor[0], porownywany[0])){
            return match(bezPierwszejLitery(wzor),bezPierwszejLitery(porownywany),poziom);
        }
        else
            return false;
    }
    else{ //jesli mamy gwiazdke na poczatku wzoru
        if(!matchChar(wzor[1],porownywany[0])) //jesli znak po gwiazdce nie jest ok, to go omin
            return match(wzor, bezPierwszejLitery(porownywany),poziom);
        else{ //jesli znak po gwiazdce jest ok
            if(DEBUG){
                for(int i=0;i<poziom+1;i++)
                        printf("     ");
                printf("-----\n");
            }
            if(match(bezPierwszejLitery(bezPierwszejLitery(wzor)), bezPierwszejLitery(porownywany),poziom+1)) //jesli dalej uda sie dopasowac
                return true;
            else //jesli sie nie uda, to ten znak nie byl dobrym wyborem, omijamy go
            {
                if(DEBUG){
                    for(int i=0;i<poziom+1;i++)
                        printf("     ");
                    printf("-----\n");
                }
                 return match(wzor, bezPierwszejLitery(porownywany),poziom);
            }
        }
    }
}

int main()
{
    if(match("a********c","ababababab",0))
        printf("tak");
    else
        printf("nie");

    return 0;
}
