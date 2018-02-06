#include <stdio.h>
#include "helper.h"
#include <stdlib.h>
#include <math.h>

int main(long argc, char** argv)
{
    long num = atoi(argv[1]);
    if(isPrime(num) == 1)
    {
        fprintf(stderr,"True\n");
    } else {
        fprintf(stderr,"False\n");
    }


    return 0;
}
