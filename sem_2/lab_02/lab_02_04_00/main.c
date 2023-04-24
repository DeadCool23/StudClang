#include <stdio.h>
#include <stdbool.h>

#define OK 0
#define ERR_COUNT 1
#define ERR_LEN 100
#define N 10

//Ввод массива
int input(int a[], size_t  *a_size);

//Сортировка массива пузырьковым методом
void bubble_sort(int a[], size_t a_size);

//Вывод массива
void print(const int a[], size_t a_size);

int main(void)
{
    int err, a[N];
    size_t n;
    err = input(a, &n);
    if (err == ERR_COUNT)
    {
        printf("Array is empty\n");
        return ERR_COUNT;
    }
    bubble_sort(a, n);
    print(a, n);
    return err;
}

int input(int a[], size_t  *a_size)
{
    printf("Input array: ");
    size_t i = 0;
    int rc, tmp;
    while (i < N && scanf("%d", &tmp) == 1)
    {
        a[i] = tmp;
        i++;
    }
    *a_size = i;
    if (i == 0)
        return ERR_COUNT;
    return scanf("%d", &rc) ? ERR_LEN : OK;
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


void print(const int a[], size_t a_size)
{
    printf("Array:\n");
    for (size_t i = 0; i < a_size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

