#include <stdio.h>
int main()
{
    int n;
    scanf("%i", &n);
    for(int i=0;i<n;i++)   //n wierszy
    {
         for(int j=0;j<n*2;j++) //2n kolumn
         {
             printf("*");
         }
         printf("\n");
    }
    return 0;
}

