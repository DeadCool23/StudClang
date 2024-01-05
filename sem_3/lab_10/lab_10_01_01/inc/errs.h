#ifndef ERRS_H
#define ERRS_H

/// @enum - перечисление ошибок
typedef enum
{
    OK, /// Отсутствие ошибок
    ERR_IO, /// Ошибка вводиых выводимых данных
    ERR_MEM, /// Ошибка выделения памяти
    ERR_ARGS, /// Ошибка аргументов
    ERR_FILE, /// Ошибка открытия файла
    ERR_DATA /// Ошибка данных
} err_t;

#endif  // ERRS_H
