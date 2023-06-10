#ifndef IP_SEARCH_H
#define IP_SEARCH_H

#include <stdbool.h>

/**
 * @def MAX_IP_OCTATE
 * Максимальное значение октeты IP-адресса
 */
#define MAX_IP_OCTET 255

/**
 * @def POINT_COUNT
 * Кол-во точек в IP-адрессе
 * @def OCTET_COUNT
 * Кол-во октет в IP-адрессе
 * @def MAX_OCTET_LEN
 * Максимальная длина октeты IP-адресса
 * @def MAX_IP_LEN
 * Максимальная длина IP-адресса
 */
#define POINT_COUNT 3
#define OCTET_COUNT 4
#define MAX_OCTET_LEN 3
#define MAX_IP_LEN (OCTET_COUNT * MAX_OCTET_LEN + POINT_COUNT)

/**
 * @brief Функция проверяет является ли строка IP-адрессом
 *
 * @param[in] ip - предполагаемый IP-адресс
 * @return Значение логического типа
 */
bool is_ip(const char *ip);

/**
 * @brief Функция считает кол-во символов, которые не являются эталонными
 *
 * @param[in] str - проверяемая строка
 * @param[in] control - строка эталонных символов
 * @return Кол-во неэталонных символов
 */
int lexem_nin(const char *str, const char *control);

/**
 * @brief Функция проверяет число на принадлежность интервалу допустимых значений
 *
 * @param[in] num_string - строка-число
 * @return Значение логического типа
 */
bool check_num_range(const char *num_string);

#endif
