/**
 * @file pop_digit.h
 * @author Нисуев Нису ИУ7-22Б
 * @brief Поиска самого частоповторяющейся цифры
 */

#ifndef POPDIG_H
#define POPDIG_H

#include "matrixio.h"

/// @def DIG_COUNT
/// Количество цифр
#define DIG_COUNT 10

/**
 * @fn void digit_count(int matrix[][M], int n, int m, int dig_arr[])
 * @brief Функция создания частотного массива цифр элементов матрицы
 * @details Индекс элемента соответствует цифре
 * 
 * @param[in] matrix - матрица
 * @param[in] n, m - размерность матрицы
 * @param[out] dig_arr - частотный массив
 */
void digit_count(int matrix[][M], int n, int m, int dig_arr[]);

/**
 * @fn void get_digits(int dig_arr[], int num);
 * @brief Функция записи кол-ва повторений цифр элемента матрицы в частотный массив  
 * @details В частотный массив значения дозаписываются
 * 
 * @param[in, out] dig_arr - Частотный массив
 * @param[in] num - Число(Элемент матрицы) 
 */
void get_digits(int dig_arr[], int num);

/**
 * @fn int freq_digit(int dig_arr[])
 * @brief Функция ищет в частотном массиве самую частовстречающуюся цифру
 * @details Если несколько самых чатсовстречающихся цифр, выбирается минимальное
 * 
 * @param[in] dig_arr - Частотный массив 
 * @return pop_digit - самое частовстречающаяся цифра в матрице 
 */
int freq_digit(int dig_arr[]);

#endif
