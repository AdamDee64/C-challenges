#include <stdio.h>
#include <inttypes.h>

/*
function takes in an unsigned integer and rearranges the digits
to make the largest possible integer with those digits.
*/

uint64_t descendingOrder(uint64_t n)
{
  char number[32];
  sprintf(number, "%lu", n);
  char high = 9;
  uint64_t out = 0;
  int i = 0;

  while(1) {
    while(number[i]){
      if (number[i++] - 48 == high){
        out *= 10;
        out += (uint64_t)high;
      }
    }
    if(!high--) break;
    i = 0;
  }
  return out;
}

int main() {

  printf("%lu\n", descendingOrder(1469594179));

  return 0;
}