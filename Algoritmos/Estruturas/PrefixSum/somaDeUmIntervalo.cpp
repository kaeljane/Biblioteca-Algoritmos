// Função para pegar a soma do intervalo [L, R] (0-bases)
// Exemplo query(p, 2, 4) retorna v[2] + v[3] + v[4]

ll querySum(const vector<ll>& p, int l, int r) {
        if (l > r) return 0;
        return p[r + 1] - p[l];
}