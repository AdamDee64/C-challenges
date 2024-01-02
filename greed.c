#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
A function that takes in an array representing the values of 5 six-sided dice
it returns a score based on the dice game Greed where 3 or more of any value
are worth 100x the face value, with special scoring conditions for 1 and 5.

3 x 1 = 1000 pts
3 x 2 = 200 pts
3 x 3 = 300 pts
3 x 4 = 400 pts
3 x 5 = 500 pts
3 x 6 = 600 pts

in addition to above:
5s are worth 50 points each when they appear less than or more than 3 times
1s are worth 100 points each when they appear less than or more than 3 times

for fun I also made a random roll generator
*/

int* roll_dice() {
  static int dice[5];
  int i = 0;
  printf("dice: [ ");
  while(i < 5){
    dice[i] = rand() % 6 + 1;
    printf("%d ", dice[i++]);
  }
  printf("], score = ");
  return dice;
}

int score(const int dice[5]) {
  int total = 0;
  int arr[6] = {0};
  
  int i = 4;
  while(i >= 0) arr[dice[i--] - 1]++;

  i = 0;
  
  while(i < 6){
    int points = 0;
    points += arr[i] / 3 * 100;
    if (i == 1 -1 || i == 5 -1) points += arr[i] % 3 * 10;
    if (i == 1 -1) points *= 10;
    points *= 1 + i++;
    total += points;
  }
  return total;
}

void main() {

  srand(time(NULL));
  int number_of_rolls = 10;
  while(number_of_rolls--) printf("%d\n", score(roll_dice()));

}