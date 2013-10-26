/**************************************************************
 *  Fast Modular Exponentiation by Squaring
 *
 *  Worst case complexity is O(log N), where N = the exponent
 **************************************************************/

unsigned long long mod_expo(unsigned long long base, unsigned long long expo) {
    base %= MOD;
    if(expo == 1)       return base;
    else if(expo & 1)   return (base * mod_expo(base * base, expo >> 1)) % MOD;
    else                return mod_expo(base * base, expo >> 1) % MOD;
}
