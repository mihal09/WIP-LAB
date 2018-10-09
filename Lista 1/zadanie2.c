#include <stdio.h>
#include <math.h>
int main()
{
    float a,b,c;
    scanf("%f %f %f", &a, &b, &c);
    float delta = b*b - 4*a*c;
    if(delta<0){
        printf("W zbiorze liczb rzeczywistych nie ma rozwiązania tego równania\n");
    }
    else if(delta==0){
        float x1 = -b/(2*a);
        printf("%f\n",x1);
    }
    else {
        float x1 = (-b-sqrt(delta))/(2*a);
        float x2 = (-b+sqrt(delta))/(2*a);
        printf("%f %f\n",x1, x2);
    }
    return 0;
}

