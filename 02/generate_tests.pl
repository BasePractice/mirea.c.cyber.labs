#!/usr/bin/perl
use strict;
use warnings;

sub generate_test {
    my ($id) = $_[0];
    $id = sprintf("%02d", $id);
    return qq|

    int* DIRECT_CALL($id, task)(int *array, size_t size, int *result_size);
    int* DIRECT_CALL($id, generate_array)(size_t *l_size);

    START_TEST(unit_$id)
    {
        size_t size  = 0;
        int   *array = DIRECT_CALL($id, generate_array)(&size), *result, result_size = 0;
        ck_assert(0 != array);
        result = DIRECT_CALL($id, task)(array, size, &result_size);
        ck_assert(0 != result);
        destroy_array(array);
        destroy_array(result);
    }
    END_TEST
|;
}

my $content = qq|#include <check.h>
#include "base.h"

|;
my $case = qq|
Suite *main_suite() {
    Suite *suite;
    TCase *core_case;

    suite = suite_create("[Lab.02]");
    core_case = tcase_create("unit_tasks");
|;
for (my $i = 1; $i <= 36; $i++) {
    my $id = sprintf("%02d", $i);
    $content .= &generate_test($i);
    $case .= qq|tcase_add_test(core_case, unit_$id);\n|;
}
$case .= qq|
    suite_add_tcase(suite, core_case);
    return suite;
}
|;

print $content;
print $case;
