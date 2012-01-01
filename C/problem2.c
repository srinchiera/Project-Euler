#include <stdio.h>

int
main(void) {
  unsigned long int previous = 1, previousTmp = 1, counter = 1, sum = 0;

  while(counter < 4000000) {
    if (counter%2 == 0)
      sum+=counter;

    previousTmp = counter;
    counter+=previous;
    previous = previousTmp;
  }

  printf("Answer: %lu\n", sum);

}
