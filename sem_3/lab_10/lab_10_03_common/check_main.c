#include <check.h>
#include <stdlib.h>

#include "check_add_del.h"
#include "check_min_max.h"
#include "check_find_each.h"
#include "check_create_destroy.h"

int main(void) {
    SRunner *runner;
    runner = srunner_create(assoc_array_create_suite());
    srunner_add_suite(runner, assoc_array_destoy_suite());
    srunner_add_suite(runner, assoc_array_insert_suite());
    srunner_add_suite(runner, assoc_array_remove_suite());
    srunner_add_suite(runner, assoc_array_find_suite());
    srunner_add_suite(runner, assoc_array_clear_suite());
    srunner_add_suite(runner, assoc_array_each_suite());
    srunner_add_suite(runner, assoc_array_min_suite());
    srunner_add_suite(runner, assoc_array_max_suite());

    srunner_run_all(runner, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
