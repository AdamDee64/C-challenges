#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
An intentionally bad implementation of hello world.
*/

char *greet(char *greeting) {
  int how_long_hello_world_string_should_be;
  how_long_hello_world_string_should_be = 13;
  int length_of_greeting_string;
  length_of_greeting_string = 0;
  int lengthOfGreetingStringIndex;
  lengthOfGreetingStringIndex = 0;
  while(greeting[lengthOfGreetingStringIndex] != '\0') {
    length_of_greeting_string++;
    lengthOfGreetingStringIndex++;
  }
  int allocateThisManyBytes = 0;
  if(length_of_greeting_string != how_long_hello_world_string_should_be) {
    allocateThisManyBytes = how_long_hello_world_string_should_be;
  } else {
    allocateThisManyBytes = length_of_greeting_string;
  }

  char *output = malloc(allocateThisManyBytes);

  char *hello = "hello world!";
  bool greeting_matches_string = true;
  int match_index = 0;
  while(match_index < allocateThisManyBytes){
    if (greeting[match_index] != hello[match_index]) {
      greeting_matches_string = false;
    }
    match_index += 1;
  }

  if(greeting_matches_string == true) {
    int i = 0;
    while(i < allocateThisManyBytes) {
      output[i] = greeting[i];
      i+=1;
    }
  } else {
    int i = 0;
    while(i < allocateThisManyBytes) {
      output[i] = hello[i];
      i+=1;
    }
  }
  return output;
}

int main() {

  printf("%s\n", greet("hello world!"));

  return 0;
}