#include "errs.h"
#include "marks.h"
#include <inttypes.h>
#include <stdio.h>

int get_marks(uint32_t *marks, size_t marks_cnt, FILE *stud_file)
{
    uint32_t mark;
    for (size_t i = 0; i < marks_cnt; i++)
    {
        if (fscanf(stud_file, "%" SCNu32, &mark) != 1)
            return ERR_READ;
        marks[i] = mark;
    }
    return OK;
}

void fprint_marks(const uint32_t *marks, size_t marks_cnt, FILE *new_file)
{
    for (size_t i = 0; i < marks_cnt; i++)
        fprintf(new_file, "%" PRIu32 " ", marks[i]);
    fprintf(new_file, "\n");
}
