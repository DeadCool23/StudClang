#include <stdio.h>
#include <string.h>

#include "allocate.h"
#include "matrix_math.h"
#include "matrix_struct.h"
#include "matrixio.h"

int main(int argc, char *argv[])
{
    err_t err = OK;
    matrix_t matrix_res = { .matrix = NULL };
    matrix_t matrix_fst = { .matrix = NULL };
    matrix_t matrix_scd = { .matrix = NULL };
    if (argc == 5 && !strcmp(argv[1], "a"))
    {
        err = matrix_create_ex(argv[2], &matrix_fst);
        err = !err ? matrix_create_ex(argv[3], &matrix_scd) : err;
        err = !err ? matrix_sum(&matrix_fst, &matrix_scd, &matrix_res) : err;
    }
    else if (argc == 5 && !strcmp(argv[1], "m"))
    {
        err = matrix_create_ex(argv[2], &matrix_fst);
        err = !err ? matrix_create_ex(argv[3], &matrix_scd) : err;
        err = !err ? matrix_mult(&matrix_fst, &matrix_scd, &matrix_res) : err;
    }
    else if (argc == 4 && !strcmp(argv[1], "g"))
    {
        err = matrix_create_ex(argv[2], &matrix_fst);
        err = !err ? gauss(&matrix_fst, &matrix_res) : err;
    }
    else
        err = ERR_ARGS;

    if (!err)
    {
        FILE *file = fopen(!strcmp(argv[1], "o") ? argv[3] : argv[4], "w");
        if (file != NULL)
        {
            matrix_print(file, &matrix_res);
            fclose(file);
        }
        else
            err = ERR_FILE;
    }

    matrix_free(matrix_fst.matrix, matrix_fst.rows);
    matrix_free(matrix_scd.matrix, matrix_scd.rows);
    matrix_free(matrix_res.matrix, matrix_res.rows);
    return err;
}
