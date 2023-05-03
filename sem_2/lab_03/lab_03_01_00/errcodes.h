#ifndef ERRCODES_H
#define ERRCODES_H

/*!
 * @def OK
 * Положительный код возврата
 * @def ERR_IO
 * Код ошибки ввода данных
 * @def ERR_SIZE
 * Код ошибки ввоха размера матрицы
*/
#define OK 0
#define ERR_IO 1
#define ERR_SIZE 3

/**
 * @brief Процедура вывода сообщения об ошибке
 *
 * @param [in] err_code - код ошибки
 */
void err_output(int err_code);

#endif //ERRCODES_H
