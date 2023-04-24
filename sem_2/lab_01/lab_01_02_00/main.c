// Нисуев Нису ИУ7-22Б Вариант 0
//Подсчет периметра р/б трапиции

#include <stdio.h>
#include <math.h>

// Программа считает периметр р/б трапеции
int main(void)
{
    double a, b, h;
    printf("Input a,b,h: ");
    scanf("%lf%lf%lf", &a, &b, &h);
    double c = sqrt((fabs(a - b) / 2) * (fabs(a - b) / 2) + h * h); // Вычисление ребер
    double p = a + b + 2 * c; // Вычисление периметра
    printf("Perimetr of trapezoid Р = %.6lf\n", p);
    return 0;
}
