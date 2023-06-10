#include <stdio.h>
#include <string.h>
#include "stud_arr.h"
#include "errs.h"
#include "binwork.h"

int main(int argc, char **argv)
{
    if (argc < 3)
        return ERR_PARAM;
    
    FILE *file;
    int err = OK;
    if (strcmp(argv[1], "ft") == 0)
    {
        if (argc != 5)
            return ERR_PARAM;
        if (!strlen(argv[4]))
            return ERR_PARAM;
        file = fopen(argv[2], "r");
        FILE *wfile = fopen(argv[3], "w");
        CHECK_FILES(file, wfile);
        stud_t studs[STUD_COUNT];
        size_t stud_cnt;
        if (err == OK)
        {
            err = get_students(file, studs, &stud_cnt);
            if (err == OK)
                err = fprint_needed_students(studs, stud_cnt, wfile, argv[4]);
        }
        fclose(wfile);
    }
    else if (strcmp(argv[1], "sb") == 0) 
    {
        file = fopen(argv[2], "rb+");
        CHECK_FILE(file);
        err = fb_sort_by_fullname(file);
    }
    else
        return ERR_KEY;

    fclose(file);
    ERR_CHECK(err);
    return OK;
}

