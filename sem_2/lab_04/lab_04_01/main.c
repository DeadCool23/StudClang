#include <stdio.h>
#include "testing.h"

int main(void)
{
    size_t err_cnt = 0;
    diff_sting(&err_cnt);
    printf("Errors in function working: %zu\n", err_cnt);
    return err_cnt;
}
