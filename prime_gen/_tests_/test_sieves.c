#include <stdio.h>

#define SIZE    100000000
#define PSIZE   5761500

#ifdef TEST_ATKIN
    #include "../atkin_sieve.c"
#elif TEST_SUNDARAM
    #include "../sundaram_sieve.c"
#elif TEST_ERATOSTHENES
    #include "../eratosthenes_sieve.c"
#elif TEST_FAST_ERATOSTHENES
    #include "../fast_eratosthenes_sieve.c"
#endif

int main() {
    unsigned count;

    #ifdef TEST_ATKIN
        count = atkin_sieve();
    #elif TEST_SUNDARAM
        count = sundaram_sieve();
    #elif TEST_ERATOSTHENES
        count = eratosthenes_sieve();
    #elif TEST_FAST_ERATOSTHENES
        count = fast_eratosthenes_sieve();
    #endif

    printf("Found %d primes under %d\n", count, SIZE);

    return 0;
}
