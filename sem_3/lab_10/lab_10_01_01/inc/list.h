#ifndef LIST_H
#define LIST_H

#include "node.h"

#include <stdio.h>

typedef int (*comparator_t)(const void *, const void *);

/**
 * @brief Функция поиска узла
 * @details Ищется узел у которого тока удалена на заданное расстояние от начала координат
 * 
 * @param [in] head - голова списка
 * @param [in] data - указанное расстояние
 * @param [in] cmp - функция сравнения точки с заданным расстоянием
 * @return Узел
 */
list_t *find(list_t *head, const void *data, comparator_t cmp);
/**
 * @brief Вставка элемета в список перед заданным
 * 
 * @param [in, out] head - голова списка 
 * @param [in] elem - вставляемый элемент 
 * @param [in] before - элемент после которого тдет вставка
 */
void insert(list_t **head, list_t *elem, list_t *before);

/**
 * @brief Функция обращения списка
 * @details Алгоритм рекурсивный
 * 
 * @param [in, out] head - голова списка 
 * @return Голова "нового" списка
 */
list_t *reverse(list_t *head);

/**
 * @brief Функция сортировки списка
 * @details Сортировка вставками
 * 
 * @param [in, out] head - голова списка
 * @param [in] cmp - указатель на функцию сравнения элементов списка
 * @return Голова "нового" списка 
 */
list_t *sort(list_t *head, comparator_t cmp);
/**
 * @brief Функция вставки элемента в отсортированный список
 * 
 * @param [out] head - голова списка
 * @param [in] element - вставляемый элемент
 * @param [in] cmp - указатель на функцию сравнения элементов списка
 */
void sorted_insert(list_t **head, list_t *element, comparator_t cmp);

/**
 * @brief Функция печати списка
 * 
 * @param [in] head - голова списка
 * @param [in, out] file - файловая переменная на запись списка
 */
void fprint_list(FILE *file, list_t *head);

/**
 * @brief Функция освобождения памяти из под списка
 * 
 * @param [in, out] head - голова списка
 */
void free_list(list_t *head);

#endif // LIST_H
