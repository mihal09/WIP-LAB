#include <stdio.h>

int sigma(n){
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
	int tablica[n+1];
	printf("Liczby doskonale mniejsze od %d:\n",n);
	for(int i=1; i<=n; i++){
		int ile = sigma(i);
		tablica[i] = ile;
		if(i==ile)
			printf("%d\n",i);
	}
	for(int i=1; i<=n; i++){
	}
	
	 
    return 0;
}

