/**************************************************************
 *  Eratosthenes' Sieve for Prime Generation
 *
 *  The time complexity is O(N log log N) and space complexity
 *  is O(N), where N is the upper limit on value of the primes.
 **************************************************************/

unsigned prime[PSIZE];
char is_composite[SIZE] = {0};

unsigned eratosthenes_sieve() {
    register unsigned i;
    register unsigned *p = prime;

    *p = 2;
    for(i = 3; i < SIZE; i += 2) {
        if(is_composite[i]) continue;

        *(++p) = i;
        register unsigned j;
        for(j = i << 1; j < SIZE; j += i)
            is_composite[j] = 1;
    }

    return (p - prime) + 1;
}
