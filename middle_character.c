#include <string.h>
#include <stdio.h>

/* 
a function that returns the middle character of a given string
if the string has an even number of characters, it will return the two middle characters
*/

char *get_middle(char outp[3], const char *inp)
{
  int c = 0;
  while(*(inp + c)) c+=1;
  
  outp[0] = *(inp + c / 2);
  outp[1] = 0;
  outp[2] = 0;
  if (c % 2 == 0) {
    outp[0] = *(inp + c / 2 - 1);
    outp[1] = *(inp + c / 2);
  }
  return outp;
}


int main() {
  char outp[3];

  printf("%s\n,", get_middle(outp, "testing"));


  return 0;
}