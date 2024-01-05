#include "check_process.h"

#include <stdlib.h>

int ck_assert_point_eq(point_t *X, point_t *Y) {
    return abs(points_cmp(X, Y));
}

int ck_assert_list_eq(list_t *X, list_t *Y) {
    int diff = 0;
    list_t *X_iter = NULL,*Y_iter = NULL;
    for (X_iter = X, Y_iter = Y; X_iter && Y_iter && !diff; X_iter = X_iter->next, Y_iter = Y_iter->next)
        diff = ck_assert_point_eq(X_iter->element, Y_iter->element);
    diff = !diff ? ((X_iter == Y_iter) ? 0 : 1) : diff;
    return diff;
}
