#include <stdio.h>
#include <stdbool.h>

/*
function takes in two strings, and returns true if the characters in 
string 1 include all the characters of string 2, including quantity
of specific characters
*/

// solution 1
// compare each string to the alphabet individually, then compare the counts, and repeat
// this makes 52 iterations total
bool scramble1(const char *str1, const char *str2) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int a = 0;

    while (a < 27) {
        int i = 0;
        int count_i = 0;
        while(*(str2 + i) != 0){
            if(alphabet[a] == *(str2 + i)) count_i += 1;
            i += 1;
        }
        i = 0;
        if (count_i > 0){
            int count_j = 0;
            while(*(str1 + i) != 0){
                if(alphabet[a] == *(str1 + i)) count_j += 1;
                if (count_j == count_i) break;
                i += 1;
            }
            if (count_i > count_j) return false;
            
        }
        a += 1;
    }

    return true;
}

// solution 2
// iterate over each string once, count up each occurrance of a character
// into an array, then compare arrays

bool scramble2(const char *str1, const char *str2){
   int arr1[26] = {0};
   int arr2[26] = {0};

   while(*str1) arr1[(*str1++)-'a']++;
   while(*str2) arr2[(*str2++)-'a']++;

   for(int i = 0; i < 26; i++){
       if(arr2[i] > arr1[i]) return false;
   }
   return true;
}


void main() {
    char *str1 = "cedewaraaossoqqyt";
    char *str2 = "codewarks";

    printf("%s\n", scramble2(str1, str2) ? "true" : "false");
    printf("%s\n", scramble1(str1, str2) ? "true" : "false");
}