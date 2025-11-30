ll get_max_suffix_sum(const vl& v) {
    ll n = sz(v);
    if (n == 0) return -INF; // Segurança para vetor vazio

    ll current_sum = 0;
    ll max_suf = -INF; // Começa com -INF para lidar com números negativos

    // Itera de trás para frente
    for (int i = n - 1; i >= 0; i--) {
        current_sum += v[i];
        max_suf = max(max_suf, current_sum);
    }

    return max_suf;
}