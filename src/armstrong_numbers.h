#ifndef ARMSTRONG_NUMBERS
#define ARMSTRONG_NUMBERS

#ifdef __cplusplus
extern "C" {
#endif

#include <inttypes.h>
#include <stdbool.h>

unsigned int num_digits(unsigned int n);
int num_digits2(int n);

int ipow(int base, int exp);
uint64_t ipow2(uint8_t base, uint8_t exp);
bool is_armstrong_number(unsigned int candidate);
bool is_armstrong_number_old(int candidate);

#ifdef __cplusplus
}
#endif

#endif
