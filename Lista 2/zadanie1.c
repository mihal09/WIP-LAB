#include <stdio.h>
int main()
{
    int zl, gr, kwota;
    printf("podaj liczbę złoty: ");
    scanf("%d", &zl);
    printf("podaj liczbę groszy: ");
    scanf("%d", &gr);
    kwota = zl*100+gr;
    int nominaly[] = {200*100, 100*100, 50*100, 20*100, 10*100, 5*100, 2*100, 1*100, 50, 20, 10, 5, 2, 1};
    int ile_nominalow = sizeof(nominaly)/sizeof(nominaly[0]);
    for(int i=0; i<ile_nominalow; i++)
    {
        if(i==0)
            printf("banknoty:\n");
        else if(nominaly[i]==5*100)
            printf("monety:\n");

        int ile_nominalu = kwota/nominaly[i];
        if(ile_nominalu>0)
        {
            if(nominaly[i]>=1*100) //wypisz zl na koncu
                printf("    %d x %d zł\n",ile_nominalu, nominaly[i]/100);
            else //wypisz gr na koncu
                printf("    %d x %d gr\n",ile_nominalu, nominaly[i]);
            kwota %= nominaly[i];
        }
    }
    
    return 0;
}

