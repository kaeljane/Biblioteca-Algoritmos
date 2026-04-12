// Comparar se duas substrings são iguais em
// O(1). Acha palíndromos, períodos de uma string e resolve
// o problema de "maior prefixo que também é sufixo". Dica:
// No CodeForces, use um módulo seguro (ex: 1e9+9) ou Hash
// Duplo para evitar ser hackeado.

const ll M = 1e9 + 9, B = 31; // Base 31 para letras minusculas
vector<ll> h, p;

// Constroi o hash de todos os prefixos em O(N)
void build_hash(string& s) {
    int n = s.size();
    h.assign(n + 1, 0); 
    p.assign(n + 1, 1);
    for (int i = 0; i < n; i++) {
        h[i+1] = (h[i] * B + (s[i] - 'a' + 1)) % M;
        p[i+1] = (p[i] * B) % M;
    }
}

// Retorna o hash da substring s[l...r] em O(1) (0-indexed, inclusivo)
ll get_hash(int l, int r) { 
    ll res = (h[r+1] - h[l] * p[r - l + 1]) % M;
    return (res + M) % M; // Garante que nao seja negativo
}