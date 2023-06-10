#include "errcodes.h"
#include <stdio.h>

void input_error_message(int err_code)
{
    if (err_code == ERR_IO)
        printf("Input error\n");
    else if (err_code == ERR_BUF_TOO_SMALL)
        printf("String too long\n");
    else
        printf("Undefined error\n");
}

void words_error_message(int err_code)
{
    if (err_code == ERR_BUF_TOO_SMALL)
        printf("Words too long\n");
    else if (err_code == TOO_MUCH_WORDS)
        printf("Too much words in string\n");
    else
        printf("Undefined error\n");
}

void words_letter_error_message(int err_code)
{
    if (err_code == EMPTY_NEW_STRING)
        printf("New string is empty\n");
    else if (err_code == ERR_BUF_TOO_SMALL)
        printf("New string too long\n");
    else
        printf("Undefined error\n");
}

