#ifndef STUD_ARR_H
#define STUD_ARR_H

#include <bits/types/FILE.h>
#include <stdio.h>
#include "stud.h"

#define STUD_COUNT 20

/**
 * @brief Функция вывода студентов
 * @param[out] students - массив студентов
 * @param[out] studs_cnt - кол-во студентов
 * @param[in] stud_file - файл
 */
int get_students(FILE *stud_file, stud_t *students, size_t *studs_cnt);

/**
 * @brief Процедура вывода студентов, фамилия которых начинается на заданную подстроку
 * @param[in] students - массив студентов
 * @param[in] substr - подстрока
 * @param[in] stud_cnt - кол-во студентов
 * @param[in,out] new_file - файл на запись
 */
int fprint_needed_students(const stud_t *students, size_t stud_cnt, FILE *new_file, const char *substr);

#endif //STUD_ARR_H
