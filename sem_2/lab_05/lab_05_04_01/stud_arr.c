#include <string.h>
#include "stud.h"
#include "stud_arr.h"
#include "errs.h"

int get_students(FILE *stud_file, stud_t *students, size_t *studs_cnt)
{
    size_t i = 0;
    while (!stud_read(students + i, stud_file))
        i++;
    *studs_cnt = i;
    if ((*studs_cnt) == 0)
        return ERR_DATA;
    return OK;
}

int fprint_needed_students(const stud_t *students, size_t stud_cnt, FILE *new_file, const char *substr)
{
    int nsutd = 0;
    for (size_t i = 0; i < stud_cnt; i++)
    {
        if (!stud_cmp_surname_substr(students + i, substr))
        {
            stud_fprint(students + i, new_file);
            nsutd++;
        }
    }
    return nsutd != 0 ? OK : ERR_DATA;
}

