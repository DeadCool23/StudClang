#include "errs.h"
#include "process.h"

int main(void) 
{
    size_t max_index;
    int err = process(stdin, &max_index);

    if (err != OK)
    {
        if (err == ERR_INPUT)
            fprintf(stderr, "Incorrect input\n");
        else
            fprintf(stderr, "Undefined error\n");
        return err;
    }

    fprintf(stdout, "Index of max num: %zu\n", max_index);

    return OK;
}
