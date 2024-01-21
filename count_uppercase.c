#include <stdio.h>

/*
function checks to see if character in string is uppercase. returns non-zero value if true
*/


long unsigned is_uppercase(char c){
  return (c >= 'A' && c <= 'Z') ? 1 : 0;
}

int main() {

  char *str = "Alice in Wonderland by C.S. Lewis";

  long unsigned count = 0;
  while(*str) count += is_uppercase(*str++) ? 1 : 0;

  printf("%lu\n", count);

  return 0;
}