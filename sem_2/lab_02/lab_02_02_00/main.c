#include <stdio.h>

#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2
#define ERR_COUNT 3
#define N 10

//Ввод массива
int input(int a[], size_t *a_size);

//Функция поиска среднего значения
double average(const int a[], size_t n);

//Функция создания нового массива из элементов больше среднего значения
size_t average_array(const int a[], int new[], size_t arr_size);

//Вывод массива
void print(const int a[], size_t a_size);

int main(void)
{
    int a[N];
    size_t n;
    int err = input(a, &n); //Ввод массива
    //Проверка ошибок
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
    int new[N];
    size_t new_size = average_array(a, new, n);
    if (new_size == 0)
    {
        printf("No nums great then average\n");
        return ERR_COUNT;
    }
    print(new, new_size);
    return OK;
}

int input(int a[], size_t *a_size)
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

double average(const int a[], size_t n)
{
    double sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += a[i];
    return sum / (int) n;
}

size_t average_array(const int a[], int new[], size_t arr_size)
{
    double av = average(a, arr_size);
    size_t j = 0;
    for (size_t i = 0; i < arr_size; i++)
    {
        if (a[i] > av)
        {
            new[j] = a[i];
            j++;
        }
    }
    return j;
}

void print(const int a[], size_t a_size)
{
    printf("Array:\n");
    for (size_t i = 0; i < a_size; i++)
        printf("%d ", a[i]);
    printf("\n");
}
