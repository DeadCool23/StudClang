#ifndef SUBJ_ARR_H
#define SUBJ_ARR_H

#include "errs.h"
#include "subject.h"
#include <stddef.h>
#include <stdio.h>

typedef int (*compare_t)(const subject_t*, const subject_t*);

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
 * @brief Функция подсчета кол-ва структур в файле
 * 
 * @param [in, out] file - файл со структурами 
 * @param [out] subjs_cnt - кол-во структур 
 * @return err_t 
 */
err_t subjects_cnt(FILE *file, size_t *subjs_cnt);
/**
 * @brief Функция считывания структур из файла в массив
 * 
 * @param [in, out] file - файл со структурами
 * @param [out] subjects - массив структур
 * @param [in] subjs_cnt - кол-во считанных структур
 * @return Ошибка
 */
err_t subjects_read(FILE *file, subject_t *subjects, size_t subjs_cnt);
/**
 * @brief Функция считывания структур из файла
 * @details Функция выделяет память под массив структур
 *
 * @param [in, out] file - файловая переменная
 * @param [out] subjects - массив структур
 * @param [out] subjs_cnt - кол-во считанных структур
 * @return ошибка
 */
err_t subjects_create(FILE *file, subject_t **subjects, size_t *subjs_cnt);
/**
 * @brief Функция считывания массива структур из файла с заданным названием
 *
 * @param [in] filename - название файла считывания
 * @param [out] subjects - массив структур
 * @param [out] subjs_cnt - кол-во структур в массиве
 * @return ошибка
 */
err_t subjects_create_ex(const char *filename, subject_t **subjects, size_t *subjs_cnt);

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
 * @brief Сортровка массива структур по возрастанию их плотностей
 * @details Сортировка пузырек с флагом (Усстойчивый алгоритм)
 * 
 * @param [in, out] subjects - массив структур
 * @param [in] subjs_cnt - кол-во структур
 * @param [in] el_cmp - функция сравнения элементов
 */
void subjects_sort_by_density(subject_t *subjects, const size_t subjs_cnt, compare_t el_cmp);

/**
 * @brief Функция очистки динамического массива динамических структур структур
 * 
 * @param [in, out] subjects - Массив структур
 */
void free_subjs(subject_t *subjects, const size_t subjs_cnt);

#endif // SUBJ_ARR_H
