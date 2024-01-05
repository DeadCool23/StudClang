#include <check.h>
#include <stdlib.h>
#include "check_polinom.h"

int main(void) {
    SRunner *runner;
    runner = srunner_create(val_suite());
    srunner_add_suite(runner, ddx_suite());
    srunner_add_suite(runner, sum_suite());
    srunner_add_suite(runner, dvd_suite());

    srunner_run_all(runner, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
