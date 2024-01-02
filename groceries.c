#include <stdio.h>
#include <stdbool.h>

/*
  a function that takes in an array of customers with the time it will take to process their groceries at the till
  along with the number of tills. customers are processed in order they appear in the array. 

  for example customers array [ 5, 3, 1 ] and 2 tills
  customer 0 and 1 go into the till 0 and 1
  customer 2 waits for an open till
  customer 1 finishes after the 3rd minutes, freeing the second till
  customer 2 takes the second till
  customer 2 finishes after the 4th minute
  customer 0 finishes after the 5th minute
  no more customers are left, so the total time is 5 minutes

  also handles edge cases(no customers, 1 till, more tills than customers)
*/


int queue_time(const int *customers, int customers_length, int n){

  if (!customers) return 0;
  if (n == 1) {
    int count = 0;
    for(int i = 0; i < customers_length; i++ ) count += customers[i];
    return count;
  }
  if (n > customers_length) {
    int highest = 0;
    for(int i = 0; i < customers_length; i++) if (customers[i] > highest) highest = customers[i];
    return highest;
  }

  int total_time = 0;
  int tills[n];

  for(int i = 0; i < n; i++) tills[i] = customers[i];

  int c = n;

  while(1){
    int tills_busy = 0;
    for(int i = 0; i < n; i++) {
      tills_busy += tills[i];
      if(!tills[i] && c < customers_length) tills[i] = customers[c++] - 1;
      else if (tills[i] > 0) tills[i]--;
      tills_busy += tills[i];
    }

    if (!tills_busy) break;
    else total_time += 1;
  }

  return total_time;
}




void main() {

  int customers1[] = {2, 2, 3, 3, 4, 4};
  int customers1_length = 6;
  int n1 = 2;

  int customers2[] = {1, 2, 3, 4};
  int customers2_length = 4;
  int n2 = 1;

  int customers3[] = {1, 2, 3, 4, 5};
  int customers3_length = 5;
  int n3 = 100;

  printf("%d\n", queue_time(NULL, 0, 1));                         // 0
  printf("%d\n", queue_time(customers1, customers1_length, n1));  // 9
  printf("%d\n", queue_time(customers2, customers2_length, n2));  // 10
  printf("%d\n", queue_time(customers3, customers3_length, n3));  // 5
}