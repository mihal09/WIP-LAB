#include <stdio.h>
#include <math.h>
#include "rozwiazanie.h"

int main(){
	double a = 2;
	double b = 4;
	for(int k=1;k<=8;k++){
		double eps = pow(10,-k);	
		printf("10^(-%d) - %lf\n",k,rozwiazanie(a,b,eps));
	}
}
