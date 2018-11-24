#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "match.h"
int main()
{
    if(match("a*b*b*c","aQQQbWWWbEEEc",0))
        printf("tak");
    else
        printf("nie");

    return 0;
}
