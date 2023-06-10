#ifndef BINWORK_H
#define BINWORK_H

#include <stdio.h>
#include "stud.h"

/**
 * @brief Функция получения студента из заданной позиции бинарного файла 
 * @param[in] f - файловая переменная
 * @param[in] pos - позиция студента
 * @param[out] stud - студент
 * @return Код ошибки
 */
int fb_get_by_pos(FILE *f, long pos, stud_t *stud);

/**
 * @brief Функция записи студента на заданную позицию бинарного файла 
 * @param[in,out] f - файловая переменная
 * @param[in] pos - позиция студента
 * @param[in] stud - студент
 * @return Код ошибки
 */
int fb_put_by_pos(FILE *f, long pos, const stud_t *stud);

/**
 * @brief Функция перестановки студентов в бинарном файле
 * @param[in,out] f - файловая переменная
 * @param[in] ind_fst - позиция переставляемого студента
 * @param[in] num_fst - переставляемое студент
 * @param[in] ind_scd - позиция перестановки
 * @param[in] num_scd - студент перестановки
 * @return Код ошибки
 */
int bswap_studs(FILE *f, long ind_fst, long ind_scd, const stud_t *stud_fst, const stud_t *stud_scd);

/**
 * @brief Функция получения количества студентов в бинарном файле
 * @param[in] f - файловая переменная
 * @param[out] num_cnt - кол-во студентов
 * @return Код ошибки
 */
int get_stud_num(FILE *f, long *num_cnt);

/**
 * @brief Сортировка студентов по алфавиту
 * @details Сортировка: пузырек с флагом
 *
 * @param[in,out] f - файловая переменная
 * @return Код ошибки
 */
int fb_sort_by_fullname(FILE *f);

#endif //BINWORK_H
