#include <stdio.h>
int main()
{
    int i=0;
    double left = -10;
    while(!(left>0)){
        i++;
        left += (double)1/i;
    }
    printf("Najmniejsze n: %d\n",i);
    return 0;
}

