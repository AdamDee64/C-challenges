#include <stdio.h>

/*
given a year, this function returns it's century
years 1-100 are considered part of the same century, not 0-99
example
499 - 5th century
500 - 5th century
501 - 6th century
*/

int centuryFromYear(int year) 
{
  return (year % 100 == 0) ? year / 100 : year / 100 + 1;
}

int main() {
  printf("%d\n", centuryFromYear(2024));
  printf("%d\n", centuryFromYear(200));
  printf("%d\n", centuryFromYear(201));
  printf("%d\n", centuryFromYear(1999));
  printf("%d\n", centuryFromYear(2001));
}