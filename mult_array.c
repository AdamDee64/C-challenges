#include <stddef.h>
#include <stdio.h>

int grow(size_t size, const int arr[size]) {
   int out = 1;
   while(size) out *= arr[size-- - 1];
   return out; //Your code comes here
}



int main() {

   int arr[] = {1, 2, 4, 3}; // 24

   printf("%d\n", grow(4, arr));


   return 0;
}