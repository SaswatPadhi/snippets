#define HSIZE   (SIZE >> 1)

unsigned prime[PSIZE];
char sieve[HSIZE] = {0};

unsigned sundaram_sieve() {
    register unsigned i, j, m = 0, d = 0;

    for(i = 1; i < HSIZE; ++i) {
        d = (i << 1) + 1;
        m = (HSIZE - i) / d;
        for(j = i; j <= m; ++j)
            sieve[i + j * d] = 1;
    }

    prime[d = 0] = 2;
    for(i = 1; i < HSIZE; ++i)
        if(!sieve[i])
            prime[++d] = (i << 1) + 1;

    return d + 1;
}
