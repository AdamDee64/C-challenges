#include <stdbool.h>
#include <stdio.h>

/*
a function that returns true or false depending on the final state of 3 possible states
the state changes based on which state it is currently in and which binary number is passed to it
the state changes are given in a string of binary numbers
*/

bool read_commands(const char* commands)
{
  int state = 1;
  
  while(*commands){
    switch(state){
      case(1):
      if(*commands == '1') state = 2;
      break;
      case(2):
      if(*commands == '0') state = 3;
      break;
      default:
      state = 2;
    }
    *commands++;
  }
  return (state == 2) ? true : false;
}

int main() {

  read_commands("111001010") ? printf("true\n") : printf("false\n");

  return 0;
}