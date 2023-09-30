#include <check.h>

#include "check_filter.h"
#include "check_sort.h"

int main(void) {
    SRunner *runner;
    runner = srunner_create(double_compare_suite());
    srunner_add_suite(runner, char_compare_suite());
    srunner_add_suite(runner, int_compare_suite());
    srunner_add_suite(runner, mysort_suite());
    srunner_add_suite(runner, sum_suite());
    srunner_add_suite(runner, key_suite());

    srunner_run_all(runner, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
