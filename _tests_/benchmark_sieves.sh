#!/bin/bash

g++ test_sieves.c -D TEST_ATKIN -o test_atkin_sieve
g++ test_sieves.c -D TEST_SUNDARAM -o test_sundaram_sieve
g++ test_sieves.c -D TEST_ERATOSTHENES -o test_eratosthenes_sieve
g++ test_sieves.c -D TEST_FAST_ERATOSTHENES -o test_fast_eratosthenes_sieve

echo -ne "\nATKIN'S SIEVE :: "
time ./test_atkin_sieve

echo -ne "\nSUNDARAM'S SIEVE :: "
time ./test_sundaram_sieve

echo -ne "\nERATOSTHENES' SIEVE :: "
time ./test_eratosthenes_sieve

echo -ne "\nFAST ERATOSTHENES' SIEVE :: "
time ./test_fast_eratosthenes_sieve

rm test_*sieve
