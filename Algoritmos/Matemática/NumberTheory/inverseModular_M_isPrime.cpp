// Requer a função binpow que você já tem
long long inverse(long long a, long long m) {
    return binPow(a, m - 2, m);
}