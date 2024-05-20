#include <stdio.h>
#include <stdlib.h>

// a function that turns a string of numbers into a digital style ascii drawing
// include the character : to display the time

void build_char(char *target, char *segment){
   int i = 0;
   while(i < 3){
      target[i] = segment[i];
      i++;
   }
}

void parse_char(char value, char *str_a, char *str_b, char *str_c, int offset){

   switch(value){
      case '0':
      build_char(str_a + offset * 4, " _ ");
      build_char(str_b + offset * 4, "| |");
      build_char(str_c + offset * 4, "|_|");
      break;
      case '1':
      build_char(str_a + offset * 4, "   ");
      build_char(str_b + offset * 4, "  |");
      build_char(str_c + offset * 4, "  |");
      break;  
      case '2':
      build_char(str_a + offset * 4, " _ ");
      build_char(str_b + offset * 4, " _|");
      build_char(str_c + offset * 4, "|_ ");
      break; 
      case '3':
      build_char(str_a + offset * 4, " _ ");
      build_char(str_b + offset * 4, " _|");
      build_char(str_c + offset * 4, " _|");
      break; 
      case '4':
      build_char(str_a + offset * 4, "   ");
      build_char(str_b + offset * 4, "|_|");
      build_char(str_c + offset * 4, "  |");
      break; 
      case '5':
      build_char(str_a + offset * 4, " _ ");
      build_char(str_b + offset * 4, "|_ ");
      build_char(str_c + offset * 4, " _|");
      break; 
      case '6':
      build_char(str_a + offset * 4, " _ ");
      build_char(str_b + offset * 4, "|_ ");
      build_char(str_c + offset * 4, "|_|");
      break; 
      case '7':
      build_char(str_a + offset * 4, " _ ");
      build_char(str_b + offset * 4, "  |");
      build_char(str_c + offset * 4, "  |");
      break; 
      case '8':
      build_char(str_a + offset * 4, " _ ");
      build_char(str_b + offset * 4, "|_|");
      build_char(str_c + offset * 4, "|_|");
      break; 
      case '9':
      build_char(str_a + offset * 4, " _ ");
      build_char(str_b + offset * 4, "|_|");
      build_char(str_c + offset * 4, " _|");
      break; 
      case ':':
      build_char(str_a + offset * 4, "   ");
      build_char(str_b + offset * 4, " - ");
      build_char(str_c + offset * 4, " - ");
      break;     
   }
}

void print_number(char *number){

   int length = 0;
   while(number[++length]);
   length *= 4;

   char *str_a = calloc(length, 3);

   char *str_b = (str_a + 1 * length);
   char *str_c = (str_a + 2 * length);

   int i = 0;

   while(*(number + i)){
      if(*number + i){
         *(str_a + i * 4 + 3) = ' ';
         *(str_b + i * 4 + 3) = ' ';
         *(str_c + i * 4 + 3) = ' ';
      }
      parse_char(*(number + i), str_a, str_b, str_c, i);
      i++;
   }

   str_a[i * 4 - 1] = 0;
   str_b[i * 4 - 1] = 0;
   str_c[i * 4 - 1] = 0;

   printf("%s\n%s\n%s\n", str_a, str_b, str_c);
   free(str_a);
}


int main(void){

   print_number("775566");
   print_number("12:05");
   print_number("05:06:81");

   return 0;
}