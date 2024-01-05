#include "check_process.h"

#include <stdlib.h>

int ck_assert_nomen_eq(nomen_t *X, nomen_t *Y) {
    return ((X->factor == Y->factor) && (X->power == Y->power)) ? 0 : 1;
}

int ck_assert_polinom_eq(polinom_t *X, polinom_t *Y) {
    int diff = 0;
    polinom_t *X_iter = NULL,*Y_iter = NULL;
    for (X_iter = X, Y_iter = Y; X_iter && Y_iter && !diff; X_iter = X_iter->next, Y_iter = Y_iter->next)
    {
        diff = ck_assert_nomen_eq(&X_iter->nomen, &Y_iter->nomen);
    }
    diff = !diff ? ((X_iter == Y_iter) ? 0 : 1) : diff;
    return diff;
}
