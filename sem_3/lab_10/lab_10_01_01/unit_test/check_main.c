#include <check.h>
#include <stdlib.h>
#include "check_cmp.h"
#include "check_find.h"
#include "check_sort.h"
#include "check_insert.h"
#include "check_reverse.h"

int main(void) {
    SRunner *runner;
    runner = srunner_create(points_cmp_suite());
    srunner_add_suite(runner, dist_cmp_suite());
    srunner_add_suite(runner, reverse_suite());
    srunner_add_suite(runner, insert_suite());
    srunner_add_suite(runner, sorted_insert_suite());
    srunner_add_suite(runner, sort_suite());
    srunner_add_suite(runner, find_suite());

    srunner_run_all(runner, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
