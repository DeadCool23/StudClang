#include <stdio.h>
#include "testing.h"
#include "errcodes.h"

int main(void)
{
    size_t err_cnt = 0;
    diff_sting(&err_cnt);
    printf("Errors in fucnction working: %zu\n", err_cnt);
    return OK;
}
