#include "getdata.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arrgen.h"
#include "time_calc.h"
#include "getaverage.h"

unsigned long long get_sort_time(sort_t sort, int *arr, size_t n) 
{
    unsigned long long beg = microseconds_now();
    sort(arr, n, sizeof(*arr), int_compare);
    unsigned long long end = microseconds_now();
    return (end - beg) * 1000;
}

err_t add_sort_time(FILE *file, sort_t sort, int *arr, size_t n) 
{
    double avg = 0;
    size_t runs = 0;
    double rse = 100;
    unsigned long long *measures = malloc(sizeof(*measures));
    while (rse > MIN_RSE)
    {
        int *tmp_arr = malloc(sizeof(*arr) * n);
        if (!tmp_arr) return ERR_MEM;
        memcpy(tmp_arr, arr, n * sizeof(*arr));
        unsigned long long *ptmp = realloc(measures, sizeof(*measures) * (runs + 1));
        if (!ptmp) return ERR_MEM;
        measures = ptmp;
        measures[runs++] = get_sort_time(sort, tmp_arr, n);
        if (runs > 2)
        {
            avg = get_average(measures, runs);
            rse = real_std_err(avg, measures, runs);
        }
        free(tmp_arr);
    }
    free(measures);
    fprintf(file, "%zu %.2lf\n", n, avg);
    return OK;
}

err_t get_mes_res(char *key)
{
    FILE *mysort_file_data;
    FILE *qsort_file_data;
    if (!strcmp(key, SORTED_GEN))
    {
        mysort_file_data = fopen("data/mysort_sorted.txt", "w");
        qsort_file_data = fopen("data/qsort_sorted.txt", "w");
    }
    else if (!strcmp(key, REVERSE_GEN))
    {
        mysort_file_data = fopen("data/mysort_reversed.txt", "w");
        qsort_file_data = fopen("data/qsort_reversed.txt", "w");
    }
    else if (!strcmp(key, RAND_GEN))
    {
        mysort_file_data = fopen("data/mysort_random.txt", "w");
        qsort_file_data = fopen("data/qsort_random.txt", "w");
    }
    else
        return ERR_KEY;

    if (mysort_file_data == NULL || qsort_file_data == NULL)
        return ERR_FILE;
    err_t err = OK;
    int *arr = NULL;
    for (size_t i = 5; i <= 500; i += 5)
    {
        if ((err = gen_arr_by_key(&arr, i, key) != OK))
            goto END;
        if ((err = add_sort_time(mysort_file_data, mysort, arr, i)) != OK)
            goto END;
        if ((err = add_sort_time(qsort_file_data, qsort, arr, i)) != OK)
            goto END;
        free(arr);
    }
    END:
    if (err)
        free(arr);
    if (!err)
    {
        printf("Measuring %s sort time array using a function \033[1mmysort\033[0m and added to file \033[1mmysort_%s.txt\033[0m\n", key, key);
        printf("Measuring %s sort time array using a function \033[1mqsort\033[0m and added to file \033[1mqsort_%s.txt\033[0m\n", key, key);
    }
    fclose(mysort_file_data);
    fclose(qsort_file_data);
    return err;
}
