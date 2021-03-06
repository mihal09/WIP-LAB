#include <stdio.h>
#include <math.h>
int main()
{
    int zakres = 1e5;
    int czy_pierwsza[zakres+1];
    for(int i=2; i<=zakres;i++)
        czy_pierwsza[i]=1;
    for(int n=2; n*n<=zakres;n++){ //n od 2 do pierwiastka z zakresu
        if(czy_pierwsza[n]){  //jesli jest pierwsza, to usuwamy z listy jej wielokrotnosci
            int k=n+n;
            while(k<=zakres){
               czy_pierwsza[k] = 0;
               k+=n;
            }
        }
    }
    int ile_pierwszych_wczesniej = 0;
    for(int n=2; n<=zakres;n++){
	ile_pierwszych_wczesniej += czy_pierwsza[n];
        printf("%d;%f\n",n,ile_pierwszych_wczesniej/(n/log(n)));
    }
    return 0;
}

