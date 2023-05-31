#include <stdio.h>
#include <stdbool.h>
#include "libs/time_clac.h"
#include "libs/errs.h"
#include "libs/matrix_generator.h"

int array[N];
size_t n;

/**
 * @brief Сортировка пузырьком с флагом
 * @details Обращение к элементу методом индексации
 * @param[in,out] a - массив
 * @param[in] a_size - размер массива 
 */
void bubble_sort(int a[], size_t a_size);

int main(int argc, char **argv)
{
    if (argc < 2)
        return ERR_ARGS_CNT;
    if (sscanf(argv[1], "%zu", &n) != 1)
        return ERR_ARG;

/**
 * @def RAND
 * Макрос создания рандомного массива
 */
#ifdef RAND
random_matrix(n, array);
#endif /* RAND */

/**
 * @def SORT
 * Макрос создания отсортированного массива
 */
#ifdef SORT
sorted_matrix(n, array);
#endif /* SORT */

    unsigned long long beg, end, elapsed_time;
    
    beg = microseconds_now();
    bubble_sort(array, sizeof(array) / sizeof(int));
    end = microseconds_now();
    
    elapsed_time = end - beg; /// Получение времени выполнения
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

