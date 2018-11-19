#include <stdbool.h>
#include <string.h>
#include "palindrom.h"

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
