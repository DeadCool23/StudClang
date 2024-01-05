#ifndef __POINT_H__
#define __POINT_H__

#include "errs.h"

#include <stdio.h>
#include <stddef.h>

#define EPS 1e-10

typedef struct
{
    double x;
    double y;
} point_t;

typedef struct
{
    point_t *points;
    size_t cnt;
    size_t capacity;
} points_t;

/**
 * @brief Инициализация вектора точек
 * 
 * @return Вектор точек
 */
points_t points_init(void);
/**
 * @brief Уничтожение вектора точек
 * 
 * @param [out] points - вектор точек
 */
void points_destroy(points_t *points);

/**
 * @brief Функция сравнения коордниат
 * @details Сравнивается расстояние д начала системы координат
 * 
 * @param [in] fst - первая координата 
 * @param [in] scd - вторая координата
 * @return <0 - первая координата дальше от начала координат
 * @return =0 - точки равноудалены от начала координат
 * @return >0 - вторая координата дальше от начала координат
 */
int points_cmp(const void *fst, const void *scd);
/**
 * @brief Функция сравнения точки с заданным расстоянием до начала координат
 * 
 * @param [in] point - точка 
 * @param [in] dist - расстояние
 * @return =1 - точка не на заданном расстоянии от начала координат
 * @return =0 - точка на заданном расстоянии от начала координат
 */
int dist_cmp(const void *point, const void *dist);

/**
 * @brief Функция считывания точки из файла
 * 
 * @param [in, out] file - файловая переменная 
 * @param [out] dst - указатель на мето записи 
 * @return 0 если не считалось, иначе 1
 */
int fread_point(FILE *file, point_t *dst);

/**
 * @brief Добавление точки в вектор точек
 * 
 * @param [in, out] points - вектор точек 
 * @param [in] point - точка
 * @return Код ошибки
 */
err_t add_point(points_t *points, point_t point);

#endif // __POINT_H__
