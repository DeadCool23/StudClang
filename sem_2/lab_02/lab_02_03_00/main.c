#include <stdio.h>
#include <stdbool.h>

#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2
#define ERR_COUNT 3
#define N 10

//Ввод массива
int input(int a[], size_t  *a_size);

//Проверка числа на полендромность
bool palendrom(int num);

//Функция удаления палендромов
void delete_palendrom(int a[], size_t  *a_size);

//Вывод массива
void print(const int a[], size_t a_size);

//Удаление элемента по индексу
void delete_by_index(int arr[], size_t *n, size_t index);

int main(void)
{
    int err, a[N];
    size_t n;
    err = input(a, &n);
    if (err != OK)
    {
        if (err == ERR_IO)
        {
            printf("IO Error\n");
            return ERR_IO;
        }
        if (err == ERR_RANGE)
        {
            printf("Length is out of range\n");
            return ERR_RANGE;
        }
    }
    delete_palendrom(a, &n);
    if (n == 0)
    {
        printf("All nums palendroms\n");
        return ERR_COUNT;
    }
    print(a, n);
    return OK;
}

int input(int a[], size_t  *a_size)
{
    int n;
    printf("Input n: ");
    if (scanf("%d", &n) != 1)
    {
        return ERR_IO;
    }
    if (n <= 0 || n > N)
    {
        return ERR_RANGE;
    }

    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &a[i]) != 1)
        {
            return ERR_IO;
        }
    }
    *a_size = (size_t) n;
    return OK;
}

bool palendrom(int num)
{
    int num_copy = num, rev_num = 0;
    if (num == 0)
        return false;
    if (num > 0)
    {
        while (num != 0)
        {
            rev_num = rev_num * 10 + num % 10;
            num /= 10;
        }
    }
    return num_copy == rev_num ? true : false;
}

void delete_palendrom(int a[], size_t  *a_size)
{
    size_t i = 0;
    while (i < *a_size)
    {
        if (palendrom(a[i]))
            delete_by_index(a, a_size, i);
        else
            i++;
    }
}

void print(const int a[], size_t a_size)
{
    printf("Array:\n");
    for (size_t i = 0; i < a_size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// Функция удаления по индексу
void delete_by_index(int arr[], size_t *n, size_t index)
{
    for (size_t i = index; i < *n - 1; i++)
        arr[i] = arr[i + 1];
    (*n)--;
}
