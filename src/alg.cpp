// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <cmath>
double pown(double value, uint16_t n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return value;
    }
    return pow(value, n);
}

uint64_t fact(uint16_t n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double exp = 1;
    for (uint16_t i = 1; i <= count; ++i) {
        exp += calcItem(x, i);
    }
    return exp;
}

double sinn(double x, uint16_t count) {
    double sin = x;
    for (uint16_t i = 2; i <= count; ++i) {
        sin += pow(-1, i - 1) * (pow(x, 2 * i - 1) / fact(2 * i - 1));
    }
    return sin;
}

double cosn(double x, uint16_t count) {
    double cos = 1;
    for (uint16_t i = 2; i <= count; ++i) {
        cos += pow(-1, i - 1) * (pow(x, 2 * i - 2) / fact(2 * i - 2));
    }
    return cos;
}
