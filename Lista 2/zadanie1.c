#include <stdio.h>
int banknoty[] = {200,100,50,20,10};
int monety1[] = {5,2,1};
int monety2[] = {50,20,10,5,2,1};

void dziel_banknoty(int kwota){
	for(int i=0; i<5; i++){
     	   int ile_nominalu = kwota/banknoty[i];
     	   if(ile_nominalu>0)
		{
       	         	printf("    %d x %d zł\n",ile_nominalu, banknoty[i]);
	        	kwota %= banknoty[i];
		}
	}
}

void dziel_monety1(int kwota){
	for(int i=0; i<3; i++){
     	   int ile_nominalu = kwota/monety1[i];
     	   if(ile_nominalu>0)
		{
       	         	printf("    %d x %d zł\n",ile_nominalu, monety1[i]);
	        	kwota %= monety1[i];
		}
	}
}

void dziel_monety2(int grosze){
	for(int i=0; i<6; i++){
     	   int ile_nominalu = grosze/monety2[i];
     	   if(ile_nominalu>0)
		{
       	         	printf("    %d x %d gr\n",ile_nominalu, monety2[i]);
	        	grosze %= monety2[i];
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
    printf("banknoty:\n");
    dziel_banknoty(zl);
    printf("monety:\n");
    dziel_monety1(zl%10);
    dziel_monety2(gr);	
    
    return 0;
}

