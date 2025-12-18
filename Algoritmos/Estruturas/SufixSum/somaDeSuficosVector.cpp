vl build_suffix(const vl& v) {
    int n = sz(v);
    vl s(n + 1, 0); // Tamanho n+1, inicializado com 0

    // Itera de trás para frente
    // s[n] já é 0
    for (int i = n - 1; i >= 0; i--) {
        s[i] = s[i + 1] + v[i];
    }

    return s;
}