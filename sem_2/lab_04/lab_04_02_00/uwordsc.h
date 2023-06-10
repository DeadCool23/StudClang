#ifndef UWORDSC_H
#define UWORDSC_H

#include <stdbool.h>
#include <stddef.h>
#include "string_words.h"

/**
 * @brief Функция считает кол-во втреч каждого слова и записывает их в массив уникальных слов 
 *
 * @param[out] uwordc - кол-во встреч слова в строке
 * @param[in,out] words - массив слов
 * @param[in,out] words_n - кол-во слов
 */
void uwordsc(int uwordc[], char words[][WORD_LEN + 1], size_t words_n, char uwords[][WORD_LEN + 1], size_t *uwords_n);

/**
 * @brief Функция проверки слова на уникальность
 *
 * @param[in] uwords - массив уникальных слов
 * @param[in] uwords_n - кол-во уникальных слов
 * @param[in] word - проверяемое слово
 * @return Булевое значение 
 */
bool is_uniq(char uwords[][WORD_LEN + 1], size_t uwords_n, const char *word);

/**
 * @brief Процедура вывода слов и их кол-ва повторений по заданной маске
 *
 * @details Маска: "Result: word_1 count_1\nword_2 count_2\n...\nword_n count_n"
 * @param[in] words - массив уникальных слов
 * @param[in] words_count - массив кол-ва повторений слов
 * @param[in] words_n - кол-во слов
 */
void words_count_output(char words[][WORD_LEN + 1], const int words_count[], size_t words_n);

#endif //UWORDSC_H
