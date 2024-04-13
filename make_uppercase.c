#include <stdio.h>

/*
A function that converts an ascii string to uppercase.
*/

void to_upper(char *str) {
   while(*str){
      if(*str >= 'a' && *str <= 'z') *str -= 32;
      str++;
   }
}

void main(){

   char str[] = "thIs is A string.";
   to_upper(str);
   printf("%s\n", str);

}