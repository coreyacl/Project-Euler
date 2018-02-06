#include <stdio.h>
#include "helper.h"
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv)
{
    long sum = 2;
    int i = 1;
    long upperBound = atoi(argv[1]);
    while(i<upperBound)
    {
        if(isPrime(i)==1)
        {
            sum += i;
        }
    i += 2;
    }
    fprintf(stderr,"%ld\n",sum);

    return 0;
}
