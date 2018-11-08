#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool palindrom(char napis[]){
	int wielkosc = strlen(napis);
	int i=0, j=wielkosc-1;
	while(i<=j){
		if(napis[i]!=napis[j])
			return false;
		i++; j--;
	}
	return true;
}

int main(){
	char napis[200];
	scanf("%s",napis);
	printf("%d",palindrom(napis));
	
}
