#include <stdio.h>

#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2

//Функция для возведения заданного числа в заданную степень
int deg(int a, int n)
{
    int a_n = 1;
    for (int i = 0; i < n; i++)
    {
        a_n *= a;
    }
    return a_n;
}

int main(void)
{
    int a, n;
    printf("Input a,n: ");
    //Проверка ввода
    if (scanf("%d%d", &a, &n) != 2)
    {
        printf("IO error\n");
        return ERR_IO;
    }
    if (n <= 0)
    {
        printf("Error: n is negative\n");
        return ERR_RANGE;
    }
    int ans = deg(a, n); //Присваивание значения ф-ции переменной
    printf("a^n = %d", ans);
    return OK;
}
