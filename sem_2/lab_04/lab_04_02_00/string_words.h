#ifndef SRING_WORDS_H
#define SRING_WORDS_H

#include <stddef.h>

/**
 * @def DELIMS
 * Знаки разделения слов
 * @def STR_LEN
 * Максимальная длина строки
 * @def WORD_LEN
 * Максимальный размер слова
 * @def WORD_COUNT
 * Кол-во слов в строке
 */
#define DELIMS " .,;:!?-"
#define STR_LEN 256
#define WORD_LEN 16
#define WORD_COUNT (STR_LEN / 2)

/**
 * Функция ввода строки
 * @param[out] sting - Строка
 * @param[in] string_size - Максимальный размер строки
 * @return Код ошибки
 */
int string_input(char *sting, size_t string_size);

/**
 * @brief Функция поиска адрессов начала и конца нового слова
 *
 * @param[in] str - строка
 * @param[out] pbeg - адресс начала нового слова
 * @param[out] pend - адресс конца нового слова
 */
void get_next_word(char *str, char **pbeg, char **pend);

/**
 * @brief Функция для копирования слова в заданноее место
 *
 * @param[in] pbeg - адрес начала копируемого слова
 * @param[in] pend - адрес конца копируемого слова
 * @param[in] word_size - размер слова
 * @param[out] word - место для копирования слова
 * @return Код ошибки
 */
int copy_word(const char *pbeg, const char *pend, char *word, size_t word_size);

/**
 * @brief Функция разделения строки на массив слов
 *
 * @param[in] str - строка
 * @param[out] words - массив слов
 * @param[out] words_n - кол-во слов
 * @return Код ошибки
 */
int parse_string_to_words(char *str, char words[][WORD_LEN + 1], size_t *words_n);

#endif //SRING_WORDS_H
