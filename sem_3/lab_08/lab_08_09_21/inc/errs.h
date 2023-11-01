#ifndef __ERRS_H__
#define __ERRS_H__

/// @enum err_t - перечисление ошибок
typedef enum
{
    OK, // Все нормально
    ERR_IO, // Ошибка ввода
    ERR_RANGE, // Ошибка диапозона
    ERR_MEM, // Ошибка памяти
    ERR_FILE, // Ошибка файла
    ERR_ARGS, // Ошибка аргументов
    ERR_MATRIX, // Ошибка матрицы
    ERR_MATH // Ошибка математической операции
} err_t;

#endif  //__ERRS_H__
