#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>

#define OK 0

unsigned long long microseconds_now(void);
void bubble_sort(int a[], size_t a_size);
int arr[] = {};

int main(void)
{
    unsigned long long beg, end, elapsed_time;
    beg = microseconds_now();
    bubble_sort(arr, sizeof(arr) / sizeof(int));
    end = microseconds_now();
    elapsed_time = end - beg;
    printf("%llu\n", elapsed_time);
    return OK;
}

void bubble_sort(int a[], size_t a_size)
{
    size_t i, j;
    bool swapped = true;
    for (i = 0; i < a_size - 1 && swapped; i++)
    {
        swapped = false;
        for (j = 0; j < a_size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = true;
            }
        }
    }
}

unsigned long long microseconds_now(void)
{
    struct timeval val;

    if (gettimeofday(&val, NULL))
        return (unsigned long long) -1;

    return val.tv_sec * 1000ULL * 1000ULL + val.tv_usec;
}
