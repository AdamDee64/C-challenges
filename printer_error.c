#include <stdio.h>

/*
function takes in a string and returns a separate string
the passed-in string represents a string of printer commands
the out string will report how many invalid commands were contained
in the string along with the total length of the string
valid printer commands are letters a to m case sensitive.
*/

char* printerError(char *s) {
  static char out[32];
  int e = 0;
  int total = 0;
  while(*s){
    if(*s < 97 || *s > 109) e++;
    total++;
    s++;
  }
  sprintf(out, "%d/%d", e, total);
  return out;
}

int main() {

  char *err = printerError("aaxbbccx");
  printf("%s\n", err);

  return 0;
}