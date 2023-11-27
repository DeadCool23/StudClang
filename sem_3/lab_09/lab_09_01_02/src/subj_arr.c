#include "subj_arr.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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

err_t subjects_cnt(FILE *file, size_t *subjs_cnt)
{
    *subjs_cnt = 0;
    bool eof = false;
    subject_t tmp_subj = 
    {
        .name = NULL,
        .weight = 0,
        .volume = 0,
    };

    while (!eof)
    {
        err_t err = subject_read(file, &tmp_subj);
        if (err != OK)
        {
            free_subj(&tmp_subj);
            return err;
        }
        (*subjs_cnt)++;
        eof = is_eof(file);
    }

    free_subj(&tmp_subj);
    return OK;
}

err_t subjects_read(FILE *file, subject_t *subjects, size_t subjs_cnt)
{
    bool eof = false;
    subject_t tmp_subj = 
    {
        .name = NULL,
        .weight = 0,
        .volume = 0,
    };

    for (size_t i = 0; i < subjs_cnt && !eof; i++)
    {
        subjects[i].name = NULL;
        err_t err = subject_read(file, &tmp_subj);
        if (err != OK)
        {
            free_subj(&tmp_subj);
            return err;
        }
        subj_cpy(subjects + i, &tmp_subj);
        eof = is_eof(file);
    }

    free_subj(&tmp_subj);
    return OK;
}

err_t subjects_create(FILE *file, subject_t **subjects, size_t *subjs_cnt)
{
    err_t err = OK;
    err = subjects_cnt(file, subjs_cnt);
    rewind(file);
    if (!(*subjs_cnt) || err)
    {
        *subjs_cnt = 0;
        return ERR_IO;
    }
    *subjects = malloc((*subjs_cnt) * sizeof(**subjects));
    if (!(*subjects))
        return ERR_MEM;
    err = subjects_read(file, *subjects, *subjs_cnt);
    return err;
}

err_t subjects_create_ex(const char *filename, subject_t **subjects, size_t *subjs_cnt)
{
    err_t err = OK;
    FILE *file = fopen(filename, "r");
    if (file == NULL)
        return ERR_FILE;

    err = subjects_create(file, subjects, subjs_cnt);
    fclose(file);
    return err;
}

err_t subjects_print_all(FILE *file, const subject_t *subjects, const size_t subjs_cnt)
{
    for (size_t i = 0; i < subjs_cnt; i++)
        if (subject_print(file, subjects + i))
            return ERR_IO;
    return OK;
}

err_t subjects_print_with_substr(FILE *file, const subject_t *subjects, const size_t subjs_cnt, const char *substr)
{
    for (size_t i = 0; i < subjs_cnt; i++)
        if (substr_search_in_name(subjects + i, substr))
            if (subject_print(file, subjects + i))
                return ERR_IO;
    return OK;
}

void subjects_sort_by_density(subject_t *subjects, const size_t subjs_cnt, compare_t el_cmp)
{
    size_t i, j;
    bool swapped = subjs_cnt ? true : false;
    for (i = 0; i < subjs_cnt - 1 && swapped; i++)
    {
        swapped = false;
        for (j = 0; j < subjs_cnt - i - 1; j++)
        {
            if (el_cmp(subjects + j, subjects + j + 1) > 0)
            {
                subject_t temp = subjects[j];
                subjects[j] = subjects[j + 1];
                subjects[j + 1] = temp;
                swapped = true;
            }
        }
    }
}

void free_subjs(subject_t *subjects, const size_t subjs_cnt)
{
    for (size_t i = 0; i < subjs_cnt; i++)
        free_subj(subjects + i);
    free(subjects);
}
