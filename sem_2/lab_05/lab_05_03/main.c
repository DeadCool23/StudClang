/**
 * @details Алгоритрм сортировки: сортировка пузырьком с флагом
 * @details Тип данных в бинарном файле: int32_t
 * @details Упорядочивание по возрастанию
 */

#include <string.h>
#include <stdio.h>
#include "errs.h"
#include "binwork.h"

int main(int argc, char **argv)
{
    FILE *file;
    int err = OK;
    if (argc < 3)
        return ERR_PARAM;
    
    size_t number = 10;
    if (strcmp(argv[1], "w") == 0)
    {
        if (argc == 4)
        {
            err = check_num(argv[3], &number);
            ERR_CHECK(err);
        }

        file = fopen(argv[2], "wb");
        if (file != NULL)
            err = fb_write_nums(file, number);
        else
            err = ERR_FILE;
    }
    else if (strcmp(argv[1], "p") == 0)
    {
        err = check_file(argv[2]);
        ERR_CHECK(err);
        file = fopen(argv[2], "rb");
        err = fb_print(file);
    }
    else if (strcmp(argv[1], "s") == 0)
    {
        err = check_file(argv[2]);
        ERR_CHECK(err);
        file = fopen(argv[2], "rb+");
        err = fb_sort(file);
    }
    else
        return ERR_KEY;

    fclose(file);
    ERR_CHECK(err);
    return err;
}
