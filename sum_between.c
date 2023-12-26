#include <stdio.h>

/*
function takes in two integers and sums every integer that falls between them
along with the integers themselves. order non-dependent.
if two of the same integers are passed, no sum is done and that integer is returned
*/

int get_sum(int a , int b) {
    if (a == b) return a;
    int sum = a;
    int high = b;

    if (a > b) {
        high = a;
        sum = b;
    }

    int i = sum + 1;
    while (i <= high) {
        sum += i;
        i += 1;
    }

    return sum;
}

void main() {

    printf("%d\n", get_sum(5 , -1));    // 14
    printf("%d\n", get_sum(505 , 4));   // 127759
    printf("%d\n", get_sum(-50 , 0));   // -1275
    printf("%d\n", get_sum(321 , 123)); // 44178
    printf("%d\n", get_sum(-1 , -5));   // -15
    printf("%d\n", get_sum(-5 , -5));   // -5
    printf("%d\n", get_sum(-504 , 4));  // -127250
    printf("%d\n", get_sum(7 , 8));  // 15

}