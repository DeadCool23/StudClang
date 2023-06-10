#ifndef MARKS_H
#define MARKS_H

#include <bits/types/FILE.h>
#include <stdint.h>
#include <stdio.h>

#define MARKS_COUNT 4

/**
 * @brief Функция считывания оценок из файла
 * @param[out] marks - оценки
 * @param[in] marks_cnt - количество оценок
 */
int get_marks(uint32_t *marks, size_t marks_cnt, FILE *stud_file);

/**
 * @brief Процедура вывода оценок
 * @param[in] marks - оценки
 * @param[in] marks_cnt - кол-во оценок
 * @param[in,out] new_file - файл на запись
 */
void fprint_marks(const uint32_t *marks, size_t marks_cnt, FILE  *new_file);

#endif //MARKS_H
