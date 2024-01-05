#ifndef ERRS_H
#define ERRS_H

/// @enum - перечисление ошибок
typedef enum
{
    OK, /// Отсутствие ошибок
    ERR_IO, /// Ошибка ввода данных
    ERR_RANGE, /// Ошибка диапазона 
    ERR_MEM, /// Ошибка выделения памяти
    ERR_CMD /// Ошибка команды
} err_t;

#endif  // ERRS_H
