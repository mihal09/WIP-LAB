#include <stdio.h>
#include "palindrom.h"

int main(){
	char napis[200];
	scanf("%s",napis);
	if(palindrom(napis))
		printf("To jest palindrom\n");
	else
		printf("To nie jest palindrom\n");
	
}
