#include <stdio.h>

/*
a function that takes in a name and returns the initials capitalized
with a . between the letters. Input will always be two names separated by a space
*/

char *get_initials (const char *full_name, char initials[4])
{
  *initials = '\0';
  initials[0] = full_name[0];
  initials[1] = 46;

  int get_initial = 0;
  while(*full_name++){
    if(get_initial) {
      initials[2] = *full_name;
      break;
    }
    if(*full_name == 32) get_initial = 1;
  }
  
  if(initials[0] >= 97 && initials[0] <= 122) initials[0] -= 32;
  if(initials[2] >= 97 && initials[2] <= 122) initials[2] -= 32;

  return initials; // return it
}

int main() {

  char initials[4];

  printf("%s\n", get_initials("bobo yolo", initials));

  return 0;
}