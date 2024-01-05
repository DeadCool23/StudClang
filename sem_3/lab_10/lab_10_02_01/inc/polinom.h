#ifndef __POLINOM_H__
#define __POLINOM_H__

#include "errs.h"
#include "nomen.h"

#include <stdio.h>

/**
 * @brief Функция инициализации многочлена
 * @return Полином
 */
polinom_t *polinom_init(void);

/**
 * @brief Функция считывание многочлена
 * 
 * @param [in, out] file - файловая переменная
 * @param [out] head - голова списка полинома 
 * @return Код ошибки
 */
err_t fread_polinom(FILE *file, polinom_t **head);
/**
 * @brief Процедура печати полинома
 * 
 * @param [in, out] file - файловая переменная
 * @param [in] head - голова списка полинома
 */
void fprint_polinom(FILE *file, polinom_t *head);

/**
 * @brief Функция вычисления значения полинома при определенном аргументе
 * 
 * @param [in] head - голова списка полинома
 * @param [in] val - аргумент
 * @return Вычисленное значение
 */
int val(polinom_t *head, int val);
/**
 * @brief Функция вычисления производной полинома
 * 
 * @param [in, out] head - голова списка полинома 
 * @return Полином-производная 
 */
polinom_t *ddx(polinom_t *head);
/**
 * @brief Функция сложения двух полиномов
 * @details Из второго полинома удаляются члены с уникальной степенью
 * 
 * @param [in, out] fst - голова списка первого полинома 
 * @param [in, out] scd - голова списка второго полинома
 * @return Голова полинома-суммы
 */
polinom_t *sum(polinom_t *fst, polinom_t **scd);
/**
 * @brief Разделение полинома на четные и нечетные степени
 * @details В изначальной голове остаются четные степени
 * 
 * @param [in, out] head - голова списка полинома 
 * @return голова полинома
 */
polinom_t *dvd(polinom_t **head);

/**
 * @brief Функция очистки памяти из под многочлена
 * 
 * @param [in, out] head - голова списка полинома
 */
void free_polinom(polinom_t *head);

#endif // __POLINOM_H__
