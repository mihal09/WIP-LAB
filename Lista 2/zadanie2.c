#include <stdio.h>
int main()
{
    int n, liczba;
    double suma=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&liczba);
        suma += liczba;
    }
    printf("%.2f\n",suma/n);
    return 0;
}

