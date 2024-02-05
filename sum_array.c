#include <stddef.h>
#include <stdio.h>

/*
A function that takes in an array of integers and the length of the array
returns the sum of the numbers in the array
*/

int sum_array(const int *values, size_t count){
   int out = 0;
   while(count) out += values[count-- - 1];
   return out;
}




int main() {
   //           1  4  8  10 15 21 22 23 25           
   int arr[] = {1, 3, 4, 2, 5, 6, 1, 1, 2}; // 25
   printf("%d\n", sum_array(arr, 9));

   return 0;
}