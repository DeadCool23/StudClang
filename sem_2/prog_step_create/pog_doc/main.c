/**
 * @mainpage Документация к программе
 * 
 * Программа для поиска самой частоповторяющейся цифры матрицы
 * 
 * Автор: Нисуев Нису ИУ7-22Б
 */

/*! @page Допущения 
 *
 * Это страница о допущениях в работе программы
 * - @ref Размеры матриц беззнаковые целые числа
 * - @ref Матрица состоит из целых чисел
 * - @ref Размер матрицы не больше 10х10
 * - @ref Элементы матрицы разделяются произвольным числом пробелов
 * - @ref Размер элементов матрицы ограничен целым типом
 * - @ref Если самых частовстречающихся цифр несколько берем минимальное
 */

/**
 * @file main.c
 * @author Нисуев Нису ИУ7-22Б
 * @brief Программа ищет самую частовстречающуюся цифру в матрице
 */
#include <stdio.h>
#include "errcodes.h"
#include "matrixio.h"
#include "pop_digit.h"
#include "testing.h"

int main(void)
{
    int n, m;
    int matrix[N][M];
    func_test();
    printf("Input size of matrix: ");
    if (scanf("%d%d", &n, &m) != 2)
    {
        printf("Size input error\n");
        return ERR_IO;
    }
    if ((n <= 0 || n > N) || (m <= 0 || m > M))
    {
        printf("Size range error\n");
        return ERR_SIZE;
    }
    int rc = matrix_els(matrix, n, m);
    if (rc != OK)
    {
        if (rc == ERR_IO)
        {
            printf("Matrix input error\n");
            return ERR_IO;
        }
    }

    int dig_arr[DIG_COUNT] = {0};
    digit_count(matrix, n, m, dig_arr);
    int popular_digit = freq_digit(dig_arr);
    printf("The most frequent digit: %d", popular_digit);
    return OK;
}
