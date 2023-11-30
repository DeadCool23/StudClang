#include <stdlib.h>
#include "check_my_snprintf.h"

int main(void) {
    SRunner *runner;
    runner = srunner_create(my_snprintf_suite());

    srunner_run_all(runner, CK_NORMAL);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
