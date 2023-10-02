#include <check.h>
#include <stddef.h>

#include "check_filter.h"
#include "check_sort.h"

int main(void) {
    SRunner *runner;

    Suite *(*unit_tests[])(void) = {
        double_compare_suite, char_compare_suite, int_compare_suite,
        mysort_suite, sum_suite, key_suite
    };
    size_t tests_cnt = sizeof(unit_tests) / sizeof(*unit_tests);

    int number_failed = 0;

    for (size_t i = 0; i < tests_cnt; i++) {
        runner = srunner_create(unit_tests[i]());
        srunner_run_all(runner, CK_VERBOSE);
        number_failed += srunner_ntests_failed(runner);
        srunner_free(runner);
    }

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
