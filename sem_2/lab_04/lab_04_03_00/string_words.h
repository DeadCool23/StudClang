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
 * @param sting - Строка
 * @param string_size - Максимальный размер строки
 * @return Код ошибки
 */
int string_input(char *sting, size_t string_size);

/**
 * @brief Функция для копирования слова в массив
 *
 * @param[in] word - слово для копирования
 * @param[out] words_data - массив слов
 * @param[in] etalon_word_len - заданный максимальный размре слова
 * 
 * @return Код ошибки
 */
int copy_word(const char *word, char *words_data, size_t etalon_word_len);

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
