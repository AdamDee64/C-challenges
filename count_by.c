#include <stdio.h>

/*
A function that takes in two numbers and an empty array
the first number is the multiplier, the second number is the size of the empty array

the function populates the array with sequential multiples of the first number

for example (2, 4, arr[4]) will return [2, 4, 6, 8]
*/

void print_array(unsigned arr[], unsigned length){
  unsigned i = 0;
  printf("[");
  while(--length) printf("%d, ", arr[i++]);
  printf("%d]\n", arr[i]);
}

void count_by(unsigned x, unsigned n, unsigned result[n]) {
  while(n) *(result + n) = n-- * x;
}

#define ARR_SIZE 10

int main() {
  unsigned mult = 2;
  unsigned count = ARR_SIZE;
  unsigned arr[ARR_SIZE];

  count_by(mult, count, arr);
  print_array(arr, count);

  return 0;
}