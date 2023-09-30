#ifndef SUBJECT_H
#define SUBJECT_H

#include <stdbool.h>
#include <stdio.h>

#include "errs.h"

/// @def SUBJECT_NAME_LEN - максимальный размер имени продукта
#define SUBJECT_NAME_LEN 25

/// @struct subject_t - структура объекта
/// @details хранит имя, вес и плотность
typedef struct
{
    char name[SUBJECT_NAME_LEN + 1];
    double weight;
    double volume;
} subject_t;

/**
 * @brief Функция считывания структуры из файла
 *
 * @param [in] file - файл со структурами
 * @param [out] ptr_subj - считываемый объект
 * @return Ошибка
 */
err_t subject_read(FILE *file, subject_t *ptr_subj);

/**
 * @brief Функция записи структуры в файл
 *
 * @param [out] file - файл для записи
 * @param [in] ptr_subj - записываеммый объект
 * @return Ошибка
 */
err_t subject_print(FILE *file, const subject_t *ptr_subj);

/**
 * @brief Функция поиска подстроки в начале названия объекта
 *
 * @param [in] ptr_subj - объект для поиска подстроки
 * @param [in] substr - подстрока
 * @return true - подстрока расположена в начале названия объекта
 * @return false - подстрока не в начале названия объекта или отсутствует в назании в целом
 */
bool substr_search_in_name(const subject_t *ptr_subj, const char *substr);

/**
 * @brief Функция подсчета плотности объекта
 *
 * @param [in] ptr_subj - объект
 * @return Плотность
 */
double subject_density_calc(const subject_t *ptr_subj);

#endif  // SUBJECT_H
