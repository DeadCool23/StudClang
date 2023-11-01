#include "matrix_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "allocate.h"
#include "process.h"

err_t matrix_sum(const matrix_t *fst, const matrix_t *scd, matrix_t *res)
{
    if (fst->rows != scd->rows || fst->cols != scd->cols)
        return ERR_MATH;

    res->rows = fst->rows;
    res->cols = fst->cols;
    res->matrix = matrix_alloc(res->rows, res->cols);
    if (!res->matrix)
        return ERR_MEM;

    for (size_t i = 0; i < res->rows; i++)
        for (size_t j = 0; j < res->cols; j++)
            res->matrix[i][j] = fst->matrix[i][j] + scd->matrix[i][j];

    return OK;
}

err_t matrix_mult(const matrix_t *fst, const matrix_t *scd, matrix_t *res)
{
    if (fst->cols != scd->rows)
        return ERR_MATH;

    res->rows = fst->rows;
    res->cols = scd->cols;
    res->matrix = matrix_alloc(res->rows, res->cols);
    if (!res->matrix)
        return ERR_MEM;

    for (size_t i = 0; i < fst->rows; i++)
    {
        for (size_t k = 0; k < scd->cols; k++)
        {
            double sum_el = 0;
            for (size_t j = 0; j < fst->cols; j++)
                sum_el += fst->matrix[i][j] * scd->matrix[j][k];
            res->matrix[i][k] = sum_el;
        }
    }

    return OK;
}

/**
 * @brief Установка главных элементов на столбцах Гаусса
 * 
 * @param [in, out] matrix - структура матрицы
 * 
 */
static void set_leading_els(matrix_t *matrix)
{
    for (size_t i = 0; i < matrix->cols - 1; i++)
    {
        size_t max_el_row = i;
        for (size_t j = i + 1; j < matrix->rows; j++)
            if (fabs(matrix->matrix[j][i]) > fabs(matrix->matrix[max_el_row][i]))
                max_el_row = j;
        swap_rows(matrix->matrix, i, max_el_row);
    }
}

/**
 * @brief Проверка СЛАУ после метода Гаусса
 * 
 * @param [in, out] matrix - структура матрицы
 * @return Код ошибки
 */
static err_t check_slau(const matrix_t *matrix)
{
    for (size_t i = matrix->cols - 1; i < matrix->rows; i++)
        if (fabs(matrix->matrix[i][matrix->cols - 1]) > EPS)
            return ERR_MATH;
    return OK;
}

/**
 * @brief Прямой ход метода Гаусса
 * 
 * @param [in, out] matrix - структура матрицы
 * @return Код ошибки
 */
static err_t forward_elimination(matrix_t *matrix)
{
    for (size_t i = 0; i < matrix->cols - 1; i++)
    {
        if (fabs(matrix->matrix[i][i]) < EPS)
            return ERR_MATH; 
        for (size_t j = i + 1; j < matrix->rows; j++)
        {
            double div = matrix->matrix[j][i] / matrix->matrix[i][i];
            for (size_t k = i; k < matrix->cols; k++)
                matrix->matrix[j][k] -= div * matrix->matrix[i][k];
        }
    }
    return OK;
}

/**
 * @brief Преведение элементов главной диагонали к единицам 
 * 
 * @param [in, out] matrix - структура матрицы 
 */
static void main_dig_to_one(matrix_t *matrix)
{
    for (size_t i = 0; i < matrix->cols - 1; i++)
    {
        double dig_el = matrix->matrix[i][i];
        for (size_t j = i; j < matrix->cols; j++)
            matrix->matrix[i][j] /= dig_el;
    }
}

/**
 * @brief Обратный ход метода Гаусса
 * 
 * @param [in, out] matrix - структура матрицы 
 */
static void back_substitution(matrix_t *matrix)
{
    for (ssize_t i = matrix->cols - 2; i >= 0; i--)
    {
        for (ssize_t j = i - 1; j >= 0; j--) 
        {
            double factor = matrix->matrix[j][i];
            for (ssize_t k = i; k < (ssize_t)matrix->cols; k++)
                matrix->matrix[j][k] -= factor * matrix->matrix[i][k];
        }
    }
}

err_t gauss(const matrix_t *slau, matrix_t *res)
{
    // Копирование СЛАУ в локальную матрицу
    if (slau->cols <= 1 || slau->rows < slau->cols - 1)
        return ERR_MATH;
    
    matrix_t tmp = 
    {
        .cols = slau->cols,
        .rows = slau->rows,
        .matrix = matrix_alloc(slau->rows, slau->cols)
    };

    if (!tmp.matrix)
        return ERR_MEM;
    
    matrix_copy(tmp.matrix, slau);

    // Установка главных элементов на столбцах 
    set_leading_els(&tmp);

    // Прямой ход с обработкой возможности появления нулевых элементов на главной диагонали
    if (forward_elimination(&tmp))
    {
        matrix_free(tmp.matrix, tmp.rows);
        return ERR_MATH;
    }

    // Приведение элементов главной диагонали к единичному виду
    main_dig_to_one(&tmp);

    // Обратный ход
    back_substitution(&tmp);

    // Проверка на то что матрица линейна независима
    if (check_slau(&tmp))
    {
        matrix_free(tmp.matrix, tmp.rows);
        return ERR_MATH;
    }

    // Запись свободных членов(решений) в вектор-столбец
    res->rows = tmp.cols - 1;
    res->cols = RES_MATRIX_COLS;
    res->matrix = matrix_alloc(res->rows, res->cols);

    if (!res->matrix)
    {
        matrix_free(tmp.matrix, tmp.rows);
        return ERR_MEM;
    }

    for (size_t i = 0; i < tmp.cols - 1; i++)
        res->matrix[i][0] = tmp.matrix[i][tmp.cols - 1];

    // Освобождение памяти из под локальной СЛАУ
    matrix_free(tmp.matrix, tmp.rows);

    return OK;
}
