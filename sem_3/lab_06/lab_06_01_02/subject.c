#include "subject.h"

#include <string.h>

err_t subject_read(FILE *file, subject_t *ptr_subj)
{
    char name[SUBJECT_NAME_LEN + 1];
    double weight, volume;

    char tmp[2];

    if (!fgets(name, SUBJECT_NAME_LEN + 1, file))
        return ERR_IO;

    char *name_end = strchr(name, '\n');
    if (name_end == NULL)
        return ERR_RANGE;
    else
        *name_end = '\0';
    if (!strlen(name))
        return ERR_IO;

    strcpy(ptr_subj->name, name);

    if (fscanf(file, "%lf%lf", &weight, &volume) != 2)
        return ERR_IO;

    if (weight <= 0 || volume <= 0)
        return ERR_RANGE;

    ptr_subj->weight = weight;
    ptr_subj->volume = volume;

    fgets(tmp, sizeof(tmp), file);

    return OK;
}

err_t subject_print(FILE *file, const subject_t *ptr_subj)
{
    fprintf(file, "%s\n", ptr_subj->name);
    fprintf(file, "%lf\n", ptr_subj->weight);
    fprintf(file, "%lf\n", ptr_subj->volume);
    return OK;
}

bool substr_search_in_name(const subject_t *ptr_subj, const char *substr)
{
    /// false возвращается если после работы программы подстрока не нашлась или нашлась но не в начале имени объекта, иначе выводится true
    return strstr(ptr_subj->name, substr) == NULL || strstr(ptr_subj->name, substr) != ptr_subj->name ? false : true;
}

double subject_density_calc(const subject_t *ptr_subj)
{
    return ptr_subj->weight / ptr_subj->volume;
}
