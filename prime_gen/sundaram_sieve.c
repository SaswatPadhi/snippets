/**************************************************************
 *  Sundaram's Sieve for Prime Generation
 *
 *  The time complexity is Θ(N log N) and space complexity is
 *  O(N), where N is the upper limit on value of the primes.
 **************************************************************/

#define HSIZE   (SIZE >> 1)

unsigned prime[PSIZE];
char sieve[HSIZE] = {0};

unsigned sundaram_sieve() {
    register unsigned i, d;

    for(i = 1; i < HSIZE; ++i) {
        d = (i << 1) + 1;
        register unsigned m = (HSIZE - i) / d;
        register unsigned j;
        for(j = i; j <= m; ++j)
            sieve[i + j * d] = 1;
    }

    prime[d = 0] = 2;
    for(i = 1; i < HSIZE; ++i)
        if(!sieve[i])
            prime[++d] = (i << 1) + 1;

    return d + 1;
}
