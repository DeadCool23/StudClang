#include <stdio.h>
#include <stdbool.h>

#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2
#define ERR_COUNT 3

#define N 10

//Ввод длины массива
int input_len(size_t *n);

//Ввод массива
int input_arr(int *p_beg, const int *p_end);

//Поиск максимальной суммы равноудаленных от центра элементов массива
int max_side_sum(const int *p_beg, const int *p_end);

int main(void)
{
    int a[N];
    int *p_beg = a, *p_end;
    size_t n;
    int err = input_len(&n);
    if (err != OK)
    {
        if (err == ERR_IO)
        {
            printf("IO Error\n");
            return ERR_IO;
        }
        if (err == ERR_RANGE)
        {
            printf("Length is out of range\n");
            return ERR_RANGE;
        }
    }
    p_end = p_beg + n;
    err = input_arr(p_beg, p_end);
    if (err != OK)
    {
        printf("IO Error");
        return err;
    }
    int max = max_side_sum(p_beg, p_end);
    printf("Max: %d", max);
    return OK;
}

int input_len(size_t *n)
{
    printf("Input len: ");
    int len;
    int rc = scanf("%d", &len);
    if (rc != 1)
    {
        return ERR_IO;
    }
    if (len <= 0 || len > N)
    {
        return ERR_RANGE;
    }
    *n = (size_t) len;
    return OK;
}

int input_arr(int *p_beg, const int *p_end)
{
    for (int *p_cur = p_beg; p_cur < p_end; p_cur++)
    {
        if (scanf("%d", p_cur) != 1)
            return ERR_IO;
    }
    return OK;
}

int max_side_sum(const int *p_beg, const int *p_end)
{
    int tmp, max = 0;
    bool is_max = false;
    int const *ptmp_beg = p_beg;
    int const *ptmp_end = p_end - 1;

    while (ptmp_beg <= ptmp_end)
    {
        tmp = *ptmp_beg + *ptmp_end;
        if (tmp > max || !is_max)
        {
            max = tmp;
            is_max = true;
        }
        ptmp_beg++;
        ptmp_end--;
    }
    return max;
}
