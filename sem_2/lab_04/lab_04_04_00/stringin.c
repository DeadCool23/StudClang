#include "stringin.h"
#include "errcodes.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void space_del(char *string)
{
    size_t k = 0;
    char str_copy[STR_LEN];
    strcpy(str_copy, string);
    /// Удаление конечных пробельных символов
    for (size_t i = strlen(str_copy); strlen(str_copy) != 0 && isspace(str_copy[i - 1]); i--)
        str_copy[i - 1] = '\0';
    /// Поиск количества начальных пробельных символов
    while (isspace(str_copy[k]))
        k++;
    /// Удаление пробельных символов из введенной строки
    strcpy(string, str_copy + k);
}

int string_input(char *string, size_t string_size)
{
    char *point;
    if (!fgets(string, string_size, stdin))
        return ERR_IO;
    point = strrchr(string, '\n');
    if (point)
    {
        *point = '\0';
        return OK;
    }
    return ERR_BUF_TOO_SMALL;
}
