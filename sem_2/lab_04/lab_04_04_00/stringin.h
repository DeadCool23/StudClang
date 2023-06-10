#ifndef STRINGIN_H
#define STRINGIN_H

#include <stddef.h>

#define STR_LEN 256

/**
 * Функция ввода строки
 * @param sting - Строка
 * @param string_size - Максимальный размер строки
 * @return Код ошибки
 */
int string_input(char *sting, size_t string_size);

/**
 * Процедура удаления пробельных символов начала и конца строки
 * @param[in,out] string - строка
 */
void space_del(char *string);

#endif
