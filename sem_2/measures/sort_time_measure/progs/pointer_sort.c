#include <stdio.h>
#include <stdbool.h>
#include "libs/time_clac.h"
#include "libs/errs.h"
#include "libs/matrix_generator.h"

int array[N];
size_t n;

void bubble_sort(int *point_beg, int *point_end);

int main(int argc, char **argv)
{
    if (argc < 2)
        return ERR_ARGS_CNT;
    if (sscanf(argv[1], "%zu", &n) != 1)
        return ERR_ARG;

#ifdef RAND
random_matrix(n, array);
#endif /* RAND */

#ifdef SORT
sorted_matrix(n, array);
#endif /* SORT */

    int *point_beg = array;
    int *point_end = array + sizeof(array) / sizeof(int);

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

