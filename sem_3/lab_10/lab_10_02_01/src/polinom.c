#include "polinom.h"
#include "nomen.h"

#include <math.h>

#include <stdlib.h>
#include <stdbool.h>

polinom_t *polinom_init(void)
{
    return NULL;
}

err_t fread_polinom(FILE *file, polinom_t **head)
{
    char end = 0;
    err_t err = OK;
    polinom_t *prev = *head;
    while (end != '\n' && !err)
    {
        int tmp_factor, tmp_power;
        if (fscanf(file, "%d %d%c", &tmp_factor, &tmp_power, &end) != 3)
            err = ERR_IO;
        else if (tmp_power >= 0)
        {
            nomen_t tmp_nomen = {
                .factor = tmp_factor,
                .power = tmp_power
            };
            polinom_t *new_nomen = nomen_create(&tmp_nomen);
            if (!new_nomen)
                err = ERR_MEM;
            else if (!prev)
            {
                *head = new_nomen;
                prev = *head;
            }
            else if (prev->nomen.power > tmp_power)
            {
                prev->next = new_nomen;
                prev = prev->next;
            }
            else
            {
                nomen_destroy(new_nomen);
                err = ERR_RANGE; 
            }
        }
    }

    return !err ? ((!*head) ? ERR_IO : err) : err;
}

void fprint_polinom(FILE *file, polinom_t *head)
{
    for (polinom_t *inomen = head; inomen != NULL; inomen = inomen->next)
    {
        fprint_nomen(file, inomen);
        fprintf(file, " ");
    }
    if (!head)
        fprintf(file, "0 0 ");
    fprintf(file, "L\n");
}

int val(polinom_t *head, int val)
{
    int res = 0;
    for (polinom_t *inomen = head; inomen; inomen = inomen->next)
        res += inomen->nomen.factor * (int)pow(val, inomen->nomen.power);
    return res;
}

polinom_t *ddx(polinom_t *head)
{
    polinom_t *prev = NULL;

    for (polinom_t *inomen = head; inomen;)
    {
        if (inomen->nomen.power)
        {
            inomen->nomen.factor *= inomen->nomen.power--;
            prev = inomen;
            inomen = inomen->next;
        }
        else
        {
            polinom_t *tmp_nomen = inomen;
            if (prev)
                prev->next = inomen->next;
            else
                head = inomen->next;
            inomen = inomen->next;
            nomen_destroy(tmp_nomen);
        }
    }
    return head;
}

polinom_t *sum(polinom_t *fst, polinom_t **scd)
{
    polinom_t *prev_nome = NULL; // Предыдущий элемент для первого полинома
    polinom_t *prev_other = NULL; // Предыдущий элемент для второго полинома
    polinom_t *inome_fst, *inome_scd; // Текущие элементы для обхода первого и второго полиномов
    polinom_t *sum_polinom = polinom_init(); // Результирующий полином

    // Обход обоих полиномов
    for (inome_fst = fst, inome_scd = *scd; inome_fst && inome_scd;)
    {
        polinom_t *add_nome = NULL; // Элемент для добавления в результирующий полином

        // Если степени элементов равны, их коэффициенты складываются
        if (inome_fst->nomen.power == inome_scd->nomen.power)
        {
            add_nome = inome_fst;
            add_nome->nomen.factor += inome_scd->nomen.factor;
            inome_fst = inome_fst->next;
            inome_scd = inome_scd->next; 
        }
        // Если степень первого элемента больше, он добавляется в результирующий полином
        else if (inome_fst->nomen.power > inome_scd->nomen.power)
        {
            add_nome = inome_fst;
            inome_fst = inome_fst->next;
        }
        // Если степень второго элемента больше, он добавляется в результирующий полином
        else
        {
            add_nome = inome_scd;
            inome_scd = inome_scd->next;
            // Удаление добавляемого в результат суммы члена из второго полинома 
            if (!prev_other)
            {
                *scd = inome_scd;
                prev_other = *scd;
            }
            else
            {
                prev_other->next = inome_scd;
                prev_other = prev_other->next;
            }
        }

        add_nome->next = NULL;

        // Добавление элемента в результирующий полином
        if (!prev_nome)
        {
            sum_polinom = add_nome;
            prev_nome = sum_polinom;
        }
        else
        {
            prev_nome->next = add_nome;
            prev_nome = prev_nome->next;
        }
    }

    // Добавление оставшихся элементов в результирующий полином
    if (prev_nome)
        prev_nome->next = inome_fst ? inome_fst : (inome_scd ? inome_scd : NULL);
    else
        sum_polinom = inome_fst ? inome_fst : (inome_scd ? inome_scd : NULL);
    
    // Очистка второго полинома
    if (inome_scd)
    {
        if (!prev_other)
            *scd = NULL;
        else
            prev_other->next = NULL;
    }

    return sum_polinom;
}

/**
 * @brief Функция проверки четности степени полинома
 * 
 * @param [in] nomen - Член
 * @return true если четная степень 
 * @return false если нечетная степень
 */
static bool is_even_power(const polinom_t *nomen)
{
    return nomen->nomen.power & 1 ? false : true;
}

polinom_t *dvd(polinom_t **head)
{
    polinom_t *prev = NULL;
    polinom_t *new_head = polinom_init();
    polinom_t *new_prev = NULL;

    for (polinom_t *inomen = *head; inomen;)
    {
        if (!is_even_power(inomen))
        {
            polinom_t *tmp_nomen = inomen;
            inomen = inomen->next;
            tmp_nomen->next = NULL;

            if (!new_prev)
            {
                new_head = tmp_nomen;
                new_prev = new_head;
            }
            else
            {
                new_prev->next = tmp_nomen;
                new_prev = new_prev->next;
            }

            if (!prev)
            {
                *head = inomen;
            }
            else
            {
                prev->next = inomen;
            }
        }
        else
        {
            prev = inomen;
            inomen = inomen->next;
        }
    }

    return new_head;
}



void free_polinom(polinom_t *head)
{
    for (polinom_t *inomen = head; inomen != NULL;)
    {
        polinom_t *tmp_nomen = inomen->next;
        nomen_destroy(inomen);
        inomen = tmp_nomen;
    }
    head = NULL;
}
