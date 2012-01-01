#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int testPalindrome(char *number);

int
main(void)
{
  int i,j;
  int palindrome;
  int largestPalindrome = 1;
  char palinBuf[7];
  
  for (i=100; i<999; i++)
    for(j=i; j<999; j++) {
       sprintf(palinBuf, "%d", i*j); 
      if (testPalindrome(palinBuf)) {
        palindrome = atoi(palinBuf);
        if(palindrome > largestPalindrome)
          largestPalindrome = palindrome;
      }
    }
printf("Answer: %d\n", largestPalindrome);

}

int
testPalindrome(char *buf)
{
  char *newbuf;
  

  if(buf[1] == 0)
    return 1;
  
  int numDigits = strlen(buf);
  
  if (buf[0] == buf[numDigits-1]) {
    if (buf[2] == 0)
      return 1;
    newbuf = malloc(numDigits*sizeof(char)+1);
    strncpy(newbuf, buf+1, numDigits-2);
    newbuf[numDigits]='\0';
      if(testPalindrome(newbuf)) {
        free(newbuf);
        return 1;
      }
      else {
        free(newbuf);
        return 0;
      }
  }
  else
    return 0;
}