#ifndef __STARAGE_H__
#define __STARAGE_H__

#include "errs.h"
#include "node.h"
#include "point.h"

#include <stdio.h>

/**
 * @brief Функция считывания списка из файла
 * @details Список точек на двумерной системе координат
 * @details Файл форматный. Координаты хранятся в виде: (x,y)
 * 
 * @param [in, out] file - файловая переменная 
 * @param [out] stor - хранилище координат
 * @return Код ошибки 
 */
err_t fread_storage(FILE *file, points_t *stor);
/**
 * @brief Функция считывания списка из файла с заданным названием
 * 
 * @param [in] filename - название файла
 * @param [out] head - голова списка
 * @return Код ошибки
 */
err_t fread_storage_ex(const char *filename, points_t *stor);

/**
 * @brief Чтение из файла информации для вставки узла
 * 
 * @param [in] filename - название файла
 * @param [out] dist - искомое расстояние
 * @param [out] point - вставляемая точка
 * @return Код ошибки 
 */
err_t fread_insert_data(const char *filename, double *dist, point_t *point);

/**
 * @brief Функция конвертации массива в односвязный список
 * 
 * @param [in] arr - массив координат
 * @param [in] size - размер массива
 * @return Голова списка
 */
list_t *storage2list(const points_t *stor);

#endif // __STARAGE_H__
