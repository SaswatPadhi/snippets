unsigned prime[PSIZE];
char sieve[SIZE >> 1] = {0};

unsigned fast_eratosthenes_sieve() {
    register unsigned i, j, k;
    register unsigned* p = prime;

    *p = 2;
    for(i = 1; i < SIZE >> 1; ++i) {
        if(sieve[i])    continue;

        *(++p) = (k = (i << 1) + 1);
        for(j = k; j < SIZE; j += k)
            if(j & 1)
                sieve[j >> 1] = 1;
    }

    return (p - prime) + 1;
}
