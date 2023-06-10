#include "errs.h"
#include "process.h"
#include <stdio.h>

int process(FILE *f, size_t *max_index)
{
    *max_index = 0;
    size_t index = 0;
    int num, max_num = 0;

    while (fscanf(f, "%d", &num) == 1) 
    {
        index++;
        if (num > max_num || !(*max_index))
        {
            max_num = num;
            *max_index = index;
        }
    }

    if (index == 0)
        return ERR_INPUT;
    return OK;
}
