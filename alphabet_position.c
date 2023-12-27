#include <stdlib.h>
#include <stdio.h>

/*
takes in a string and returns a new string of numbers representing 
the letter's position in the alphabet (1-26) separated by spaces.
Case insensitive, ignores non-letter characters.
*/ 

char *alphabet_position(const char *text) {
    int i = 0;
    int m = 0;
    char *output = malloc(m);

    while(1){
        if(*(text + i) >= 65 && *(text + i) <= 122) {
            int offset = 64;
            if(*(text + i) <= 90 || *(text + i) >= 97) {
                if(*(text + i) >= 97) offset = 96;
                if(*(text + i) - offset < 10){
                    m+=2;
                    output = realloc(output, m);
                    output[m-2] = *(text + i) - offset + 48;
                } else {
                    m+=3;
                    output = realloc(output, m);
                    output[m-3] = (*(text + i) - offset) / 10 + 48;
                    output[m-2] = (*(text + i) - offset) % 10 + 48;
                }
                output[m-1] = 32;
            }

        }
        i += 1;
        if(*(text + i) == 0) {
            output[m-1] = 0;
            break;
        }
    }

    return output;
}

void main() {
    char *str = alphabet_position("abc {} [lmnop]^ X Y Z");
    printf("%s\n", str);
    free(str);
}