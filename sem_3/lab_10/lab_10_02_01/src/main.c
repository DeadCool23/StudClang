#include "errs.h"
#include "polinom.h"
#include "command.h"

#include <stdlib.h>
#include <string.h>

int main(void)
{
    err_t err = OK;
    char cmd[CMD_LEN + 1] = "";
    err = fread_cmd(stdin, cmd);
    if (err)
        return err;
    
    polinom_t *poli = polinom_init();
    err = fread_polinom(stdin, &poli);
    if (!err)
    {
        if (!strcmp(cmd, "val"))
        {
            int value;
            err = !err ? ((scanf("%d", &value) == 1) ? OK : ERR_IO) : err;
            if (!err)
                printf("%d\n", val(poli, value));
        }
        else if (!strcmp(cmd, "ddx"))
        {
            poli = ddx(poli);
            fprint_polinom(stdout, poli);
        }
        else if (!strcmp(cmd, "sum"))
        {
            polinom_t *other_poli = polinom_init();
            err = fread_polinom(stdin, &other_poli);
            if (!err)
            {
                poli = sum(poli, &other_poli);
                fprint_polinom(stdout, poli);
            }
            free_polinom(other_poli);
        }
        else if (!strcmp(cmd, "dvd"))
        {
            polinom_t *other_poli = dvd(&poli);
            if (poli)
                fprint_polinom(stdout, poli);
            if (other_poli)
                fprint_polinom(stdout, other_poli);
            free_polinom(other_poli);
        }
        else
            err = ERR_IO;
    }
    
    free_polinom(poli);
    return err;
}
