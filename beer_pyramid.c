#include <stdio.h>

/*
given a dollar amount and the price of a beer, return the number of 
layers of a 3 dimensional beer pyramid that can be built within budget
*/

int beeramid(double budget, double unit_cost) { 
  if(budget <= 0) return 0;
  int current_level = 1;
  int inc = 3;
  int total = 0;
  int count = 0;

  while(total * unit_cost <= budget){
    total += current_level;
    current_level += inc;
    inc += 2;
    count++;
  }

  return count -1;
}

int main() {

  printf("%d\n", beeramid(1500, 2));

  return 0;
}