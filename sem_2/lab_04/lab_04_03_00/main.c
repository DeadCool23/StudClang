#include "errcodes.h"
#include "string_words.h"
#include "first_letter_del.h"
#include <stdio.h>

int main(void)
{
    char string[STR_LEN + 1];
    int err = string_input(string, STR_LEN + 1);
    if (err != OK)
    {
        input_error_message(err);
        return err;
    }
    char words[WORD_COUNT][WORD_LEN + 1];
    size_t words_count = 0;
    err = parse_string_to_words(string, words, &words_count);
    if (err != OK)
    {
        words_error_message(err);
        return err;
    }
    if (words_count == 0)
    {
        printf("No words in string\n");
        return NO_WORDS;
    }
    char new_str[STR_LEN + 1];
    new_str[0] = 0;
    err = del_last_word(words, words_count, new_str);
    if (err != OK)
    {
        words_letter_error_message(err);
        return err;
    }
    printf("Result: %s\n", new_str);
    return OK;
}

