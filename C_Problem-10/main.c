/*
Problem 10

@author: Corey Cochran-Lepiz

A script that can be run in the terminal to
find the sum of all primes below given number

Called with:
>>> gcc isPrimeScript.c -o primeSum -lm
>>> ./primeSum 2000000
142913828922

Note:
Modulo functions stops working after around 3.5 millions
so function is moot after that

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int main(int argc, char** argv)
{
    long sum = 2;
    int i = 3;
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
