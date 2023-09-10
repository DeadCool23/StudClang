#include "subj_arr.h"

#include <string.h>

bool is_eof(FILE *file)
{
    char end = getc(file);
    if (end == EOF)
        return true;
    if (end == '\n')
    {
        char endd = getc(file);
        if (end == EOF)
            return true;
        ungetc(endd, file);
    }
    ungetc(end, file);
    return false;
}

err_t subjects_read(FILE *file, subject_t *subjects, const size_t n_max, size_t *subjs_cnt)
{
    bool eof = false;

    for (size_t i = 0; i < n_max && !eof;)
    {
        if (!(eof = is_eof(file)))
        {
            err_t err = subject_read(file, subjects + i);
            if (err != OK)
                return err;
            (*subjs_cnt)++;
            i++;
        }
    }

    if (!eof)
        return ERR_OVERFLOW;

    return *subjs_cnt == 0 ? ERR_IO : OK;
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

err_t subjects_print_by_option(FILE *file, subject_t *subjects, const size_t subjs_cnt, const char *option)
{
    if (!strcmp(option, TO_SORT))
    {
        if (subjs_cnt > 1)
            subject_sort_by_density(subjects, subjs_cnt);
        if (subjects_print_all(file, subjects, subjs_cnt))
            return ERR_IO;
    }
    else if (!strcmp(option, "ALL"))
    {
        if (subjects_print_all(file, subjects, subjs_cnt))
            return ERR_IO;
    }
    else
    {
        if (subjects_print_with_substr(file, subjects, subjs_cnt, option))
            return ERR_IO;
    }

    return OK;
}

void subject_sort_by_density(subject_t *subjects, const size_t subjs_cnt)
{
    size_t i, j;
    bool swapped = true;
    for (i = 0; i < subjs_cnt - 1 && swapped; i++)
    {
        swapped = false;
        for (j = 0; j < subjs_cnt - i - 1; j++)
        {
            if (subject_density_calc(subjects + j) > subject_density_calc(subjects + j + 1))
            {
                subject_t temp = subjects[j];
                subjects[j] = subjects[j + 1];
                subjects[j + 1] = temp;
                swapped = true;
            }
        }
    }
}
