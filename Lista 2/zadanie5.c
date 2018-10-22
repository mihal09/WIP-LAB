#include <stdio.h>
int nwd(a,b){
	if(b==0)
		return a;
	return nwd(b,a%b);
}

int maks=1000;

int main()
{	
	int ile = 0;
	for(int i=1; i<=maks; i++){
		for(int j=1; j<=i; j++){
			if(nwd(i,j)==1){
				ile++;	
			}
		
		}
		printf("%d;%f\n",i,(double)ile/(i*i));
	}
	 
    return 0;
}

