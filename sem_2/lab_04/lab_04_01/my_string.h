#ifndef MY_STRING
#define MY_STRING

#include <stddef.h>

/**
 * @fn char *my_strpbrk(const char *str, const char *control)
 * @brief Функция ищет вхождения любого символа из одной строки в другой
 *
 * @param[in] str - Строка, в которой ищется вхождения символов
 * @param[in] control - Строка искомых символов
 * @return Указатель на первое найденное вхождения одного из искомых символов
 */
char *my_strpbrk(const char *str, const char *control);

/**
 * @fn size_t *my_strspn(const char *str, const char *control)
 * @brief Функция считает количество вхождений символов одной строки в начале другой строки
 *
 * @param[in] str - строка для проверки начала на вхождения
 * @param[in] control - строка символов вхождения
 * @return Количество вхождений символов в начале
 */
size_t my_strspn(const char *str, const char *control);

/**
 * @fn size_t *my_strspn(const char *str, const char *control)
 * @brief Функция считает количество отсутствия вхождений символов одной строки в начале другой строки
 *
 * @param[in] str - строка для проверки начала на отсутсвие вхождений
 * @param[in] control - строка символов вхождения
 * @return Количество отсутствия вхождений символов в начале
 */
size_t my_strcspn(const char *str, const char *control);

/**
 * @fn char *my_strchr(const char *str, int val)
 * @brief Функция ищет первое вхождение заданного символа в заданной строке
 *
 * @param[in] str - Строка, в которой ищется вхождение символа
 * @param[in] val - Символ
 * @return Указатель на первое найденное вхождение символа
 */
char *my_strchr(const char *str, int val);

/**
 * @fn char *my_strchr(const char *str, int val)
 * @brief Функция ищет последнее вхождение заданного символа в заданной строке
 *
 * @param[in] str - строка, в которой ищется вхождение символа
 * @param[in] vch - Символ
 * @return Указатель на последнее найденное вхождение символа
 */
char *my_strrchr(const char *str, int ch);

#endif
