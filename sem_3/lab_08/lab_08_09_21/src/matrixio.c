#include "matrixio.h"

#include <stdlib.h>

#include "allocate.h"

bool is_eof(FILE *file)
{
    char end = getc(file);
    if (end == EOF)
        return true;
    if (end == '\n')
    {
        char endd = getc(file);
        if (endd == EOF)
            return true;
        ungetc(endd, file);
    }
    ungetc(end, file);
    return false;
}

err_t matrix_read(FILE *f, const matrix_t *matrix)
{
    int els_cnt;
    err_t err = OK;
    bool * add_arr = calloc(matrix->rows * matrix->cols, sizeof(*add_arr));
    if (!add_arr)
        return ERR_MEM;
    if (fscanf(f, "%d", &els_cnt) != 1)
        err = ERR_IO;

    if (!err)
    {
        if (els_cnt < 0 || (size_t)els_cnt > matrix->rows * matrix->cols)
            err = ERR_IO;

        for (size_t i = 0; i < (size_t)els_cnt && !err; i++)
        {
            double el_tmp;
            int n_tmp, m_tmp;
            if (fscanf(f, "%d%d%lf", &n_tmp, &m_tmp, &el_tmp) != 3)
                err = ERR_IO;
            
            if (!err)
            {
                if ((n_tmp <= 0 || (size_t)n_tmp > matrix->rows) || (m_tmp <= 0 || (size_t)m_tmp > matrix->cols) || add_arr[matrix->cols * (n_tmp - 1) + (m_tmp - 1)])
                    err = ERR_IO;

                if (!err)
                {
                    matrix->matrix[n_tmp - 1][m_tmp - 1] = el_tmp;
                    add_arr[matrix->cols * (n_tmp - 1) + (m_tmp - 1)] = true;
                }
            }
        }
    }

    free(add_arr);
    return !err ? (is_eof(f) ? OK : ERR_FILE) : err;
}

err_t matrix_create(FILE *f, matrix_t *matrix)
{
    int n_tmp, m_tmp;
    if (fscanf(f, "%d%d", &n_tmp, &m_tmp) != 2)
        return ERR_IO;

    if (n_tmp <= 0 || m_tmp <= 0)
        return ERR_IO;

    matrix->rows = n_tmp;
    matrix->cols = m_tmp;

    matrix->matrix = matrix_calloc(matrix->rows, matrix->cols);
    if (!matrix->matrix)
        return ERR_MEM;

    err_t err = matrix_read(f, matrix);
    if (err)
    {
        matrix_free(matrix->matrix, matrix->rows);
        matrix->matrix = NULL;
    }

    return err;
}

err_t matrix_create_ex(const char *filename, matrix_t *matrix)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
        return ERR_FILE;

    err_t err = OK;
    err = matrix_create(file, matrix);

    fclose(file);
    return err;
}

void matrix_print(FILE *file, const matrix_t *matrix)
{
    fprintf(file, "%zu %zu\n", matrix->rows, matrix->cols);
    for (size_t i = 0; i < matrix->rows; i++)
    {
        for (size_t j = 0; j < matrix->cols; j++)
            fprintf(file, "%lf ", matrix->matrix[i][j]);
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
}

