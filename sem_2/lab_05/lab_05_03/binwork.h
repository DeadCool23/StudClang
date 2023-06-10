#ifndef BINWORK_H
#define BINWORK_H

#include <stdio.h>

/**
 * @brief Функция ввода чисел в бинарный файл
 * @param[in,out] f - файловая переменная
 * @param[in] cnt - кол-во записываемых чисел
 * @return Код ошибки
 */
int fb_write_nums(FILE *f, size_t cnt);

/**
 * @brief Процедура вывода чисел из двоичного файла
 * @param[in] f - файловая переменная
 * @return Код ошибки
 */
int fb_print(FILE *f);

/**
 * @brief Функция сортировки элементов бинарного файла
 * @param[in,out] f - файловая переменная
 * @return Код ошибки
 */
int fb_sort(FILE *f);

#endif //BINWORK_H
