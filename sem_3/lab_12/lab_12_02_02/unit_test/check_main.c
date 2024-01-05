#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "check_uniq.h"
#include "check_fibonacci.h"

typedef Suite *(*suite_create_t)(void);

int main(void) {
    SRunner *runner;

    suite_create_t unit_tests[] = {
        fill_fibonacci_suite,
        uniqcpy_suite
    };
    size_t tests_cnt = sizeof(unit_tests) / sizeof(*unit_tests);

    int number_failed = 0;

    for (size_t i = 0; i < tests_cnt; i++) {
        puts("\n");
        runner = srunner_create(unit_tests[i]());
        srunner_run_all(runner, CK_NORMAL);
        number_failed += srunner_ntests_failed(runner);
        srunner_free(runner);
    }

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
