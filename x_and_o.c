#include <stdbool.h>
#include <stdio.h>

/*
function takes in a string and counts the number of Xs and Os (case insensitive)
and returns true if there is an even number of both, or false otherwise.
*/

bool xo (const char* str)
{
    int x = 0;
    int o = 0;
    int i = 0;

    while (*(str + i) != 0){
        if(*(str + i) == 79 || *(str + i) == 111) o++;
        if(*(str + i) == 88 || *(str + i) == 120) x++;
        i++;
    }
    if (x == o) return true;
    return false;
}

void main() {

    if(xo("xxoo")) printf("true\n");
    else printf("false\n");

}