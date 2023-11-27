#ifndef SUBJECT_H
#define SUBJECT_H

#define _GNU_SOURCE

#include <stdbool.h>
#include <stdio.h>

#include "errs.h"

/// @struct subject_t - структура объекта
/// @details хранит имя, вес и плотность
typedef struct
{
    char *name;
    double weight;
    double volume;
} subject_t;

/**
 * @brief Фуункция инициализации объекта
 * 
 * @param [out] subj - Объект инициализации
 * @param [in] name - имя
 * @param [in] weight - вес
 * @param [in] volume - плотность
 * @return Ошибка 
 */
err_t subj_init(subject_t *subj, const char *name, double weight, double volume);
/**
 * @brief Функция копирования объекта
 * 
 * @param [out] dst - Объект куда копируют 
 * @param [in] src - Копируемый объект
 * @return Код ошибки
 */
err_t subj_cpy(subject_t *dst, const subject_t *src);
/**
 * @brief Функция очитки динамической памяти в структуре объекта
 * 
 * @param [in, out] subj - Объект
 */
void free_subj(subject_t *subj);

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
 * @brief Функция сравнения двух объектов
 * 
 * @param [in] left - левый объект
 * @param [in] right - правый объект
 * @return < 0 если правая плотность больше 
 * @return = 0 если плотности равны 
 * @return > 0 если левая плотность больше 
 */
int subjs_cmp(const subject_t *left, const subject_t *right);

/**
 * @brief Функция подсчета плотности объекта
 * @details Данные в функцию подаются корректными
 * 
 * @param [in] ptr_subj - объект
 * @return Плотность
 */
double subject_density_calc(const subject_t *ptr_subj);

#endif  // SUBJECT_H
