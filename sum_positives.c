#include <stddef.h>
#include <stdio.h>

/*
a function that sums up only the positive values in an array. 
*/

int positive_sum(const int *values, size_t count){
  int out = 0;
  while(count--) out += (*values > 0 ? *values++ : *values++ * 0);
  return out;
}

int main() {
  int arr[] = {10, -5, 6, 4, -17, 100}; // 120
  size_t length = sizeof(arr) / sizeof(arr[0]);

  printf("%d\n", positive_sum(arr, length));

  return 0;
}