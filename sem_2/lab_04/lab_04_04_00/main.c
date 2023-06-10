#include <stdio.h>
#include "errcodes.h"
#include "ip_search.h"
#include "stringin.h"

int main(void)
{
    char str[STR_LEN + 1];
    int err = string_input(str, STR_LEN + 1);
    if (err != OK)
        return err;
    space_del(str);
    if (is_ip(str))
        printf("YES\n");
    else
        printf("NO\n");
    return OK;
}
