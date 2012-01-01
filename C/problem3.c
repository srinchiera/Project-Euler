/*			Challenge				  /
/* What is the largest prime factor of the number 600851475143 ?  /
/*                                                               */

#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

#define longInt uint64_t
#define MAX 20000

longInt n = 600851475143;
//longInt n = 400000;

int numPrimes=0;
int *primes;
longInt g_count = 3;

longInt factor(longInt factorTest);
longInt prime(longInt largestFactor);
void sieve(void);

typedef struct testNum
{
  int num;
  int marked;
} testNum;

int
main(void) {

  longInt largestFactor = 0;
  longInt factorTest = n;

  // this is our answer
  longInt largestPrimeFactor = 1;
  sieve();
  
  // if largestFactor isn't prime, test find next largest factor
  do 
  {
  
  // test to see if this number is a factor of n
  while(g_count < n){
    if (n % g_count == 0){
      factorTest = n / g_count;
      printf("%lli divided by %lli = %lli\n", n, g_count, factorTest);

      g_count+=2;
      break;
    }
    g_count+=2;
  }
  } while(!(largestPrimeFactor = prime(factorTest)));
  
  printf("Answer: %lli\n", largestPrimeFactor);

}

longInt
prime(longInt isPrime)
{
  longInt rootFactor = sqrt(isPrime);
  longInt count;

  // check to see if divisible by first 200 primes
  for (count = 0; count < numPrimes, primes[count] < isPrime; count++)
    if (isPrime % primes[count] == 0){
      return 0;
    }
  // then check rest of primes
  for (count = 1; (MAX*count-1) <= rootFactor; count++)
  {
    int i=0;
    if(!(isPrime % (MAX*count-1)))
    {
	  return 0;
	}
	if(!(isPrime % (MAX*count-1)))
	{
	  return 0;
	}
	
    // if remainder = 0 continue
	for (i = 1; i < numPrimes; i++){
      if(!(isPrime % (MAX*count-primes[i])))
  	    return 0;
    }
    
    for (i = 1; i < numPrimes; i++){
	if (!(isPrime % (MAX*count+primes[i])))
	  return 0;
	}
  }

  return isPrime;
 
}

void
sieve(void)
{

  testNum consec[MAX];
  int label;
  int p = 2;
  int count, primesCount = 1;
  
  // array of all numbers
  for (label = 0; label < MAX; label++)
    consec[label].num = label;

  // make all numbers unmarked
  for (label = 0; label < MAX; label ++)
    consec[label].marked = 0;

  // 0, 1, 2 are marked
  consec[0].marked = 1;
  consec[1].marked = 1;
  consec[2].marked = 1;

  // while p is below the MAX
  while (p < MAX-3)
  {
    // for all multiple of p's within interval, make that spot marked
    for (count = 2; p*count < MAX; count++){
      consec[p*count].marked = 1;
    }
    
    // find the next p by starting at the current p and finding where the next unmarked # is
    for (count = p+1; count < MAX; count++){
      if (consec[count].marked == 0){
        p = consec[count].num;
        break;
      }
    }
  }
  
    for (count = 0; count < MAX; count++){
      if (consec[count].marked == 0) {
        numPrimes++;
      }
    }
    numPrimes++;
    primes = malloc(numPrimes * sizeof(int));
    primes[0] = 2;
    for (count = 0; count < MAX; count++)
      if (consec[count].marked == 0){
        primes[primesCount] = consec[count].num;
        primesCount++;
      }
      
}
