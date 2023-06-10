#include "errs.h"
#include "calculate.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return ERR_PARAM;
    }

    FILE *file;

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Can't open file: %s\n", argv[1]);
        return ERR_PARAM;
    }

    double avg, disp;
    size_t n = 0;
    int err = OK;

    err = calc_avg(file, &avg, &n);
    if (err != OK)
    {
        calc_errs(err);
        return err;
    }
    rewind(file);
    err = calc_disp(file, avg, n, &disp);
    if (err != OK)
    {
        calc_errs(err);
        return err;
    }

    fclose(file);

    fprintf(stdout, "Dispersion: %lf\n", disp);

    return OK;
}
