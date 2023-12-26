#include <stdlib.h>
#include <stdio.h>

/*
function sorts all the odd numbers in an array from lowest to highest
while leaving the even numbers alone. 
*/

void print_arr(size_t n, int arr[n]){
    printf("[");
    size_t i = 0;
    while (i < n - 1){
        printf("%d, ", arr[i]);
        i+=1;
    }
    printf("%d]\n", arr[n - 1]);

}


void sort_array(size_t n, int arr[n]) {
    int i = 0;
    int j = (int) n;

    while (j > 0) {
        if (arr[i] % 2 != 0) {
            int c = i + 1;
            while(c <= j) {
                if (arr[c] % 2 != 0) {
                    if (arr[i] > arr[c]){
                        int swap = arr[i];
                        arr[i] = arr[c];
                        arr[c] = swap;
                    } 
                    i = c;
                } 
                c += 1;
            }
            i = 0;
            j -= 1;

        } else {
            i += 1;
        }
    }
}


void main() {

    int arr1[] = {11, 1, 11, 11, 2, 1, 111, 0};
    int arr2[] = {5, 3, 1, 8, 0};
    int arr3[] = {6, -42, 17, -41, 29, 35, -37, -13};

    size_t size1 = 8;
    size_t size2 = 5;
    size_t size3 = 8;

    print_arr(size1, arr1);
    sort_array(size1, arr1);
    print_arr(size1, arr1);
    printf("\n");
    print_arr(size2, arr2);
    sort_array(size2, arr2);
    print_arr(size2, arr2);
    printf("\n");
    print_arr(size3, arr3);
    sort_array(size3, arr3);
    print_arr(size3, arr3);


}
