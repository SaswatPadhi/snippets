/**************************************************************
 *  Eratosthenes' Sieve for Prime Generation (My Variation)
 *
 *  The time complexity is O(N log log N) and space complexity
 *  is O(N), where N is the upper limit on value of the primes.
 *
 *  In this variant, I only use half the amount of space and
 *  number of operations than the un-optimised version.
 *
 *  The basic idea is to forget about even numbers completely,
 *  because a prime (> 2) cannot be even.
 **************************************************************/

unsigned prime[PSIZE];
char sieve[SIZE >> 1] = {0};

unsigned fast_eratosthenes_sieve() {
    register unsigned i;
    register unsigned *p = prime;

    *p = 2;
    /**
     *  We know that primes will always be of the form 2i+1, so
     *  iterate only till N/2 numbers.
     **/
    for(i = 1; i < SIZE >> 1; ++i) {
        if(sieve[i])    continue;

        register unsigned k;
        *(++p) = (k = (i << 1) + 1);
        register unsigned j = (k <<= 1);
        /**
         *  Cross out halves of only the odd multiples of k (our
         *  new prime); because doubling them and adding 1 would
         *  gives us this multiple, which is composite.
         *
         *  Halves of even multiples are not crossed out because
         *  doubling it and adding 1 "might" give us a prime.
         **/
        for(j >>= 1; j < SIZE; j += k)
            sieve[j >> 1] = 1;
    }

    return (p - prime) + 1;
}
