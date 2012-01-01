#include <stdio.h>
#include <stdlib.h>

#define MAX 200000

int
main(void)
{

  int numPrimes = 0;
  int primes[1000000];

  typedef struct testNum
  {
    int num;
    int marked;
  } testNum;


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
  consec[2].marked = 0;

  // while p is below the MAX
  for (int count = 0; count < 10001; count++)
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
    primes[0] = 2;
    for (count = 0; count < MAX; count++)
      if (consec[count].marked == 0){
        primes[primesCount] = consec[count].num;
        primesCount++;
      }
    
    printf("Answer: %d\n", primes[10001]);
      
}