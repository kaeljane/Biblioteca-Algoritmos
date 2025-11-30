const int MAX = 2e5 + 5; // Ajuste conforme o problema (geralmente 2*10^5 ou 10^6)
// MOD já está definido no seu template (1e9 + 7)

ll fact[MAX];

// 1. Exponenciação Modular (O Motor)
ll binpow(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

// 2. Inverso Modular (A Ferramenta de Divisão - Fermat)
ll inverse(ll n) {
    return binpow(n, MOD - 2);
}

// 3. Pré-cálculo dos Fatoriais (Inicialização)
void init_fact() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

// 4. A Função de Combinação (O Objetivo Final)
// n! / (k!*(n-k)!)
ll nCr(int n, int k) {
    if (k < 0 || k > n) return 0; // Impossível escolher k itens se tem n
    
    // Fórmula: n! * inv(k!) * inv((n-k)!)
    return (((fact[n] * inverse(fact[k])) % MOD) * inverse(fact[n - k])) % MOD;
}

// n! / (n - k)!
ll nPr(int n, int k) {
    if (k < 0 || k > n) return 0;
    return (fact[n] * inverse(fact[n - k])) % MOD;
}

signed main() {
    ___ // Seu fast I/O
    
    init_fact(); // <--- CRUCIAL: Calcule os fatoriais uma vez só!
    
    t = 1;
    cin >> t;
    while(t--)
        solve(); 

    return 0;
}