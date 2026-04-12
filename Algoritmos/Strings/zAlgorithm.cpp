// O array Z[i] armazena o tamanho do maior
// prefixo da substring S[i . . . N − 1] que também é prefixo da
// string inteira S. Se quiser buscar uma palavra P num texto
// T , rode o algoritmo na string S = P + ”$” + T .

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) z[i] = min(r - i, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if(i + z[i] > r) { l = i; r = i + z[i]; }
    }
    return z; // z[0] geralmente e mantido como 0
}