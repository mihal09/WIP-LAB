#include "nwd.h"

long int nwd(long int a, long int b){
	if(b!=0)
		return nwd(b,a%b);
	return a;
}
