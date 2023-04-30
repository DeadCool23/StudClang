#include "testing.h"
#include <string.h>
#include "my_string.h"

void diff_sting(size_t *errors)
{
    diff_strpbrk(errors);
    diff_strspn(errors);
    diff_strcspn(errors);
    diff_strchr(errors);
    diff_strrchr(errors);
}

void diff_strpbrk(size_t *errs)
{
    char str[TEST_COUNT][STR_LEN] = {
        "Hello world",
        "Hello world",
        "\n",
        ""
    };
    char control[TEST_COUNT][STR_LEN] = {
        "dw", "afp", "\t\n", ""
    };
    /// Сравнение работы strpbrk и my_strpbrk
    for (size_t i = 0; i < TEST_COUNT; i++)
        if (strpbrk(str[i], control[i]) != my_strpbrk(str[i], control[i]))
            ++(*errs);
}

void diff_strspn(size_t *errs)
{
    char str[TEST_COUNT][STR_LEN] = {
        "Hello world",
        "Hello world",
        "\na",
        ""
    };
    char control[TEST_COUNT][STR_LEN] = {
        "Helo", "wq", "\t\n", ""
    };
    /// Сравнение работы strspn и my_strspn
    for (size_t i = 0; i < TEST_COUNT; i++)
        if (strspn(str[i], control[i]) != my_strspn(str[i], control[i]))
            ++(*errs);
}

void diff_strcspn(size_t *errs)
{
    char str[TEST_COUNT][STR_LEN] = {
        "Hello world",
        "Hello world",
        "a\n",
        ""
    };
    char control[TEST_COUNT][STR_LEN] = {
        "Helo", "wq", "\t\n", ""
    };
    /// Сравнение работы strcspn и my_strcspn
    for (size_t i = 0; i < TEST_COUNT; i++)
        if (strcspn(str[i], control[i]) != my_strcspn(str[i], control[i]))
            ++(*errs);
}

void diff_strchr(size_t *errs)
{
    char str[TEST_COUNT][STR_LEN] = {
        "Hello world",
        "Hello world",
        "Hello world",
        "\t\n\tabc\n",
    };
    int val[TEST_COUNT] = {
        'l', 'q', '\0', '\n'
    };
    /// Сравнение работы strchr и my_strchr
    for (size_t i = 0; i < TEST_COUNT; i++)
        if (strchr(str[i], val[i]) != my_strchr(str[i], val[i]))
            ++(*errs);
}

void diff_strrchr(size_t *errs)
{
    char str[TEST_COUNT][STR_LEN] = {
        "Hello world",
        "Hello world",
        "Hello world",
        "\t\n\tabc\n",
    };
    int val[TEST_COUNT] = {
        'l', 'q', '\0', '\n'
    };
    /// Сравнение работы strrchr и my_strrchr
    for (size_t i = 0; i < TEST_COUNT; i++)
        if (strrchr(str[i], val[i]) != my_strrchr(str[i], val[i]))
            ++(*errs);
}