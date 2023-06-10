#include <stdio.h>
#include "errcodes.h"

void error_message(int err_code)
{
    if (err_code == ERR_IO)
        printf("Input error\n");
    else if (err_code == ERR_BUF_TOO_SMALL)
        printf("String/words too long\n");
    else if (err_code == TOO_MUCH_WORDS)
        printf("Too much words in string\n");
    else
        printf("Undefined error\n");
}

