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
    char *word;
    size_t n = 0;
    int err = OK;
    
    word = strtok(str, DELIMS);
    while (word != 0)
    {
        if (n < WORD_COUNT)
        {
            err = copy_word(word, words[n], (size_t)WORD_LEN);
            if (err == OK)
                n++;
            else
                return err;
        }
        else
            return TOO_MUCH_WORDS;
        word = strtok(0, DELIMS);
    }
    *words_n = n;
    return err;
}

int copy_word(const char *word, char *words_data, size_t etalon_word_len)
{
    size_t word_len = strlen(word);
    
    if (word_len > etalon_word_len)
        return ERR_BUF_TOO_SMALL;
    
    strncpy(words_data, word, etalon_word_len);
    words_data[etalon_word_len] = '\0';
    
    return OK;
}

