#include "first_letter_del.h"
#include "string_words.h"
#include "errcodes.h"
#include <string.h>

int del_last_word(char words[][WORD_LEN + 1], size_t words_count, char *new_str)
{
    char *last_word = words[words_count - 1];
    for (int i = (int)words_count - 2; i >= 0; i--)
    {
        if (strcmp(words[i], last_word))
        {
            del_same_first_letter(words[i]);
            if (strlen(new_str) + strlen(words[i]) > STR_LEN)
                return ERR_BUF_TOO_SMALL;
            strcat(new_str, words[i]);
            strcat(new_str, " ");
        }
    }
    if (strlen(new_str) == 0)
        return EMPTY_NEW_STRING;
    new_str[strlen(new_str) - 1] = 0;
    return OK;
}

void del_same_first_letter(char *word)
{
    char first_letter = word[0];
    size_t write_index = 0;
    for (size_t i = 1; word[i] != '\0'; i++)
    {
        if (word[i] != first_letter)
            word[++write_index] = word[i];
    }
    word[++write_index] = '\0';
}

