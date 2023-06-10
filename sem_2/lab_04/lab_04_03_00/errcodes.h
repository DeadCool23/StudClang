#ifndef ERRCODES_H
#define ERRCODES_H

/*!
 * @def OK
 * Положительный код возврата
 * @def ERR_IO
 * Код ошибки ввода данных
 * @def ERR_BUF_TOO_SMALL
 * Код ошибки размера введенной строки
 * @def TOO_MUCH_WORDS
 * Код ошибки избыточного количества слов
 * @def NOT_WORDS
 * Код ошибки кол-ва слов
 * @def EMPTY_NEW_STRING
 * Код ошибки пустой строки
 */
#define OK 0
#define ERR_IO 1
#define ERR_BUF_TOO_SMALL 2
#define TOO_MUCH_WORDS 3
#define NO_WORDS 5
#define EMPTY_NEW_STRING 6

/**
 * @brief Процедура вывода сообщений об ошибках ввода
 *
 * @param[in] err_code - код ошибки
 */
void input_error_message(int err_code);

/**
 * @brief Процедура вывода сообщений об ошибках слов в строке
 *
 * @param[in] err_code - код ошибки
 */
void words_error_message(int err_code);

/**
 * @brief Процедура вывода сообщений об ошибках в новой строке
 *
 * @param[in] err_code - код ошибки
 */
void words_letter_error_message(int err_code);

#endif //ERRCODES_H

