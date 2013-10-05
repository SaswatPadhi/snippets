unsigned prime[PSIZE];
char sieve[SIZE] = {0};

unsigned eratosthenes_sieve() {
    register unsigned i, j;
    register unsigned* p = prime;

    *p = 2;
    for(i = 3; i < SIZE; i += 2) {
        if(sieve[i])
            continue;

        *(++p) = i;
        for(j = i << 1; j < SIZE; j += i)
            sieve[j] = 1;
    }

    return (p - prime) + 1;
}
