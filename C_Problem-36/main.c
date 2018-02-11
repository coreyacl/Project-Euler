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

    int comp = x; //holds value to reverse it
    comp = comp >> (int)(diff/2); //gets the second half of bits
    int rev = (pow(2,(int)diff/2)-comp)-1; //comp supposed to hold the complementary number that has the bits reversed
    //if((comp-1)%2==0 || (x-1)%2==0){
    //    return true;
    //}
    fprintf(stderr, "%d\n%d\n%d\n",comp,rev,rev^x);
    int agh = rev^comp;
    fprintf(stderr, "ahhh %d\n",agh );
    if(rev ^ comp != 0)
    {
        //fprintf(stderr, "what");
        return false;
    }


    return true;
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
