#include "point.h"

#include <math.h>
#include <stdlib.h>
#include "errs.h"

#define STEP 2
#define START_CAPACITY 1

points_t points_init(void)
{
    points_t init_points = { 
        .cnt = 0, 
        .capacity = 0, 
        .points = NULL
    };
    return init_points; 
}

void points_destroy(points_t *points)
{
    free(points->points);
    points->capacity = points->cnt = 0;
    points->points = NULL;
}

int points_cmp(const void *fst, const void *scd)
{
    const point_t *point_fst = fst;
    const point_t *point_scd = scd;

    double fst_sq_dist = point_fst->x * point_fst->x + point_fst->y * point_fst->y;
    double scd_sq_dist = point_scd->x * point_scd->x + point_scd->y * point_scd->y;

    return (fst_sq_dist > scd_sq_dist) ? 1 : (fabs(fst_sq_dist - scd_sq_dist) < EPS) ? 0 : -1;
}

int dist_cmp(const void *point, const void *dist)
{
    const point_t *point_ = point;
    double distant = sqrt(point_->x * point_->x + point_->y * point_->y);
    return (fabs(distant - *(double *)dist) < EPS) ? 0 : 1;
}

int fread_point(FILE *file, point_t *dst)
{
    return (fscanf(file, "%lf,%lf", &dst->x, &dst->y) == 2) ? 1 : 0;
}

err_t add_point(points_t *points, point_t point)
{
    if (!points->capacity)
    {
        points->capacity = START_CAPACITY;
        points->points = malloc(points->capacity * sizeof(point));
        if (!points->points)
            return ERR_MEM;
    }
    else if (points->cnt == points->capacity)
    {
        points->capacity *= STEP;
        point_t *tmp_points = realloc(points->points, points->capacity * sizeof(point));
        if (!tmp_points)
        {
            points_destroy(points);
            return ERR_MEM;
        }
        points->points = tmp_points;
    }
    points->points[points->cnt++] = point;
    return OK;
}
