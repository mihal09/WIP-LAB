#include <stdio.h>
int main()
{
    int n;
    scanf("%i", &n);
    for(int i=0; i<n; i++) 
    {
        for(int k=0; k<n-i-1; k++) //gdy i rosnie, odstep ma malec
            printf(" ");
        for(int j=0; j<i*2+1; j++) //kazdy kolejny wiersz ma o 2 gwiazdki wiecej
        {
            printf("*");
        }
        printf("\n");
    }
	printf("XD");
    return 0;
}

