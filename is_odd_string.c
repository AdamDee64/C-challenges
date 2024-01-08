#include <stdio.h>
#define _TRUE_FALSE_ printf("true\n") : printf("false\n")

/*
functions that returns 1 if a number entered is odd, 0 if even.
one function is for integers, one is for integers that appear as a string
*/

int is_odd(int n){
  return n & 1;
}

int is_odd_s(char* number){
  while(*number) number++;
  return *(number - 1) & 1;
}

void main() {
  is_odd(99)      ? _TRUE_FALSE_;
  is_odd_s("255671") ? _TRUE_FALSE_;

  is_odd(82458)   ? _TRUE_FALSE_;
  is_odd_s("71888888123456") ? _TRUE_FALSE_;
}