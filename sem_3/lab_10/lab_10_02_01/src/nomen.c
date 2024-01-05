#include "nomen.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

polinom_t *nomen_create(const nomen_t *nomen)
{
    polinom_t *polinom = malloc(sizeof(*polinom));
    if (!polinom)
        return NULL;
    polinom->next = NULL;
    polinom->nomen = *nomen;
    return polinom;
}

void nomen_destroy(polinom_t *nomen)
{
    free(nomen);
    nomen = NULL;
}

void fprint_nomen(FILE *file, const polinom_t *nomen)
{
    fprintf(file, "%d %d", nomen->nomen.factor, nomen->nomen.power);
}
