#include <stdio.h>

int sigma(int n){
	int suma = 1;
	for(int i=2; i*i <= n; i++){
		if(n%i==0){
			suma+=i;
			suma+=n/i;
		if(i*i==n) //nie licz pierwiastka dwa razy
			suma-= i;
		}

	}
	return suma;
}

int n=1000;

int main()
{	
	int tablica[n];
	int wypisane[n];
	for(int i=0;i<n;i++)
		wypisane[i]=0;
	printf("Liczby doskonale mniejsze od %d:\n",n);
	for(int i=1; i<n; i++){
		int ile = sigma(i);
		tablica[i] = ile;
		if(i==ile)
			printf("%d\n",i);
	}

	printf("Pary liczb zaprzyjaznionych mniejszych od %d:\n",n);
	for(int i=1; i<n; i++){
		int m = tablica[i];
	//	if(m==i) continue;
		if(tablica[m]==i){
			if(wypisane[i]==0)
				printf("%d i %d\n",i, m);
			wypisane[m] = 1;
			wypisane[i] = 1;
		}
	}
	
	 
    return 0;
}

