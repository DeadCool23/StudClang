#include <stdio.h>
#include <string.h>
#include "string_words.h"
#include "errcodes.h"

int string_input(char *string, size_t string_size)
{
    char *point;
    printf("Input string: ");
    if (!fgets(string, string_size, stdin))
        return ERR_IO;
    point = strrchr(string, '\n');
    if (point)
    {
        *point = '\0';
        return OK;
    }
    return ERR_BUF_TOO_SMALL;
}

int parse_string_to_words(char *str, char words[][WORD_LEN + 1], size_t *words_n)
{
    char *pbeg, *pend, *pcur = str;
    size_t n = 0;
    int err = OK;
    while (!err && pcur && *pcur)
    {
        get_next_word(pcur, &pbeg, &pend);
        if (pbeg)
        {
            if (n < WORD_COUNT)
            {
                err = copy_word(pbeg, pend, words[n], WORD_LEN);
                if (!err)
                    n++;
            }
            else
                return TOO_MUCH_WORDS;
        }
        pcur = pend;
    }
    if (!err)
    {
        *words_n = n;
    }
    return err;
}

int copy_word(const char *pbeg, const char *pend, char *word, size_t word_size)
{
    size_t word_len = pend - pbeg;

    if (word_len > word_size)
        return ERR_BUF_TOO_SMALL;

    for (size_t i = 0; i < word_len; i++)
        word[i] = pbeg[i];

    word[word_len] = '\0';

    return OK;
}

void get_next_word(char *str, char **pbeg, char **pend)
{
    char *pcur = str;
    *pbeg = *pend = 0;
    while (*pcur && strrchr(DELIMS, *pcur))
        pcur++;

    if (!*pcur)
        return;

    *pbeg = pcur;

    while (*pcur && !strrchr(DELIMS, *pcur))
        pcur++;

    *pend = pcur;
}

