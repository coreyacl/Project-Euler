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
#include <string.h>
#include <stdbool.h>


char * itoa();
bool isPol();
unsigned long long dec2bi();
double pow(double x, double y);
double ceil(double x);
double floor(double x);


int main(int argc, char const *argv[]) {

    //char * a = "55";
    //fprintf(stderr, "%d\n%d\n is %u long\n",a[0],a[1],(unsigned)strlen(a) );

    unsigned long long num = atoi(argv[1]);
    bool v = isPol(num);
    if(v){
        fprintf(stderr,"True\n");
    } else {
        fprintf(stderr,"False\n");
    }

    return 0;
}

bool isPol(unsigned int x){
    char snum [12]; //creates an empty string with length of 12
    itoa(x,snum,10); //takes the int and turns it into a string in the space of snum
    unsigned len = strlen(snum); //holds length of snum
    /* This checks to see if the decimal version of the number is palindromic */
    for (int i = 0;i<(int)(len/2);i++){
        if(snum[i]!=snum[(len-1)-i]){
            return false;
    }
}
    short diff = 0;
    int x1 = x;
    while(x1>0){
    diff ++;
    x1 = (int)(x1/2);
    }

    int shift = 0;

    if(diff%2==0){ //shift deals with odd length binary numbers
        shift = 0;
    } else {
        shift = 1;
    }
    //THIS WORKS
    int f2 = x; //holds value to reverse it
    f2 = f2 >> (int)(diff/2); //gets the second half of bits

    //THIS WORKS
    int f1 = x;
    f1 = (f2 << (int)(diff/2)) ^ f1;//gets the first half of bits

    f2 = f2 >> shift;

    //THIS DOES NOT WORK...YET
    int rev = (f2- pow(2,(int)diff/2-1)); //f2 supposed to hold the f2lementary number that has the bits reversed

    unsigned long long aa = dec2bi(x);
    unsigned long long a = dec2bi(f2);
    unsigned long long b = dec2bi(f1);
    unsigned long long c = dec2bi(rev);

    fprintf(stderr, "%d : %llu\n \
%d : %llu\n \
%d : %llu\n \
%d : %llu\n ",(int)x,aa,f2,a,f1,b,rev,c);

    if(rev ^ f1 != 0)
    {
        //fprintf(stderr, "what");
        return false;
    } else {
        return true;
    }
}

unsigned long long dec2bi(int x){
    /*
    input: positive integer
    returns: number in binary in a long

    limitations: fails somewhere between 520000 and 1000000 due to insuffeciant
    space to store number in unsigned long long
    */

    if(x==0){
        return 0;
    }
    else
    {
        return(x % 2 + 10 * (dec2bi(x / 2)));
    }
}


char *
itoa (int value, char *result, int base)
{
    // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }

    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );

    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while (ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}
