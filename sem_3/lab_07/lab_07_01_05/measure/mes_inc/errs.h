#ifndef MES_ERRS_H
#define MES_ERRS_H

typedef enum
{
    OK,
    ERR_MEM,
    ERR_KEY,
    ERR_FILE
} err_t;

void err_message(err_t err);

#endif //MES_ERRS_H