#include <stdio.h>

// adds up the sum of the digits in any int, and keeps adding them up until they are a single digit
// example 79
// 7 + 9 = 16
// 1 + 6 = 7

int digital_root(int n) {
    if (n < 10) return n;
    int a = n / 10;
    int b = n % 10;
    return digital_root(a + b);
}

void main() {

    printf("%d\n", digital_root(299));

}