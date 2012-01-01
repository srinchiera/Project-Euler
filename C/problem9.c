#include <stdio.h>
#include <math.h>

int
main (void)
{
  double a, b, c;
  for (a = 1; a < 998; a++)
    for (b = a; b < 998; b++) {
      c = sqrt(pow(a,2) + pow(b,2));
      if(a+b+c == 1000)
        printf("Answer: %f\n", a*b*c);
    }

}