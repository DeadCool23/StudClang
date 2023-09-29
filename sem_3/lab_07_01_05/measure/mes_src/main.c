#include "errs.h"
#include "arrgen.h"
#include "getdata.h"

int main(void)
{
    err_t err = OK;
    err = get_mes_res(SORTED_GEN);
    if (err)
    {
        err_message(err);
        return err;
    }
    err = get_mes_res(REVERSE_GEN);
    if (err)
    {
        err_message(err);
        return err;
    }
    err = get_mes_res(RAND_GEN);
    if (err)
    {
        err_message(err);
        return err;
    }
    return OK;
}
