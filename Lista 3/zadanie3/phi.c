#include <math.h>
#include "phi.h"
#include "nwd.h"

int phi(long int n)
{
	int count;
	for(long int i=1; i<=n; i++)
	{
		if(nwd(n,i)==1)
			count++;
	}
	return count;
}
