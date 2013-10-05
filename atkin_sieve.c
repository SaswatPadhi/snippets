#include <math.h>

unsigned prime[PSIZE];
char sieve[SIZE] = {0};

unsigned atkin_sieve() {
    register unsigned i, j, n, SQSIZE = sqrt(SIZE);
    register unsigned* p = prime;

    *p = 2;
    *(++p) = 3;

    for(i = 1; i <= SQSIZE; ++i) {
        for(j = 1; j <= SQSIZE; ++j) {
            n = (4 * i * i) + (j * j);
            if(n < SIZE && (n % 12 == 1 || n % 12 == 5))    sieve[n] ^= 1;
            n = (3 * i * i) + (j * j);
            if(n < SIZE && n % 12 == 7)    sieve[n] ^= 1;
            n = (3 * i * i) - (j * j);
            if(i > j && n < SIZE && n % 12 == 11)    sieve[n] ^= 1;
        }
    }

    for(i = 5; i < SQSIZE; ++i) {
        if(sieve[i]) {
            n = i * i;
            for(j = n; j < SIZE; j += n)
                sieve[j] = 0;
        }
    }

    for(i = 5; i < SIZE; ++i)
        if(sieve[i])
            *(++p) = i;

    return (p - prime) + 1;
}
