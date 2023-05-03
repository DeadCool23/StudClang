#include "errcodes.h"
#include <stdio.h>

void err_output(int err_code)
{
    if (err_code == ERR_IO)
        printf("IO Error\n");
    if (err_code == ERR_SIZE)
        printf("Size out of range\n");
    else
        printf("Undefined error\n");
}