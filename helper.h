#include <math.h>

void print_name(char * name)
{
  //fprintf(stderr,"Holy crap! It was %s all along!\n",name); // prints name
  fprintf(stderr, "%s\n",name);
}

//Primaility test by clever brute force
int isPrime(long x)
{
    if(x<=1||fmodl(x,2)==0)
    {
      //fprintf(stderr,"What");
      return 0;

    }else{

        long s = (long)sqrt(x);
        //fprintf(stderr,"%ld\n",s);
        for(long i = 3;i<=s;i+=2)
        {
            //fprintf(stderr, "%d\n",i);
            if(fmodl(x,i)==0)
        {
        long a = x%i;
        //fprintf(stderr, "%ld\n%ld\n",i,a);

        return 0;
      }
    }
  }
    //fprintf(stderr,"%d\n",x);
    return 1;
}
