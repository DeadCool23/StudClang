/**
 * @file testing.h
 * @brief Тестирование всех функций проектра
 */

#ifndef TESTING_H
#define TESTING_H
#include <stdbool.h>

/**
 * @brief Функция для тестирования всех функций
 */
void func_test(void);

/**
 * @fn void testing_digit_count(void)
 * @brief Процедура тестирования функции digit_count
 */
void testing_digit_count(void);

/**
 * @fn void testing_freq_digit(void)
 * @brief Процедура тестирования функции freq_digit
 */
void testing_freq_digit(void);

/**
 * @fn void testing_get_digits(void)
 * @brief Процедура тестирования функции get_digits
 */
void testing_get_digits(void);

/**
 * @brief Функция сравнения массивов
 * 
 * @param[in] arr1 - первый массив 
 * @param[in] arr2 - второй массив
 * @return true/false 
 */
bool diff_arr(int arr1[], int arr2[]);

#endif //TESTING_H  
