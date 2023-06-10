#include "uwordsc.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>

void uwordsc(int uwordc[], char words[][WORD_LEN + 1], size_t words_n, char uwords[][WORD_LEN + 1], size_t *uwords_n)
{
    *uwords_n = 0;
    for (size_t i = 0; i < words_n; i++)
    {
        if (is_uniq(uwords, *uwords_n, words[i]))
        {
            uwordc[*uwords_n] = 1;
            strcpy(uwords[(*uwords_n)++], words[i]);
            for (size_t j = i + 1; j < words_n; j++)
            {
                if (strcmp(words[i], words[j]) == 0)
                    ++uwordc[i];
            }
        }
    }
}

bool is_uniq(char uwords[][WORD_LEN + 1], size_t uwords_n, const char *word)
{
    for (size_t i = 0; i < uwords_n; i++)
        if (strcmp(word, uwords[i]) == 0)
            return false;
    return true;
}

void words_count_output(char words[][WORD_LEN + 1], const int words_count[], size_t words_n)
{
    printf("Result: \n");
    for (size_t i = 0; i < words_n; i++)
        printf("%s %d\n", words[i], words_count[i]);
}
