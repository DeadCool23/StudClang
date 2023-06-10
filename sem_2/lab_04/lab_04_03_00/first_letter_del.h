#ifndef FIRST_LETTER_DEL_H
#define FIRST_LETTER_DEL_H

#include "string_words.h"

/**
 * @brief Функция удаления букв из слова по определенному условию
 *
 * @details Условие: удаление всех вхождений первой буквы слова
 * @param[in,out] word - слово
 */
void del_same_first_letter(char *word);

/**
 * @brief Функция создает новую строку на основе условия
 *
 * @details Условие: Новая строка содержит слова отлчные от последнего
 * @details Примечание: Слова записываются в новую строку в обратном порядке
 *
 * @param[in] words - массив слов
 * @param[in] words_count - кол-во слов
 * @param[out] new_str - новая строка
 */
int del_last_word(char words[][WORD_LEN + 1], size_t words_count, char *new_str);

#endif //FIRST_LETTER_DEL_H

