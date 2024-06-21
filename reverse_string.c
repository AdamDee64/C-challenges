#include <stdio.h>

// a function that prints out a given string in reverse order.

void reverse_string(char *str) {
    int i = 0;
    while(str[i++]);
    while(i) printf("%c", str[i--]);
    printf("%c\n", str[i]);
}

int main(void) {

    char *str = "Hello, /g/entlemen.";

    reverse_string(str);

    return 0;
}