#ifndef NODE_H
#define NODE_H

#include <stdio.h>

/// @brief list_t - Структура односвязанного списка
typedef struct node
{
    void *element;
    struct node *next;
} list_t;

/**
 * @brief Функция создания узла списка
 * 
 * @param [in] element - данные узла
 * @return Узел
 */
list_t *node_create(void *element);

/**
 * @brief Процедура печати узла в файл
 * 
 * @param [in] node - Узел 
 * @param [in, out] file - файловая переменная на запись
 */
void fprint_node(FILE *file, const list_t *node);

/**
 * @brief Функция очистки памяти из под узла
 * 
 * @param [in] node - очищаемый узел
 */
void node_destroy(list_t *node);

#endif // NODE_H
