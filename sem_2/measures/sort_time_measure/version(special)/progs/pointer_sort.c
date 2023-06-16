#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>

#define OK 0

unsigned long long microseconds_now(void);
void bubble_sort(int *point_beg, int *point_end);
int arr[] = {};

int main(void)
{
    int *point_beg = arr;
    int *point_end = arr + sizeof(arr) / sizeof(int);
    unsigned long long beg, end, elapsed_time;
    beg = microseconds_now();
    bubble_sort(point_beg, point_end);
    end = microseconds_now();
    elapsed_time = end - beg;
    printf("%llu\n", elapsed_time);
    return OK;
}

void bubble_sort(int *point_beg, int *point_end)
{
    int *point_i = point_beg;
    int *point_j = point_beg;
    bool swapped = true;
    while (point_i < point_end - 1 && swapped)
    {
        swapped = false;
        while (point_j < point_end - (point_i - point_beg) - 1)
        {
            if (*point_j > *(point_j + 1))
            {
                int temp = *point_j;
                *point_j = *(point_j + 1);
                *(point_j + 1) = temp;
                swapped = true;
            }
            point_j++;
        }
        point_i++;
        point_j = point_beg;
    }
}

unsigned long long microseconds_now(void)
{
    struct timeval val;

    if (gettimeofday(&val, NULL))
        return (unsigned long long) -1;

    return val.tv_sec * 1000ULL * 1000ULL + val.tv_usec;
}

