#include <stdbool.h>
#include "my_string.h"

char *my_strpbrk(const char *str, const char *control)
{
    for (size_t i = 0; str[i] != '\0'; i++)
        for (size_t j = 0; control[j] != '\0'; j++)
            if (str[i] == control[j])
                return (char *)(str + i);
    return NULL;
}

size_t my_strspn(const char *str, const char *control)
{
    size_t ln = 0;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        bool char_in = false;
        for (size_t j = 0; control[j] != '\0'; j++)
            if (str[i] == control[j])
                char_in = true;

        if (!char_in)
            return ln;

        ++ln;
    }
    return ln;
}

size_t my_strcspn(const char *str, const char *control)
{
    size_t ln = 0;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        bool char_in = false;
        for (size_t j = 0; control[j] != '\0'; j++)
            if (str[i] == control[j])
                char_in = true;

        if (char_in)
            return ln;

        ++ln;
    }
    return ln;
}

char *my_strchr(const char *str, int val)
{
    size_t i;
    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == val)
            return (char *)(str + i);

    if (val == '\0')
        return (char *)(str + i);

    return NULL;
}

char *my_strrchr(const char *str, int ch)
{
    size_t i;
    const char *char_entry = NULL;
    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == ch)
            char_entry = str + i;

    if (ch == '\0')
        return (char *)(str + i);

    return (char *) char_entry;
}
