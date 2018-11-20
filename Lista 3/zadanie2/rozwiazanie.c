#include <stdio.h>
#include <math.h>
#include "rozwiazanie.h"
#include "f.h"

double rozwiazanie(double a, double b, double eps)
{	
	while(fabs(a-b)>2*eps)
	{
		double c = (a+b)/2;
		if(f(c)==0)
			return c;
		if(f(a)*f(c)<0)
			b = c;
		else
			a = c;
	}
	return (a+b)/2;
}
