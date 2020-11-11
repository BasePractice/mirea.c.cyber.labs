#include <catch2/catch.hpp>
#include "base.h"

extern "C" {
double CALL(task)(double x, double eps);
double CALL(initiate_x)();
}

TEST_CASE("Лабораторная.01", "Задание." STR(TASK)) {
    double x = CALL(initiate_x)();
    double eps = EPS;
    double calculated = CALL(task)(x, eps);
    REQUIRE(x);
    REQUIRE(eps);
    REQUIRE(calculated);
    INFO("Результат расчета при X = " << x << ", Eps = " << eps << " равен " << calculated);
}

