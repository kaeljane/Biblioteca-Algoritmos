// Retorna o XOR acumulado de 0 até n em O(1)
long long xor_sum(long long n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0; // n % 4 == 3
}

/*

xor_sum
prefix_xor
xor_0_to_n
math_bitwise

*/