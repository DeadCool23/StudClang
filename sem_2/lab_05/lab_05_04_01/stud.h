#ifndef STUD_H
#define STUD_H

#include <stdio.h>
#include <stdint.h>
#include "marks.h"

/**
 * @def NAME_LEN
 * Максимальный размер имени
 * @def SURNAME_LEN
 * Максимальный размер фамилии
 */
#define NAME_LEN 10
#define SURNAME_LEN 25

/**
 * @typedef stud_t
 * структура содержащая в себе имя, фамилию и оценки студентов
 */
typedef struct
{
    char surname[SURNAME_LEN + 1];
    char name[NAME_LEN + 1];
    uint32_t marks[MARKS_COUNT];
} stud_t;

/**
 * @brief Функция чтения студента из файла
 * @param[out] student - студент
 * @param[in] stud_file - файл
 */
int stud_read(stud_t *student, FILE *stud_file);

/**
 * @brief Процедура вывода студента в файл
 * @param[in] student - студент
 * @param[in,out] new_file - файл на запись
 */
void stud_fprint(const stud_t *student, FILE *new_file);

/**
 * @brief Функция сравнивает студентов по инициалам 
 * @param[in] student_left - первый студент
 * @param[in] student_right - второй студент
 * @return -1 если student_left раньше по алфавиту чем student_right
 * @return 0 если инициалы student_left и student_right одинаковы
 * @return 1 если student_left позже по алфавиту чем student_right
 */
int stud_cmp_by_fullname(const stud_t *student_left, const stud_t *student_right);

/**
 * @brief Функция сравнивает студентов по фамилии
 * @param[in] student_left - первый студент
 * @param[in] student_right - второй студент
 * @return -1 если student_left раньше по алфавиту чем student_right
 * @return 0 если фамилии student_left и student_right одинаковы
 * @return 1 если student_left позже по алфавиту чем student_right
 */
int stud_cmp_by_surname(const stud_t *student_left, const stud_t *student_right);

/**
 * @brief Функция сравнивает студентов по имени
 * @param[in] student_left - первый студент
 * @param[in] student_right - второй студент
 * @return -1 если student_left раньше по алфавиту чем student_right
 * @return 0 если имена student_left и student_right одинаковы
 * @return 1 если student_left позже по алфавиту чем student_right
 */
int stud_cmp_by_name(const stud_t *student_left, const stud_t *student_right);

/**
 * @brief Функция проверки длины считанного инициала
 * @param[in,out] initial - инициал
 * @param[in] init_len - максимальный размер инициала
 * @return Код ошибки
 */
int check_initials_len(char *initial, size_t init_len);

/**
 * @brief Функция проыеряет фамилию студента на наличие заданой строки в начале
 * @param[in] student - студент
 * @param[in] substr - второй студент
 * @return -1 или 1 если фамилия student не содержит substr в начале
 * @return 0 если фамилия student содержит substr в начале
 */
int stud_cmp_surname_substr(const stud_t *student, const char *substr);

#endif //STUD_H
