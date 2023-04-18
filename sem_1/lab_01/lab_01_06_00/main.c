#include <stdio.h>
#include <math.h>

#define OK 0
#define ERR_IO 1
#define ERR_RANGE -1

#define EPS 0.1e-8

#define SHARP_ANGLE 0
#define OBTUSE_ANGLE 2
#define RIGHT_ANGLE 1

//Функция считает длину вектора
double len(double x_1, double y_1, double x_2, double y_2);

//Функция вывода типа треугольника
int triangle_type(double x_a, double y_a, double x_b, double y_b, double x_c, double y_c);

//Программа определяет тип треугольника
int main(void)
{
    double x_a, y_a, x_b, y_b, x_c, y_c;
    printf("Input coordinates x_a, y_a, x_b, y_b, x_c, y_c:");
    //Проверка ввода
    if (scanf("%lf%lf%lf%lf%lf%lf", &x_a, &y_a, &x_b, &y_b, &x_c, &y_c) != 6)
    {
        printf("IO error\n");
        return ERR_IO;
    }
    int type = triangle_type(x_a, y_a, x_b, y_b, x_c, y_c);
    if (type == ERR_RANGE)
    {
        printf("Error: Not a triangle\n");
        return ERR_RANGE;
    }
    printf("Result: %d\n", type);
    return OK;
}

double len(double x_1, double y_1, double x_2, double y_2)
{
    double length = sqrt(pow(x_1 - x_2, 2) + pow(y_1 - y_2, 2));
    return length;
}

int triangle_type(double x_a, double y_a, double x_b, double y_b, double x_c, double y_c)
{
    //Векторы сторон треугольника
    double a = len(x_a, y_a, x_b, y_b);
    double b = len(x_b, y_b, x_c, y_c);
    double c = len(x_a, y_a, x_c, y_c);

    //Проверка на существование треугольника
    if (!((a + b > c) && (a + c > b) && (c + b > a)))
    {
        return ERR_RANGE;
    }

    //Поиск максимальной стороны треугольника
    double temp;
    if (b > a)
    {
        temp = a;
        a = b;
        b = temp;
    }
    if (c > a)
    {
        temp = a;
        a = c;
        c = temp;
    }

    double a_sq = a * a;
    temp = b * b + c * c;

    //Прямоугольный трегольник
    if (fabs(temp - a_sq) < EPS)
    {
        return RIGHT_ANGLE;
    }
    //Тупоугольный трегольник
    else if (temp < a_sq)
    {
        return OBTUSE_ANGLE;
    }
    //Остроугольный треугольник
    else
    {
        return SHARP_ANGLE;
    }
}
