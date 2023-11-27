#include "subject.h"

#include <math.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

err_t subj_init(subject_t *subj, const char *name, double weight, double volume)
{
    char *tmp = strdup(name);
    if (!tmp) 
        return ERR_MEM;

    free_subj(subj);
    subj->name = tmp;
    subj->weight = weight;
    subj->volume = volume;
    return OK;
}

err_t subj_cpy(subject_t *dst, const subject_t *src)
{ 
    return subj_init(dst, src->name, src->weight, src->volume); 
}

void free_subj(subject_t *subj)
{
    free(subj->name);
    subj->weight = subj->volume = 0;
    subj->name = NULL;
}

err_t subject_read(FILE *file, subject_t *ptr_subj)
{
    ssize_t read;
    err_t err = OK;
    size_t len = 0;
    char *name = NULL;
    double weight, volume;

    // char tmp[2];

    if ((read = getline(&name, &len, file)) == -1)
        err = ERR_IO;
    
    if (!err)
    {
        char *name_end = strchr(name, '\n');
        if (name_end == NULL)
            err = ERR_IO;
        else
            *name_end = '\0';
        
        if (!err)
        {
            if (!strlen(name))
                err = ERR_IO;
            
            if (!err)
            {
                if (fscanf(file, "%lf%lf\n", &weight, &volume) != 2)
                    err = ERR_IO;

                if (!err)
                    if (weight <= 0 || volume <= 0)
                        err = ERR_RANGE;

                // fgets(tmp, sizeof(tmp), file);
                // getc(file);

                if (!err)
                    err = subj_init(ptr_subj, name, weight, volume);
            }
        }
    }

    free(name);
    return err;
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
    return ((strstr(ptr_subj->name, substr) == NULL) || (strstr(ptr_subj->name, substr) != ptr_subj->name)) ? false : true;
}

int subjs_cmp(const subject_t *left, const subject_t *right)
{
#define EPS 1e-16
    double ldensity = subject_density_calc(left);
    double rdensity = subject_density_calc(right);
    if (ldensity > rdensity)
        return 1;
    else if (fabs(ldensity - rdensity) < EPS)
        return 0;
    else
        return -1;
}

double subject_density_calc(const subject_t *ptr_subj)
{
    return ptr_subj->weight / ptr_subj->volume;
}
