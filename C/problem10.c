#include <stdio.h>
#include <stdlib.h>

#define MAX 2000000

int
main(void)
{

  int numPrimes = 0;
  int *primes;
  long long int grandTotal = 2;
  
  typedef struct testNum
  {
    int num;
    int marked;
    struct testNum *nextNum;
  } testNum;

  testNum *consec = malloc(sizeof(testNum));
  testNum *start=consec;

  int p = 2;
  int count, primesCount = 1;
  

  
  // array of all numbers
  for (int label = 0; label < MAX; label++) {
    consec->num = label;
    consec->marked = 0;
    consec->nextNum = malloc(sizeof(testNum));
    consec = consec->nextNum;
  }
  
  // 0, 1 are marked
  start->marked = 1;
  start->nextNum->marked = 1;

  testNum *editThis;
  testNum *startAt = start;
  
  // for every p start at the beginning of the list
    startAt = start;
    //traverse list until you find p
    for (int findP = 2; findP < MAX; findP++) {
      if (startAt->num != p)
        startAt = startAt -> nextNum;
	}
  editThis = startAt;
  testNum *oldP;
  oldP = editThis;
  // while p is below the MAX
  while (p < 1999993) {
  
    /**** OPTIMIZATION *****/
    /* find the next p while you are traversing the list to mark 
    /* the next interval of the current p
    /* the first number you skip that isn't marked will be the next p
    /* this will take 1/2 the time 
  
    /*** GROUPING *****/
	/* find groups of 100 prime numbers that you can mark off the list as you go
    */
  
  
    // go up p every interval
    for (int count = p; count<= MAX-p; count+=p) {
        // move along editThis up p
		for (int skip=0; skip<p; skip++)
		  editThis=editThis->nextNum;
		editThis->marked = 1;
    }
   
    // we don't want to include p
    editThis = oldP->nextNum;

    // try to find next p
    while(editThis->marked != 0)
      editThis=editThis->nextNum;
    p = editThis->num;
    oldP = editThis;
    grandTotal+=p;
    printf("Primes: %d\n", p);
  }
      printf("Total: %lli\n", grandTotal);
}