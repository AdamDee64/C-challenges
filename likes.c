#include <stdlib.h>
#include <stdio.h>

/*
a function that returns a string depending on the number of "likes"
a post gets on social media. 
*/

char *likes(size_t n, const char *const names[n]) {
  char *out = calloc(1, 64);
  switch(n){
      case 0:
      sprintf(out, "no one likes this");
      break;
      case 1:
      sprintf(out, "%s likes this", names[0]);
      break;
      case 2:
      sprintf(out, "%s and %s like this", names[0], names[1]);
      break;
      case 3:
      sprintf(out, "%s, %s and %s like this", names[0], names[1], names[2]);
      break;
      default:
      sprintf(out, "%s, %s and %lu others like this", names[0], names[1], n - 2);
      break;
  }
  return out;
}

int main() {

  const char *const names[4] = {"Alex", "Jacob", "Mark", "Max"};
  printf("%s\n", likes(2, names));
  
}