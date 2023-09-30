#ifndef SUBJ_ARR_H
#define SUBJ_ARR_H

#include "errs.h"
#include "subject.h"
#include <stddef.h>
#include <stdio.h>

/// @def N - Максимальное кол-во структур
#define N 15

/// @def TO_SORT - строка вызова сортировки структур
#define TO_SORT "__SORT_STRUCTS__"

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
 * @brief Функция считывания структур из файла в массив
 * 
 * @param [in] file - файл со структурами
 * @param [out] subjects - массив структур
 * @param [in] n_max - максимальное кол-во структур
 * @param [out] subjs_cnt - кол-во считанных структур
 * @return Ошибка
 */
err_t subjects_read(FILE *file, subject_t *subjects, const size_t n_max, size_t *subjs_cnt);

/**
 * @brief Функция записи всех структур в файл
 * 
 * @param [out] file - файл для записи
 * @param [in] subjects - массив структур
 * @param [in] subjs_cnt - кол-во структур
 * @return Ошибка
 */
err_t subjects_print_all(FILE *file, const subject_t *subjects, const size_t subjs_cnt);

/**
 * @brief Функция записи структур в файл с определенной подстрокой в названии
 * 
 * @param [out] file - файл для записи
 * @param [in] subjects - массив структур
 * @param [in] subjs_cnt - кол-во структур
 * @param [in] substr - искомая подстрока
 * @return Ошибка
 */
err_t subjects_print_with_substr(FILE *file, const subject_t *subjects, const size_t subjs_cnt, const char *substr);

/**
 * @brief Функция записи структур с заданной опцией в файл
 * 
 * @param [out] file - файл для записи
 * @param [in, out] subjects - массив структур
 * @param [out] subjs_cnt - кол-во структур
 * @param [in] option - опция записи
 * @return Ошибка
 */
err_t subjects_print_by_option(FILE *file, subject_t *subjects, const size_t subjs_cnt, const char *option);

/**
 * @brief Процедура сортровки структур по возрастанию плотности
 * @details Сортировка пузырек с флагом (Усстойчивый алгоритм)
 * 
 * @param [in, out] subjects - массив структур
 * @param [in] subjs_cnt - кол-во структур
 */
void subject_sort_by_density(subject_t *subjects, const size_t subjs_cnt);

#endif // SUBJ_ARR_H
