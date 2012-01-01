#include <stdio.h>
#include <math.h>

int
main(void)
{
  long long int sumHundred=0;
  long long int sumSquared=0;
  long long int squaredSum=0;
  long long int diff=0;

  for (int count = 1; count <= 100; count++) {
    sumHundred+=count;
    squaredSum += pow(count, 2);
    printf("%d + ", pow(count,2));
  }

  sumSquared = pow(sumHundred, 2);

  diff = sumSquared - squaredSum;

  printf("sumHundred: %lli\n", sumHundred);
  printf("sumSquared: %lli\n", sumSquared);
  printf("squaredSum: %lli\n", squaredSum);
  printf("Answer: %lli\n", diff);
}
