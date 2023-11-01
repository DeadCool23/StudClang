#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "check_math.h"
#include "check_process.h"

int main(void) {
    SRunner *runner;

    Suite *(*unit_tests[])(void) = {
        matrix_copy_suite, swap_rows_suite, 
        sum_suite, mult_suite, gauss_suite
    };
    size_t tests_cnt = sizeof(unit_tests) / sizeof(*unit_tests);

    int number_failed = 0;

    for (size_t i = 0; i < tests_cnt; i++) {
        printf("\n\n");
        runner = srunner_create(unit_tests[i]());
        srunner_run_all(runner, CK_VERBOSE);
        number_failed += srunner_ntests_failed(runner);
        srunner_free(runner);
    }

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
