#!/usr/bin/perl
use strict;
use warnings;

sub generate_test {
    my ($id) = $_[0];
    $id = sprintf("%02d", $id);
    return qq|
       extern "C" {
        double DIRECT_CALL($id, task)(double x, double eps);
        double DIRECT_CALL($id, base)(double x, double eps);
        double DIRECT_CALL($id, initiate_x)();
       }

       TEST_CASE("Task.$id", "[Lab.01]") {
        double x = DIRECT_CALL($id, initiate_x)();
        double eps = EPS;
        double custom = DIRECT_CALL($id, task)(x, eps);
        REQUIRE(x);
        REQUIRE(eps);
        REQUIRE(custom);
        INFO("Результат самописный  X = " << x << " равен " << custom);
        double system = DIRECT_CALL($id, base)(x, eps);
        INFO("Результат стандартный X = " << x << " равен " << system);
        REQUIRE( abs(custom - system) <= eps );
       }
|;
}

my $content = qq|#include <catch2/catch.hpp>
#include "base.h"

|;
for (my $i = 1; $i <= 2; $i++) {
    $content .= &generate_test($i);
}

print $content;
