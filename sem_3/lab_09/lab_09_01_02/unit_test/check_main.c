#include <check.h>
#include <stdlib.h>

#include "check_subj.h"
#include "check_subjs.h"

typedef Suite *(*suite_create_t)(void);

int main(void) {
    SRunner *runner;

    suite_create_t unit_tests[] = {
        subj_init_suite, subj_cpy_suite, 
        subjs_cmp_suite, subj_density_calc_suite,
        subjects_sort_by_density_suite
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
