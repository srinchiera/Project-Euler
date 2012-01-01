#include <stdio.h>

int
main(void) {

  int counter = 0, sum = 0;

  for (; counter < 1000; counter++)
    if (counter % 5 == 0 || counter % 3 == 0)
      sum+=counter;

  printf("Answer: %d\n", sum);

}
