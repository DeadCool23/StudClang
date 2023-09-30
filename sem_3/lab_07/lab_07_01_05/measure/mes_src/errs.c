#include "errs.h"

#include <stdio.h>

void err_message(err_t err)
{
    if (err == ERR_MEM)
        printf("ERROR: Cant allocate memory\n");
    if (err == ERR_KEY)
        printf("ERROR: Incorrect generation key\n");
    if (err == ERR_FILE)
        printf("ERROR: Can't open file\n");
}