#include <stdio.h>

int
main(void)
{
  long long int testNum = 0;
  int gotIt = 0;


  while(!gotIt)
  { 
    testNum+=(2*3*5*7*11*13*17*19);
    printf("Testing: %lli\n", testNum);

      if (testNum % 8 != 0)
	    continue;
	  if (testNum % 9 != 0)
	    continue;
      if (testNum % 12 != 0)
	    continue;
	  if (testNum % 16 != 0)
	    continue;
      if (testNum % 20 != 0)
	    continue;
	    	    	    
        gotIt = 1; 
  }
  printf("Answer: %lli\n", testNum-10);
  
}
