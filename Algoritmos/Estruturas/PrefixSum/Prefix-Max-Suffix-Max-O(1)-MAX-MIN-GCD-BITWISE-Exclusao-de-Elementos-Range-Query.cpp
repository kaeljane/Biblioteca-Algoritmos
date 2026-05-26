// =========================================================================================
// TÍTULO: PREFIX & SUFFIX ARRAYS (MAX, MIN, GCD, BITWISE)
// PALAVRAS-CHAVE: Prefix Max, Suffix Max, Exclusão de Elemento, Range Query O(1).
// =========================================================================================

/*
   CASOS DE USO CLÁSSICOS:
   - "Qual o maior/menor elemento do vetor se eu REMOVER a posição i?"
   - "Qual o Máximo Divisor Comum (GCD) de todos os elementos, exceto o elemento i?"
   - "Qual a soma do máximo à esquerda com o máximo à direita?"
   
   O PULO DO GATO: Como operações de Max, Min e GCD não possuem "inverso" (não dá pra subtrair),
   nós pré-calculamos tudo vindo da esquerda (Prefix) e tudo vindo da direita (Suffix).
   A resposta excluindo 'i' é simplesmente a junção de pref[i-1] com suf[i+1].
*/

#include <bits/stdc++.h>
#define ll long long
#define vl vector<long long>
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
#define ___ ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

// Constantes úteis para inicializar buscas de Máximo e Mínimo
const ll INF = 1e18 + 7;

void solve() {
    ll n, q;
    if (!(cin >> n >> q)) return;

    // Base-1 index para evitar Segmentation Faults nas bordas
    vl v(n + 2, 0); 
    f (i, 1, n + 1) {
        cin >> v[i];
    }

    // -------------------------------------------------------------------------
    // ETAPA 1: ESCOLHA O ELEMENTO NEUTRO DA SUA OPERAÇÃO
    // Se for MAX: O neutro é um número muito pequeno (0 ou -INF).
    // Se for MIN: O neutro é um número muito grande (INF).
    // Se for GCD: O neutro é 0.
    // -------------------------------------------------------------------------
    ll NEUTRO = 0; 

    vl pref(n + 2, NEUTRO);
    vl suf(n + 2, NEUTRO);

    // 2. Construindo o Prefix Array (INCLUSIVO: da esquerda para a direita)
    f (i, 1, n + 1) {
        pref[i] = max(pref[i - 1], v[i]); 
        // Troque 'max' por 'min', 'gcd', ou '|' (bitwise OR) dependendo do problema!
    }

    // 3. Construindo o Suffix Array (INCLUSIVO: da direita para a esquerda)
    for (ll i = n; i >= 1; i--) {
        suf[i] = max(suf[i + 1], v[i]);
    }

    // 4. Respondendo as consultas em O(1)
    while (q--) {
        ll i;
        cin >> i;
        
        // ---------------------------------------------------------------------
        // TIPOS DE CONSULTAS:
        // ---------------------------------------------------------------------
        
        // Cenario A (Problema Atual): Soma do máximo à esquerda com máximo à direita
        ll max_esq = pref[i - 1];
        ll max_dir = suf[i + 1];
        cout << max_esq + max_dir << el;

        // Cenario B (Muito Comum): Maior elemento do vetor inteiro REMOVENDO a posição 'i'
        // ll max_sem_i = max(pref[i - 1], suf[i + 1]);
        // cout << max_sem_i << el;
    }
}

signed main() {
    ___
    // ll t; cin >> t;
    // while(t--)
    solve();
    return 0;
}