#include <stdio.h>
#include <stdlib.h>

/*
a function that takes in a number written out as a string and returns
it as an integer in the range of 0 - 999,999,999,999
*/

int compare_strings(char *str_a, char *str_b){
  while(*str_a && *str_b){
    if(*str_a++ != *str_b++) return 0;
  }
  if(*str_a++ != *str_b++) return 0;
  return 1;
}

long parse_int (const char *number) {
  long out = 0;
  if(number == "zero") return out;
  
  while(*number) {
    long len = 0;
    while(1) {
      len++;
      if(number[len] == ' ' || number[len] == '-' || number[len] == '\0') break;
    }

    char *test = calloc(len + 1, 1);
    
    long count = 0;
    while(len--) test[count++] = *number++;
    
    if(*number) number++;

    if(compare_strings(test, "one")) out += 1;
    else if(compare_strings(test, "two")) out += 2;
    else if(compare_strings(test, "three")) out += 3;
    else if(compare_strings(test, "four")) out += 4;
    else if(compare_strings(test, "five")) out += 5;
    else if(compare_strings(test, "six")) out += 6;
    else if(compare_strings(test, "seven")) out += 7;
    else if(compare_strings(test, "eight")) out += 8;
    else if(compare_strings(test, "nine")) out += 9;

    else if(compare_strings(test, "ten")) out += 10;
    else if(compare_strings(test, "eleven")) out += 11;
    else if(compare_strings(test, "twelve")) out += 12;
    else if(compare_strings(test, "thirteen")) out += 13;
    else if(compare_strings(test, "fourteen")) out += 14;
    else if(compare_strings(test, "fifteen")) out += 15;
    else if(compare_strings(test, "sixteen")) out += 16;
    else if(compare_strings(test, "seventeen")) out += 17;
    else if(compare_strings(test, "eighteen")) out += 18;
    else if(compare_strings(test, "nineteen")) out += 19;

    else if(compare_strings(test, "twenty")) out += 20;
    else if(compare_strings(test, "thirty")) out += 30;
    else if(compare_strings(test, "forty")) out += 40;
    else if(compare_strings(test, "fifty")) out += 50;
    else if(compare_strings(test, "sixty")) out += 60;
    else if(compare_strings(test, "seventy")) out += 70;
    else if(compare_strings(test, "eighty")) out += 80;
    else if(compare_strings(test, "ninety")) out += 90;

    else if(compare_strings(test, "hundred")) out += out % 100 * 100 - out % 100;
    else if(compare_strings(test, "thousand")) out += out % 1000 * 1000 - out % 1000;
    else if(compare_strings(test, "million")) out += out % 1000000 * 1000000 - out % 1000000;
    else if(compare_strings(test, "billion")) out += out % 1000000000 * 1000000000 - out % 1000000000;
    
    // printf("%s, %ld\n", test, out);
    free(test);
  }

  return out;
}

int main() {

  char *str_1 = "nine hundred eleven billion six hundred forty-seven million eight hundred ninety-nine thousand two hundred and forty-six";
  char *str_2 = "one hundred eleven billion one hundred eleven million one hundred eleven thousand one hundred eleven";
  char *str_3 = "nine hundred thousand and twenty-two";
  char *str_4 = "one hundred and twenty";
  char *str_5 = "eight";

  printf("%ld\n", parse_int(str_1));
  printf("%ld\n", parse_int(str_2));
  printf("%ld\n", parse_int(str_3));
  printf("%ld\n", parse_int(str_4));
  printf("%ld\n", parse_int(str_5));

  return 0;
}