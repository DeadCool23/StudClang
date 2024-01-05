#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <dlfcn.h>

#include "errs.h"

typedef err_t (*fcnt_els_t)(FILE *, size_t *);
typedef err_t (*fread_arr_t)(FILE *, int *, int *);
typedef int (*cmp_t)(const void *, const void *);
typedef size_t (*sort_t)(void *, size_t, size_t, cmp_t);
typedef size_t (*filt_len_t)(const int *, const int *);
typedef err_t (*filt_t)(const int *, const int *, int *, size_t);
typedef void (*fprint_arr_t)(FILE *, const int *, const int *);

/**
 * @brief Функция чтения массива из файла
 * 
 * @param [out] arr - массив 
 * @param [out] size - размер массива
 * @param [in] filename - имя файла
 * @param [in] cnt_els - функция подсчета кол-ва элементов в файле
 * @param [in] arr_read - функция считывания массива из файла
 * @return код ошибки
 */
err_t fread_arr(int **arr, size_t *size, const char *filename, fcnt_els_t cnt_els, fread_arr_t arr_read);

/**
 * @brief Функция записи массива в файл
 * 
 * @param [in] arr - массив 
 * @param [in] size - размер массива
 * @param [in] filename - имя файла
 * @param [in] arr_print - функция записи массива в файл
 * @return код ошибки
 */
err_t fwrite_arr(const int *arr, size_t size, const char *filename, fprint_arr_t arr_print);

/**
 * @brief Функция чтения массива из файла
 * 
 * @param [out] arr - массив 
 * @param [out] size - размер массива
 * @param [in] filtered_len - функция подсчета кол-ва элементов в отфильтрованном массиве
 * @param [in] filter - функция фильтрации массива
 * @return код ошибки
 */
err_t filter_arr(int **arr, size_t *size, filt_len_t filtered_len, filt_t filter);

/// @brief GET_FUNC - записывает в указатель на функцию одноименную функцию из библиотеки
#define GET_FUNC(dlib, func_ptr) func_ptr = dlsym(dlib, #func_ptr) 

int main(int argc, char *argv[])
{
    if (argc < 4)
        return ERR_ARGS;

    void *dlib = dlopen(argv[1], RTLD_NOW);
    if (!dlib)
        return ERR_DLFILE;
    
    err_t err = OK;

    filt_t key;
    filt_len_t key_len;

    sort_t mysort;
    cmp_t int_compare;

    fcnt_els_t fcnt_arr_els;
    fread_arr_t fread_els_in_arr;
    fprint_arr_t fprint_arr;

    switch (err) {
        case OK:
            GET_FUNC(dlib, key);
            if (!key) {
                err = ERR_DLFUNC;
                break;
            }
            
            GET_FUNC(dlib, key_len);
            if (!key_len) {
                err = ERR_DLFUNC;
                break;
            }

            GET_FUNC(dlib, mysort);
            if (!mysort) {
                err = ERR_DLFUNC;
                break;
            }
            
            GET_FUNC(dlib, int_compare);
            if (!int_compare) {
                err = ERR_DLFUNC;
                break;
            }

            GET_FUNC(dlib, fcnt_arr_els);
            if (!fcnt_arr_els) {
                err = ERR_DLFUNC;
                break;
            }
            
            GET_FUNC(dlib, fread_els_in_arr);
            if (!fread_els_in_arr) {
                err = ERR_DLFUNC;
                break;
            }

            GET_FUNC(dlib, fprint_arr);
            if (!fprint_arr) {
                err = ERR_DLFUNC;
                break;
            } 
        default:
            break;
    }

    if (err) { 
        dlclose(dlib);
        return err;
    }

    size_t n = 0;
    int *arr = NULL;
    err = fread_arr(&arr, &n, argv[2], fcnt_arr_els, fread_els_in_arr);

    if (!err)
    {
        if (argc == 5 && !strcmp(argv[4], "f"))
            err = filter_arr(&arr, &n, key_len, key);
        else if (argc >= 5)
            err = ERR_ARGS;

        if (!err)
        {
            mysort(arr, n, sizeof(*arr), int_compare);
            fwrite_arr(arr, n, argv[3], fprint_arr);  
        }
    }
    free(arr);
    dlclose(dlib);
    return err;
}

err_t fread_arr(int **arr, size_t *size, const char *filename, fcnt_els_t cnt_els, fread_arr_t arr_read) {
    FILE *file = fopen(filename, "r");
    if (!file)
        return ERR_FILE;

    err_t err = cnt_els(file, size);
    rewind(file);
    if (!err && *size > 0) {
        *arr = malloc(*size * sizeof(**arr));
        if (!(*arr))
            err = ERR_MEM;
        if (!err)
            err = arr_read(file, *arr, *arr + *size);
    } else
        err = ERR_IO;
    
    fclose(file);
    return err;
}

err_t filter_arr(int **arr, size_t *size, filt_len_t filtered_len, filt_t filter) {
    err_t err = OK;
    int *arr_filt = NULL;
    size_t n_filt = filtered_len(*arr, *arr + *size);
    if (!n_filt)
        err = ERR_ARR;
    else
        arr_filt = malloc(n_filt * sizeof(*arr_filt));

    if (!arr_filt)
        err = ERR_MEM;
    else
        err = filter(*arr, *arr + *size, arr_filt, n_filt);
    
    if (!err)
    {
        *size = n_filt;
        free(*arr);
        *arr = arr_filt;
    }
    else
        free(arr_filt);
    return err;
}

err_t fwrite_arr(const int *arr, size_t size, const char *filename, fprint_arr_t arr_print) {
    FILE *file = fopen(filename, "w");
    if (!file)
        return ERR_FILE;
    
    arr_print(file, arr, arr + size);
    fclose(file);
    return OK;
}