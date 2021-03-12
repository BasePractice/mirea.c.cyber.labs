#include <check.h>
#include "base.h"

START_TEST(unit_strlen)
    {

    }
END_TEST

Suite *main_suite() {
    Suite *suite;
    TCase *core_case;

    suite = suite_create("Task.Base_[Lab.03]");
    core_case = tcase_create("unit_strlen");
    tcase_add_test(core_case, unit_strlen);
    suite_add_tcase(suite, core_case);
    return suite;
}
