#!/usr/bin/perl
use strict;
use warnings;

sub generate_test {
    my ($id) = $_[0];
    $id = sprintf("%02d", $id);
    return qq|

    char * DIRECT_CALL($id, task)(struct Argument *args);
    void DIRECT_CALL($id, argument_create)(struct Argument *args);

    START_TEST(unit_$id)
    {
        struct Argument args = {0};
        char *result;

        DIRECT_CALL($id, argument_create)(&args);
        ck_assert(0 != args.text);
        result = DIRECT_CALL($id, task)(&args);
        ck_assert(0 != result);
        ck_assert(args.result == result);
        argument_destroy(&args);
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

    suite = suite_create("[Lab.03]");
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
