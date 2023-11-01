#ifndef __MATRIX_IO__
#define __MATRIX_IO__

#include <stdbool.h>
#include <stdio.h>

#include "errs.h"
#include "matrix_struct.h"

/**
 * @brief Функция проверки окончания файла
 * @details Функция проверяет наличие `\n` в конце файла
 *
 * @param [in] file
 * @return true - конец файла
 * @return false - не конец файла
 */
bool is_eof(FILE *file);

/**
 * @brief Функция считывания элементов матрицы из файла
 * @details Матрица в файле хранится в координатном виде
 *
 * @param [in, out] f - файловая переменная
 * @param [in, out] matrix - матрица
 * @return ошибка
 */
err_t matrix_read(FILE *f, const matrix_t *matrix);
/**
 * @brief Функция считывания матрицы из файла
 * @details Функция выделяет память под матрицу
 * @details Матрица в файле хранится в координатном виде
 *
 * @param [in, out] f - файловая переменная
 * @param [out] matrix - матрица
 * @return ошибка
 */
err_t matrix_create(FILE *f, matrix_t *matrix);
/**
 * @brief Функция считывания матрицы из файла с заданным названием
 *
 * @param [in] filename - название файла считывания
 * @param [in, out] matrix - матрица
 * @return ошибка
 */
err_t matrix_create_ex(const char *filename, matrix_t *matrix);

/**
 * @brief Запись матрицы в файл
 * @details Запись в простом формате
 *
 * @param [in, out] file - файловая переменная
 * @param [in] matrix - матрица
 */
void matrix_print(FILE *file, const matrix_t *matrix);

#endif  //__MATRIX_IO__

