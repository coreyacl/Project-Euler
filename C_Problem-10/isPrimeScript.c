/*
Problem 10

@author: Corey Cochran-Lepiz

A script that can be run in the terminal to
see if a given number is prime or not.

Called with:
>>> gcc isPrimeScript.c -o isPrime -lm
>>> ./isPrime 23
True

Note:
Modulo functions stops working after around 3.5 millions
so function is moot after that

*/

#include <stdio.h>
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

/*
Primality test via clever brute force
*/

int isPrime(long x)
{
    if(x<=1||fmodl(x,2)==0)
    {
      return 0;

    }else{

        long s = (long)sqrt(x);
        for(long i = 3;i<=s;i+=2)
        {
            if(fmodl(x,i)==0)
        {
        long a = x%i;

        return 0;
      }
    }
  }
    return 1;
}
