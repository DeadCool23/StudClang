#include "fibonacci.h"

void fill_fibonacci(int *arr, size_t n) {
    int current = 0, next = 1;
    for (size_t i = 0; i < n; i++) {
        arr[i] = current;
        current = next;
        next = current + arr[i];
    }
}
