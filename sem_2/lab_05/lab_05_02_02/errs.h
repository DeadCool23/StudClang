#ifndef ERRS_H
#define ERRS_H

/**
 * @def OK
 * Положительное окончание программы
 * @def ERR_PARAM
 * Ошибка параметров
 * @def ERR_DATA
 * Ошибка данных
 */
#define OK 0
#define ERR_PARAM 1
#define ERR_DATA 2

/**
 * @brief Процедура вывода сообщений об ошибках в обработке данных
 * @param err - код ошибки
 */
void calc_errs(int err);

#endif //ERRS_H
