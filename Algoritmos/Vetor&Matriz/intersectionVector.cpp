void solve() {
    vi a = {1, 2, 5, 7, 9};
    vi b = {2, 4, 5, 6, 9};
    
    // 1. Garanta que estão ordenados (Passo obrigatório)
    sort(all(a)); 
    sort(all(b));
    
    vi interseccao;
    
    // 2. A Mágica
    // O back_inserter vai dando push_back automaticamente no vetor 'interseccao'
    set_intersection(all(a), all(b), back_inserter(interseccao));
    
    // Resultado: 2 5 9
    for(int x : interseccao) cout << x << " ";
    cout << el;
}5