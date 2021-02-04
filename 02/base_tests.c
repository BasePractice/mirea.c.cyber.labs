#include <check.h>
#include "base.h"

START_TEST(unit_extract)
    {
        int numb[4] = {0, 0, 0, 0};

        extract(1234, numb, sizeof(numb) / sizeof(numb[0]));
        ck_assert_ptr_nonnull(numb);
        ck_assert(numb[0] == 1);
        ck_assert(numb[1] == 2);
        ck_assert(numb[2] == 3);
        ck_assert(numb[3] == 4);
    }
END_TEST

Suite *main_suite() {
    Suite *suite;
    TCase *core_case;

    suite = suite_create("Task.Base_[Lab.02]");
    core_case = tcase_create("unit_extract");
    tcase_add_test(core_case, unit_extract);
    suite_add_tcase(suite, core_case);
    return suite;
}
