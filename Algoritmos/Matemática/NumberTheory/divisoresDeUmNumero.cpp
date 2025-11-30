vector<long long> get_divisors(long long n) {
    vector<long long> divs;
    
    // Itera apenas até a raiz de N
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i); // Adiciona o divisor pequeno
            
            // Verifica se não é um quadrado perfeito para não adicionar 
            // a raiz duas vezes (ex: 5*5 = 25)
            if (i * i != n) {
                divs.push_back(n / i); // Adiciona o par maior
            }
        }
    }
    
    // Opcional: O algoritmo acima gera a lista desordenada.
    // Ex: para 12 gera {1, 12, 2, 6, 3, 4}.
    // Geralmente em problemas queremos ordenado:
    sort(divs.begin(), divs.end());
    
    return divs;
}