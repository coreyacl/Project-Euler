/*
Problem 36

@author: Corey Cochran-Lepiz

A program that can tell if a number is a palindromic or not

Called with:

Note:

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long dec2bi(int x){
    """
    input: positive integer
    returns: number in binary in a long

    limitations: fails somewhere between 100000 and 1000000 due to insuffeciant
    space to store number in unsigned long
    """

    if(x==0){
        return 0;
    }
    else
    {
        return(x % 2 + 10 * (dec2bi(x / 2)));
    }
}

int main(int argc, char const *argv[]){

    int num = atoi(argv[1]);
    fprintf(stderr, "%ld\n",dec2bi(num) );
    return 0;
}
