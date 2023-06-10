#include "stud.h"
#include "errs.h"
#include "marks.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int stud_read(stud_t *student, FILE *stud_file)
{
    memset(student, 0, sizeof(stud_t));
    int err = OK;
    char surname[SURNAME_LEN + 1];
    char name[NAME_LEN + 1];

    if (!fgets(surname, SURNAME_LEN, stud_file))
        return ERR_READ;
    err = check_initials_len(surname, SURNAME_LEN);
    ERR_CHECK(err);

    if (!fgets(name, NAME_LEN, stud_file))
        return ERR_READ;
    err = check_initials_len(name, NAME_LEN);
    ERR_CHECK(err);
    
    char tmp[3];
    uint32_t marks[MARKS_COUNT];
    err = get_marks(marks, MARKS_COUNT, stud_file);
    ERR_CHECK(err);

    if (!fgets(tmp, sizeof(tmp), stud_file))
        return ERR_DATA;
    strcpy(student->surname, surname);
    strcpy(student->name, name);
    memcpy(student->marks, marks, sizeof(marks));
    return OK;
}

void stud_fprint(const stud_t *student, FILE *new_file)
{
    fprintf(new_file, "%s\n", student->surname);
    fprintf(new_file, "%s\n", student->name);
    fprint_marks(student->marks, MARKS_COUNT, new_file);
}

int stud_cmp_by_fullname(const stud_t *student_left, const stud_t *student_right)
{
    int cmp = stud_cmp_by_surname(student_left, student_right);
    if (!cmp)
        return stud_cmp_by_name(student_left, student_right);
    return cmp;
}

int stud_cmp_by_surname(const stud_t *student_left, const stud_t *student_right)
{
    return strcmp(student_left->surname, student_right->surname);
}

int stud_cmp_by_name(const stud_t *student_left, const stud_t *student_right)
{
    return strcmp(student_left->name, student_right->name);
}

int check_initials_len(char *initial, size_t init_len)
{
    size_t len = strlen(initial);
    if (initial[len - 1] == '\n')
    {
        initial[len - 1] = 0;
        len--;
    }
    if (!len || len >= init_len)
        return ERR_DATA;

    return OK;
}

int stud_cmp_surname_substr(const stud_t *student, const char *substr)
{
    if (strlen(student->surname) < strlen(substr))
        return 1;
    return strncmp(student->surname, substr, strlen(substr));
}
