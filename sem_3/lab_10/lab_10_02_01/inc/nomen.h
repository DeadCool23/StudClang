#ifndef __NOMEN_H__
#define __NOMEN_H__

#include <stdio.h>

/// @brief nomen_t - член многочлена
typedef struct
{
    int factor; // Коэфицент члена
    int power; // Степень члена
} nomen_t;

/// @brief polinom_t - Структура односвязанного списка(многочлена)
typedef struct polinom
{
    nomen_t nomen; // Один член
    struct polinom *next; // Следующий член
} polinom_t;

/**
 * @brief Функция создания члена списка многочлена
 * 
 * @param [in] nomen - данные члена
 * @return Узел
 */
polinom_t *nomen_create(const nomen_t *nomen);

/**
 * @brief Процедура печати узла в файл
 * 
 * @param [in] nomen - Член 
 * @param [in, out] file - Файловая переменная на запись
 */
void fprint_nomen(FILE *file, const polinom_t *nomen);

/**
 * @brief Функция очистки памяти из под узла многочлена
 * 
 * @param [in] nomen - Очищаемый член
 */
void nomen_destroy(polinom_t *nomen);

#endif // __NOMEN_H__
