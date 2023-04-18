#include <stdio.h>

#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2
#define ERR_COUNT 3

#define N 10

//Ввод длины массива
int input_len(size_t *n);

//Ввод массива
int input_arr(int *p_beg, const int *p_end);

/*
Сумма по формуле: a[0] + a[0]*a[1] + .. a[0]*[1]*..*a[m]
где m - индекс первого отрицателного или последнего(при отсутствии отрицательных) элемента массива
*/
int sum_of_pr(const int *p_beg, const int *p_end);

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
    int sum = sum_of_pr(p_beg, p_end);
    printf("Sum: %d", sum);
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

int sum_of_pr(const int *p_beg, const int *p_end)
{
    int tmp = 1, sum = 0;
    int const *p_cur = p_beg;

    while (p_cur < p_end)
    {
        tmp *= *p_cur;
        sum += tmp;
        //Проверка элемента на отрицательность
        if (*p_cur < 0)
        {
            p_cur = p_end; //Переходим к концу массива
        }
        else
        {
            p_cur++; //Переходим к следующему элементу
        }
    }
    return sum;
}
