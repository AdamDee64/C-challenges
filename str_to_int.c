#include <stdio.h>

/*
function takes in a number written as a string and returns
the equivalent as an integer, signed or unsigned.
*/

int string_to_number(const char *src) {
  int out = 0;
  int sign = 1;
  if (*src == 45) sign = *src++ - 46;
  while(*src) out = out * 10 + *src++ - 48;
  return out * sign;
}

int main() {

  printf("%d\n", string_to_number("-4822"));
  printf("%d\n", string_to_number("-0"));
  printf("%d\n", string_to_number("-1"));
  printf("%d\n", string_to_number("255"));

  return 0;
}