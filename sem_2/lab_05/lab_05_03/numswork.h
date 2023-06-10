#ifndef NUMSWORK_H
#define NUMSWORK_H

#include <stdio.h>
#include <stdint.h>

/**
 * @brief Функция генерации случайного числа
 * @return Число
 */
int num_generate(void);

/**
 * @brief Функция получения числа из заданной позиции бинарного файла 
 * @param[in] f - файловая переменная
 * @param[in] pos - позиция числа
 * @param[out] num - число
 * @return Код ошибки
 */
int get_number_by_pos(FILE *f, long pos, int32_t *num);

/**
 * @brief Функция записи числа на заданную позицию бинарного файла 
 * @param[in,out] f - файловая переменная
 * @param[in] pos - позиция числа
 * @param[in] num - число
 * @return Код ошибки
 */
int put_number_by_pos(FILE *f, long pos, int32_t num);

/**
 * @brief Функция перестановки чисел в бинарном файле
 * @param[in,out] f - файловая переменная
 * @param[in] ind_fst - позиция переставляемого числа
 * @param[in] num_fst - переставляемое число
 * @param[in] ind_scd - позиция перестановки 
 * @param[in] num_scd - число перестановки
 * @return Код ошибки
 */
int bswap_nums(FILE *f, long ind_fst, long ind_scd, int32_t num_fst, int32_t num_scd);

#endif //NUMSWORK_H
