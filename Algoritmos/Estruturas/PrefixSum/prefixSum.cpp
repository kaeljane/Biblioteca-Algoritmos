// Função auxiliar para calcular Prefix Sum de um vetor
// Retorna um vetor onde p[i] é a soma de v[0]...v[i-1]

vector<ll> build_prefix(const vector<ll>& v) {
        ll n = v.size();
        vector<ll> p(n + 1, 0);
        for (ll i=0; i < n; i++) {
                p[i + 1] = p[i] + v[i];
        }
        return p;
}