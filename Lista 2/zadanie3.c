#include <stdio.h>
int main()
{
    int i=0;
    double left = 0;
    while(!(left>10)){
        i++;
        left += (double)1/i;
    }
    printf("Najmniejsze n: %d\n",i);
    return 0;
}

