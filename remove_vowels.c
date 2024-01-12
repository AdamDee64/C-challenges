#include <stdlib.h>
#include <stdio.h>

//solution must allocate all required memory
//and return a free-able buffer to the caller.

char *disemvowel(const char *str)
{
  int length = 0;
  while(*(str + length++));
  char *out = calloc(1, length);
  length = 0;
  while(*str) {
    switch(*str){
      case 'a':
      case 'A':
      case 'e':
      case 'E':
      case 'i':
      case 'I':
      case 'o':
      case 'O':
      case 'u':
      case 'U':
      break;
      default:
      *(out + length++) = *str;
    }
    *str++;
  }
  return out;
}

int main(){

  printf("%s\n", disemvowel("This is a test of things"));

  return 0;
}