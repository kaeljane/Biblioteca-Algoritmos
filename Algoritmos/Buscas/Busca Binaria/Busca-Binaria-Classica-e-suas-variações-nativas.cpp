// =========================================================================================
// TÍTULO: BUSCA BINÁRIA CLÁSSICA E NATIVAS (LOWER_BOUND / UPPER_BOUND)
// PALAVRAS-CHAVE: Binary Search, Pesquisa Binária, lower_bound, upper_bound, Vetor Ordenado.
// =========================================================================================

/*
   CASOS DE USO CLÁSSICOS:
   - Descobrir se um número existe no array.
   - Encontrar o primeiro número maior ou igual a X (lower_bound).
   - Encontrar o primeiro número estritamente maior que X (upper_bound).
   - Contar a frequência de um número em O(log N).
   
   A REGRA DE OURO: O array DEVE estar ordenado antes de usar qualquer uma dessas funções!
*/

#include <bits/stdc++.h>
#define ll long long
#define all(v) (v).begin(), (v).end()
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
using namespace std;

// =========================================================================
// IMPLEMENTAÇÃO MANUAL (Para fins didáticos)
// =========================================================================
bool busca_binaria_manual(const vector<ll>& v, ll alvo) {
    ll l = 0, r = v.size() - 1;
    
    while (l <= r) {
        // Fórmula mais segura para evitar overflow do que (l + r) / 2
        ll mid = l + (r - l) / 2; 
        
        if (v[mid] == alvo) return true; // Achou!
        
        if (v[mid] < alvo) {
            l = mid + 1; // O alvo é maior, corta a metade esquerda fora
        } else {
            r = mid - 1; // O alvo é menor, corta a metade direita fora
        }
    }
    return false; // Não achou
}

// =========================================================================
// O JEITO DE MARATONA (FUNÇÕES NATIVAS)
// =========================================================================
void solve() {
    ll n, consultas; 
    if (!(cin >> n >> consultas)) return;

    vector<ll> v(n);
    f (i, 0, n) cin >> v[i];

    // PASSO 1: A Busca Binária só funciona em terreno organizado.
    sort(all(v));

    while (consultas--) {
        ll alvo;
        cin >> alvo;

        // -----------------------------------------------------------------
        // MODO 1: binary_search (Só diz Sim ou Não)
        // -----------------------------------------------------------------
        if (binary_search(all(v), alvo)) {
            // cout << "O numero existe!" << el;
        }

        // -----------------------------------------------------------------
        // MODO 2: lower_bound (A ferramenta mais usada!)
        // Retorna iterador pro 1º elemento >= alvo
        // -----------------------------------------------------------------
        auto it_lower = lower_bound(all(v), alvo);
        
        // Para converter o "iterador" em um "índice" numérico (0, 1, 2...),
        // basta subtrair v.begin()
        ll idx_lower = it_lower - v.begin();

        if (it_lower != v.end() && *it_lower == alvo) {
            // cout << "Primeira aparicao no indice: " << idx_lower << el;
        } else {
            // cout << "O numero " << alvo << " nao existe." << el;
            // cout << "O proximo numero maior que ele esta no indice: " << idx_lower << el;
        }

        // -----------------------------------------------------------------
        // MODO 3: upper_bound
        // Retorna iterador pro 1º elemento ESTRITAMENTE MAIOR (> alvo)
        // -----------------------------------------------------------------
        auto it_upper = upper_bound(all(v), alvo);
        ll idx_upper = it_upper - v.begin();

        // -----------------------------------------------------------------
        // TRUQUE CLÁSSICO: Quantas vezes o número X aparece no vetor?
        // -----------------------------------------------------------------
        ll frequencia = idx_upper - idx_lower;
        cout << "O numero " << alvo << " aparece " << frequencia << " vezes." << el;
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    // ll t; cin >> t;
    // while (t--) 
    
    solve();
    
    return 0;
}