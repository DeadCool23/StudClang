#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <inttypes.h>

#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2

#define BIT_COUNT (sizeof(uint32_t) * CHAR_BIT)

//Функция циклического сдвига вправо
uint32_t to_right_circle(uint32_t num, int n);

//Ввод данных
int input(uint32_t *a, int *n);

//Процедура вывода числа в бинарном виде
void bin_out(uint32_t num);

int main(void)
{
    uint32_t a;
    int n;
    int err = input(&a, &n);
    if (err != OK)
        return err;
    uint32_t ans = to_right_circle(a, n); //Сдвиг числа
    bin_out(ans); //Вывод числа в дыоичном виде
    return OK;
}

uint32_t to_right_circle(uint32_t num, int n)
{
    for (int i = 0; i < n; i++)
    {
        uint32_t tmp = num & 1;
        num = (num >> 1) | (tmp << (BIT_COUNT - 1));
    }
    // num = (num >> n) | (num << (BIT_COUNT - n)); - решение в одну строчку
    return num;
}

int input(uint32_t *a, int *n)
{
    printf("Input a, n: ");
    //Проверка корректности ввода
    if (scanf("%" SCNu32 "%d", a, n) != 2)
    {
        printf("Error: Incorrect input\n");
        return  ERR_IO;
    }
    //Проверка диапазона числа n
    if (*n < 0)
    {
        printf("Error: n is negative\n");
        return ERR_RANGE;
    }
    return OK;
}

void bin_out(uint32_t num)
{
    printf("Result: ");
    for (size_t i = 1; i <= BIT_COUNT; i++)
    {
        printf("%" PRIu32, (num >> (BIT_COUNT - i)) & 1);
    }
    printf("\n");
}
