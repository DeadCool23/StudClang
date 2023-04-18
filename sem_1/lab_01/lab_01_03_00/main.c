#include <stdio.h>
#include <math.h>

#define SM_CONVERT 100
/*Программа считает нормальный вес человека и его индекс веса 
по введенным с клавиатуры данным*/
int main(void)
{
    //Блок ввода
    double h, t, m;
    printf("Input person's height (in sm), chest circumference(in sm), weight(in kg): ");
    scanf("%lf%lf%lf", &h, &t, &m);
    double m_norm, bmi;
    m_norm = (h * t) / 240; //Счет нормального веса
    bmi = m / pow((h / SM_CONVERT), 2); //Счет индекса массы человека
    printf("Person's normal weight = %.6lf\nHuman mass index BMI = %.6lf\n", m_norm, bmi);
    return 0;
}
