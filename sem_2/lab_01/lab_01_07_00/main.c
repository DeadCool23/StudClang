#include <stdio.h>
#include <math.h>

#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2

//Функция счета ряда Маклорена с учетом погрешности
double macloren(double eps, double x)
{
    double temp = 1;
    double sum = 1, i = 1;
    while (fabs(temp) >= eps)
    {
        temp = temp * x / i;// i элемент ряда
        sum += temp;
        i++;
    }
    return sum; //Значение ряда
}

int main(void)
{
    double x, eps;
    printf("Input x, eps: ");
    //Проверка на ввод
    if (scanf("%lf%lf", &x, &eps) != 2)
    {
        printf("IO error\n");
        return ERR_IO;
    }
    //Проверка диапазона точности
    if (eps <= 0 || eps > 1)
    {
        printf("Error: eps is out of range\n");
        return ERR_RANGE;
    }
    double f = exp(x); //Поиск значения заданной функции
    double s = macloren(eps, x); //Значение заданной функции посчитанное рядом Маклорена

    double delt = fabs(f - s); //абсолютная погрешность
    double rel = delt / fabs(f); //относительная погрешность
    printf("s(x) = %.6lf\nf(x) = %.6lf\nabs = %.6lf\nrel = %.6lf", s, f, delt, rel);
    return OK;
}
