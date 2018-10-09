#include <stdio.h>
#include <string.h>
int main()
{
    char napis[] = "ABRAKADABRA";
    int dlugosc = strlen(napis);
    for(int i=dlugosc; i>0; i--) //i mowi ile znakow jest w danym wierszu
    {   
        for(int k=0; k<dlugosc-i; k++) //drukowanie spacji przed wierszem
        {
            printf(" ");
        }
        for(int j=0; j<i; j++)  //drukujemy tylko i znakow
        {
            printf("%c ",napis[j]);
        }
        printf("\n"); //koniec wiersza
    }
    return 0;
}

