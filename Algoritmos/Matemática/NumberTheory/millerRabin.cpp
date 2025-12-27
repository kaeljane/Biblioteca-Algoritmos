// Definições para multiplicação segura de 128 bits (evita overflow em a*b % m)

// esse u128 nao funciona no meu gcc atual tem que fazer alteracao
using u128 = __int128;

ll binPow(ll base, ll e, ll mod) {
    ll result = 1;
    base %= mod;
    while (e) {
        if (e & 1) result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool checkComposite(ll n, ll a, ll d, int s) {
    ll x = binPow(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1) return false;
    }
    return true; // É composto
}

bool isPrime(ll n) { // Miller-Rabin Deterministico
    if (n < 2) return false;

    int s = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a) return true;
        if (checkComposite(n, a, d, s)) return false;
    }
    return true;
}