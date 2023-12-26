#include <stdlib.h>
#include <stdio.h>

char *alphabet_position(const char *text) {
    int i = 0;
    int m = 0;
    char *output = malloc(m);
    
    while(1){
        if(*(text + i) >= 65 && *(text + i) <= 122) {
            int offset;
            if(*(text + i) <= 90) offset = 64;
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
        i += 1;
        if(*(text + i) == 0) {
            output[m-1] = 0;
            break;
        }
    }

    return output;
}

void main() {
    printf("%s\n", alphabet_position("whiz"));
}