#include "my_snprintf.h"

#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>

typedef enum {
    OCT_BASE = 8,
    DEC_BASE = 10,
    HEX_BASE = 16
} base_t;

static const char *digits = "0123456789abcdef";

/**
 * @brief Запись строки в буфер
 * @details Указатель буфера сдвигается на длину строки
 * 
 * @param [in, out] to_write - указатель на буфер 
 * @param [in] write_str - строка для записи
 * @param [in] maxlen - максимальная длина буфера
 * 
 * @return Количество записанных символов (не включая нулевой символ),
 * или отрицательное значение в случае ошибки.
 */
static int write_string(char **to_write, const char *write_str, size_t maxlen) {
    int writed = 0;

    for (; *write_str; write_str++, writed++)
        if (writed < ((int)maxlen - 1) && *to_write)
            *(*to_write)++ = *write_str;

    return writed;
}

/**
 * @brief Запись знакового числа в буфер
 * @details Указатель буфера сдвигается на длину числа или на максимано разрешенную длину
 * @details Число беззнаковое и передается в десятичной системе счисления
 * 
 * @param [in, out] to_write - указатель на буфер 
 * @param [in] num - записываемое число
 * @param [in] maxlen - максимальная длина буфера
 * @param [in] is_signed - есть ли знак у числа
 * 
 * @return Количество записанных символов (не включая нулевой символ),
 * или отрицательное значение в случае ошибки.
 */
static int write_snum(char **to_write, int num, size_t maxlen, bool is_signed) {
    int writed = 0;

    if (num / DEC_BASE != 0 || (num && is_signed))
        writed += write_snum(to_write, num / DEC_BASE, maxlen, -num > num ? true : false);

    if (writed < ((int)maxlen - 1) && *to_write) 
        *(*to_write)++ = num || !is_signed ? digits[(num < 0 ? -num : num) % DEC_BASE] : is_signed ? '-' : '+';

    return ++writed;
}

/**
 * @brief Запись числа в заданной системе счисления в буфер
 * @details Указатель буфера сдвигается на длину числа или на максимано разрешенную длину
 * @details Число беззнаковое и передается в десятичной системе счисления
 * 
 * @param [in, out] to_write - указатель на буфер 
 * @param [in] num - записываемое число
 * @param [in] maxlen - максимальная длина буфера
 * @param [in] system_base - основа системы счисления
 * 
 * @return Количество записанных символов (не включая нулевой символ),
 * или отрицательное значение в случае ошибки.
 */
static int write_diff_sys_lnum(char **to_write, unsigned long num, size_t maxlen, const base_t system_base) {
    int writed = 0;

    if (num / system_base != 0)
        writed += write_diff_sys_lnum(to_write, num / system_base, maxlen, system_base);

    if (writed < ((int)maxlen - 1) && *to_write) 
        *(*to_write)++ = digits[num % system_base];

    return ++writed;
}

int my_snprintf(char *restrict s, size_t maxlen, const char *restrict format, ...) {
    int writed = 0;
    char *write_ptr = s;
    char *write_str = NULL;

    va_list args;
    va_start(args, format);

    for (const char *format_ptr = format; writed >= 0 && *format_ptr; format_ptr++) {
        bool is_end = !(writed < ((int)maxlen - 1));
        if (*format_ptr != '%' || (*format == '%' && (*(format_ptr + 1) == '%' || *(format_ptr + 1) == 'c'))) {
            if (!is_end && write_ptr)
                *write_ptr++ = *format_ptr != '%' ? *format_ptr : *++format_ptr == 'c' ? (char)va_arg(args, int) : *format_ptr;
            writed++;
        } else if (*++format_ptr == 's') {
            writed += write_string(&write_ptr, (write_str = va_arg(args, char *)) ? write_str : "(null)", maxlen - writed);
        } else if (*format_ptr == 'd') {
            writed += write_snum(&write_ptr, va_arg(args, int), maxlen - writed, NULL);
        } else if ((*format_ptr++ == 'l') && (*format_ptr == 'o' || *format_ptr == 'x' || *format_ptr == 'u')) {
            writed += write_diff_sys_lnum(&write_ptr, va_arg(args, unsigned long), maxlen - writed, *format_ptr == 'x' ? HEX_BASE : *format_ptr == 'o' ? OCT_BASE : DEC_BASE);
        } else
            writed = -1;
    }

    if (write_ptr)
        *write_ptr = '\0';
    
    va_end(args);
    return writed;
}
