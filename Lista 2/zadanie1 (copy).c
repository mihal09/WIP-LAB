#include <stdio.h>
int banknoty = [200,100,50,20,10];
int monety1 = [5,2,1];
int monety2 = [50,20,10,5,2,1]

void dziel_banknoty(int kwota){
	printf("banknoty:\n");
	for(int i=0; i<ile_nominalow; i++){
     	   int ile_nominalu = kwota/banknoty[i];
     	   if(ile_nominalu>0)
		{
       	         	printf("    %d x %d zł\n",ile_nominalu, banknoty[i]);
	        	kwota %= nominaly[i];
		}
	}
}

int main()
{
    int zl, gr, kwota;
    printf("podaj liczbę złoty: ");
    scanf("%d", &zl);
    printf("podaj liczbę groszy: ");
    scanf("%d", &gr);
    kwota = zl*100+gr;
    int nominaly[] = {200*100, 100*100, 50*100, 20*100, 10*100, 5*100, 2*100, 1*100, 50, 20, 10, 5, 2, 1};
    for(int i=0; i<ile_nominalow; i++)
    {
        if(i==0)
            
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

