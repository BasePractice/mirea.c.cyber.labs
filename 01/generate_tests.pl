#!/usr/bin/perl
use strict;
use warnings;

sub generate_test {
    my ($id) = $_[0];
    $id = sprintf("%02d", $id);
    return qq|
       double DIRECT_CALL($id, task)(double x, double eps, bool *divergent);
       double DIRECT_CALL($id, base)(double x, double eps);
       double DIRECT_CALL($id, initiate_x)();

       START_TEST(unit_$id)
       {
        bool divergent = false;
        double x = DIRECT_CALL($id, initiate_x)();
        double eps = EPS;
        double custom = DIRECT_CALL($id, task)(x, eps, &divergent);
        ck_assert(eps);
        ck_assert(custom);
        double system = DIRECT_CALL($id, base)(x, eps);
        if (divergent) {
          fprintf(stdout, "Ряд расходится");
        } else {
          ck_assert( abs(custom - system) <= eps );
        }
       }
       END_TEST
|;
}

my $content = qq|#include <check.h>
#include <stdio.h>
#include <stdlib.h>
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
    $case .= qq|tcase_add_test(core_case, unit_$id);\n|;
}
$case .= qq|
    suite_add_tcase(suite, core_case);
    return suite;
}
|;

print $content;
print $case;
