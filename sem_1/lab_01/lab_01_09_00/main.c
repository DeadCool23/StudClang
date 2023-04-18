#include <stdio.h>
#include <math.h>

#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2

//Суммирование элементов
void summator(double *sum, double x, int i);

//Функция поиска значения функции
int get_funct(double *g);

int main(void)
{
    double g;
    int err = get_funct(&g);
    if (err != OK)
    {
        if (err == ERR_IO)
        {
            printf("IO Error\n");
            return err;
        }
        if (err == ERR_RANGE)
        {
            printf("Error: first element can't be negative");
            return err;
        }
    }
    printf("g(x) = %.6lf", g);
    return OK;
}

void summator(double *sum, double x, int i)
{
    *sum += x / i;
}

int get_funct(double *g)
{
    double x, sum = 0;
    int i = 1;
    printf("Input x%d:", i);
    //Проверка правильности ввода 1-ого элемента
    if (scanf("%lf", &x) != 1)
    {
        return ERR_IO;
    }

    //Проверка первого элемента
    if (x < 0)
    {
        return ERR_RANGE;
    }

    while (x >= 0)
    {
        summator(&sum, x, i);
        i++;
        printf("Input x%d:", i);
        //Проверка правильности ввода i-ого элемента
        if (scanf("%lf", &x) != 1)
        {
            return ERR_IO;
        }
    }
    *g = sqrt(sum);
    return OK;
}
