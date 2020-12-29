#include <assert.h>
#include <math.h>

#include "armstrong_numbers.h"

int num_digits_old(int candidate) { return log10(candidate) + 1; }

bool is_armstrong_number_old(int candidate) {
    if (candidate < 0)
        return false;
    if (candidate < 10)
        return true;
    if (candidate < 100)
        return false;
    // candidate >= 100:
    int n = candidate;
    int n_digits = num_digits_old(n);
    int sum = 0;
    while (n) {
        sum += pow(n % 10, n_digits);
        n /= 10;
    }
    return sum == candidate;
}

// See
// https://stackoverflow.com/questions/25892665/performance-of-log10-function-returning-an-int

unsigned int baseTwoDigits(unsigned int x) {
    return x ? 32 - __builtin_clz(x) : 0;
}

unsigned int num_digits(unsigned int x) {
    static const unsigned char guess[33] = {0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3,
                                            3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6,
                                            6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9};
    static const unsigned int tenToThe[] = {
        1,      10,      100,      1000,      10000,
        100000, 1000000, 10000000, 100000000, 1000000000,
    };
    unsigned int digits = guess[baseTwoDigits(x)];
    return digits + (x >= tenToThe[digits]);
}


uint64_t ipow2(uint8_t base, uint8_t exp) {
    assert(base <= 9 && exp <= 10);
    static const uint64_t powers[10][11] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,

        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,

        1,
        2,
        4,
        8,
        16,
        32,
        64,
        128,
        256,
        512,
        1024,

        1,
        3,
        3 * 3,
        3 * 3 * 3,
        3 * 3 * 3 * 3,
        3 * 3 * 3 * 3 * 3,
        3 * 3 * 3 * 3 * 3 * 3,
        3 * 3 * 3 * 3 * 3 * 3 * 3,
        3 * 3 * 3 * 3 * 3 * 3 * 3 * 3,
        3 * 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3,
        3 * 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3,

        1,
        4,
        4 * 4,
        4 * 4 * 4,
        4 * 4 * 4 * 4,
        4 * 4 * 4 * 4 * 4,
        4 * 4 * 4 * 4 * 4 * 4,
        4 * 4 * 4 * 4 * 4 * 4 * 4,
        4 * 4 * 4 * 4 * 4 * 4 * 4 * 4,
        4 * 4 * 4 * 4 * 4 * 4 * 4 * 4 * 4,
        4 * 4 * 4 * 4 * 4 * 4 * 4 * 4 * 4 * 4,

        1,
        5,
        5 * 5,
        5 * 5 * 5,
        5 * 5 * 5 * 5,
        5 * 5 * 5 * 5 * 5,
        5 * 5 * 5 * 5 * 5 * 5,
        5 * 5 * 5 * 5 * 5 * 5 * 5,
        5 * 5 * 5 * 5 * 5 * 5 * 5 * 5,
        5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5,
        5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5,

        1,
        6,
        6 * 6,
        6 * 6 * 6,
        6 * 6 * 6 * 6,
        6 * 6 * 6 * 6 * 6,
        6 * 6 * 6 * 6 * 6 * 6,
        6 * 6 * 6 * 6 * 6 * 6 * 6,
        6 * 6 * 6 * 6 * 6 * 6 * 6 * 6,
        6 * 6 * 6 * 6 * 6 * 6 * 6 * 6 * 6,
        6 * 6 * 6 * 6 * 6 * 6 * 6 * 6 * 6 * 6,

        1,
        7,
        7 * 7,
        7 * 7 * 7,
        7 * 7 * 7 * 7,
        7 * 7 * 7 * 7 * 7,
        7 * 7 * 7 * 7 * 7 * 7,
        7 * 7 * 7 * 7 * 7 * 7 * 7,
        7 * 7 * 7 * 7 * 7 * 7 * 7 * 7,
        7 * 7 * 7 * 7 * 7 * 7 * 7 * 7 * 7,
        7 * 7 * 7 * 7 * 7 * 7 * 7 * 7 * 7 * 7,

        1,
        8,
        8 * 8,
        8 * 8 * 8,
        8 * 8 * 8 * 8,
        8 * 8 * 8 * 8 * 8,
        8 * 8 * 8 * 8 * 8 * 8,
        8 * 8 * 8 * 8 * 8 * 8 * 8,
        8 * 8 * 8 * 8 * 8 * 8 * 8 * 8,
        8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8,
        8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8,

        1,
        9,
        9 * 9,
        9 * 9 * 9,
        9 * 9 * 9 * 9,
        9 * 9 * 9 * 9 * 9,
        9 * 9 * 9 * 9 * 9 * 9,
        9 * 9 * 9 * 9 * 9 * 9 * 9,
        9 * 9 * 9 * 9 * 9 * 9 * 9 * 9,
        9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9,
        9ul * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9,
    };
    return powers[base][exp];
}

bool is_armstrong_number(int candidate) {
    if (candidate < 0)
        return false;
    unsigned int n = candidate;
    unsigned int n_digits = num_digits(n);
    unsigned int sum = 0;
    for (; n; n /= 10) {
        sum += ipow2(n % 10, n_digits);
    }
    return sum == candidate;
}
