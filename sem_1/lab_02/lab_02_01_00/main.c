#include <stdio.h>

#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2
#define ERR_COUNT 3

#define N 10
#define ZERO_SUM 5 //Код возврата функции поиска суммы при отсутствии соответствующих элементов
#define EVEN_BIT 1 //Бит четности

//Ввод массива
int input(int a[], size_t *a_size);

//Поиск суммы четных элементов
int sum_even(const int a[], size_t a_size, int *sum);

int main(void)
{
    int a[N];
    size_t n;
    int err = input(a, &n); //Ввод массива
    //Проверка на наличие ошибок
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
    int sum = 0;
    err = sum_even(a, n, &sum); //Счет суммы четных элементов
    //Проверка на наличие четных элементов
    if (err == ZERO_SUM)
    {
        printf("No even nums");
        return ERR_COUNT;
    }
    printf("Sum of even array elements: %d", sum);
    return OK;
}

//Функция ввода массива с его длинной
int input(int a[], size_t *a_size)
{
    int n;
    printf("Input n: ");
    if (scanf("%d", &n) != 1)
    {
        return ERR_IO;
    }

    //Проверка диапозона размера массива
    if (n <= 0 || n > N)
    {
        return ERR_RANGE;
    }

    //Ввод массива
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

//Функция поиска суммы четных элементов
int sum_even(const int a[], size_t a_size, int *sum)
{
    int count = 0;
    for (size_t i = 0; i < a_size; i++)
    {
        //Проверка на четность
        if ((a[i] & EVEN_BIT) == 0)
        {
            *sum += a[i];
            count++;
        }
    }
    return count == 0 ? ZERO_SUM : OK;
}

