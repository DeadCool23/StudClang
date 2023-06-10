#include "errcodes.h"
#include "string_words.h"
#include "uwordsc.h"
#include <stdio.h>

int main(void)
{
    char string[STR_LEN + 1];
    int err = string_input(string, STR_LEN + 1);
    if (err != OK)
    {
        error_message(err);
        return err;
    }
    char words[WORD_COUNT][WORD_LEN + 1];
    size_t uwords_count, words_count = 0;
    err = parse_string_to_words(string, words, &words_count);
    if (err != OK)
    {
        error_message(err);
        return err;
    }
    if (words_count == 0)
    {
        printf("No words in string\n");
        return NO_WORDS;
    }
    int word_cnt[WORD_COUNT];
    char uwords[WORD_COUNT][WORD_LEN + 1];
    uwordsc(word_cnt, words, words_count, uwords, &uwords_count);
    words_count_output(uwords, word_cnt, uwords_count);
    return OK;
}

