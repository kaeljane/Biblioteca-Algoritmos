// ele calcula phi, primes e lp tudo ao mesmo tempo, o que é util para a fatoração rápida depois.
const int MAX = 1e6 + 5;
int phi[MAX];
int lp[MAX]; // Menor fator primo (Lowest Prime)
vector<int> primes;

void sieve_linear() {
    phi[1] = 1;
    for (int i = 2; i < MAX; ++i) {
        if (lp[i] == 0) { // i é primo
            lp[i] = i;
            phi[i] = i - 1;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > lp[i] || i * p >= MAX) break;
            
            lp[i * p] = p;
            
            if (lp[i] == p) {
                // p divide i (Caso 3: p já está nos fatores)
                phi[i * p] = phi[i] * p; 
            } else {
                // p não divide i (Caso 2: p é novo fator)
                phi[i * p] = phi[i] * (p - 1);
            }
        }
    }
}