#ifndef __TESTSORT_H__
#define __TESTSORT_H__

#include <check.h>

#include "sort.h"

Suite *double_compare_suite(void);
Suite *char_compare_suite(void);
Suite *int_compare_suite(void);
Suite *mysort_suite(void);

int double_compare(const void *left, const void *right);
int char_compare(const void *left, const void *right);

#endif  //__TESTSORT_H__

