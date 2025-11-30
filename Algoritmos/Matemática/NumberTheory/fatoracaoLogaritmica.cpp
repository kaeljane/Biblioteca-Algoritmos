const int MAXN = 1e6 + 5;
int spf[MAXN]; // Menor Fator Primo (Smallest Prime Factor)

// 1. Pré-cálculo (Chame na main)
void sieve() {
    iota(spf, spf + MAXN, 0); // Inicializa spf[i] = i
    for (int i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) { // Se é primo
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j) // Só marca se ainda não foi marcado
                    spf[j] = i;
        }
    }
}

// 2. Fatoração O(log N)
vector<int> get_factors(int n) {
    vector<int> factors;
    while (n > 1) {
        factors.push_back(spf[n]);
        n /= spf[n];
    }
    return factors;
}
