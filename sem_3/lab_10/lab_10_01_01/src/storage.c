#include "storage.h"

#include "list.h"
#include "node.h"
#include "point.h"

#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Функция проверки окончания файла
 * @details Функция проверяет наличие `\n` в конце файла
 * 
 * @param [in] file 
 * @return true - конец файла
 * @return false - не конец файла
 */
static bool is_eof(FILE *file)
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

err_t fread_storage(FILE *file, points_t *stor)
{
    point_t tmp_el;

    while (!is_eof(file))
    {
        if (fread_point(file, &tmp_el) != 1)
            return ERR_IO;
        
        err_t err = add_point(stor, tmp_el);
        if (err)
            return err;
    }

    return OK;
}

err_t fread_storage_ex(const char *filename, points_t *stor)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
        return ERR_FILE;
    err_t err = fread_storage(file, stor);
    fclose(file);
    return err;
}

err_t fread_insert_data(const char *filename, double *dist, point_t *point)
{
    err_t err = OK;
    FILE *file = fopen(filename, "r");
    if (!file)
        return ERR_FILE;
    
    if (fscanf(file, "%lf", dist) != 1)
        err = ERR_IO;
    
    if (fread_point(file, point) != 1)
        err = ERR_IO;
    
    fclose(file);
    return err;
}

list_t *storage2list(const points_t *stor)
{
    list_t *head = NULL;
    list_t *prev = head;
    list_t *snode = NULL;
    bool is_alloc = true;
    for (size_t i = 0; i < stor->cnt && is_alloc; i++)
    {
        snode = node_create(stor->points + i);
        if (snode)
        {
            if (!head)
                head = snode;
            else
                prev->next = snode;
            prev = snode;
        }
        else
        {
            is_alloc = false;
            free_list(head);
            head = NULL;
        }
    }
    return head;
}
