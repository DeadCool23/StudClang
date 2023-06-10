#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>

/**
 * @brief Функция поиска индекса максимального элемента
 *
 * @param[in] f - файловая переменная
 * @param[out] max_index - индекс максимального числа
 * @return Код ошибки
 */
int process(FILE *f, size_t *max_index);

#endif //PROCESS_H
