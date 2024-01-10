#include <stdio.h>

/*
a function that sums up all the numbers between 0 and the passed in integer, including the
passed integer. positive numbers only
*/

int summation(int num) {
  int out = 0;
  while(num) out += num--;
  return out;
}

int main() {
  printf("%d\n", summation(5));
}