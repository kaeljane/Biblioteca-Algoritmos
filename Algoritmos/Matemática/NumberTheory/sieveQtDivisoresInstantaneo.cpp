// 1. Definimos o limite (10^6 conforme o enunciado)
const int MAXN = 1e6 + 5;

// 2. Criamos o vetor global (para não estourar a memória da stack)
// Ele começa todo com 0 automaticamente por ser global
int divs[MAXN]; 

// 3. A Mágica do Pré-cálculo
void precompute() {
    // Para cada número i de 1 até o máximo...
    for (int i = 1; i < MAXN; i++) {
        
        // ...vamos visitar todos os MÚLTIPLOS de i (j = i, 2i, 3i...)
        for (int j = i; j < MAXN; j += i) {
            divs[j]++; // Adicionamos 'i' como um divisor de 'j'
        }
    }
}

void solve() {
    int x;
    cin >> x;
    // Como já calculamos TUDO antes, a resposta é instantânea (O(1))
    cout << divs[x] << el;
}

signed main() {
    ___
    
    // Importante: Rodar o pré-cálculo ANTES de ler os casos de teste
    precompute();

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}