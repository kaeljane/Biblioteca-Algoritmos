// =========================================================================================
// TÍTULO: TWO POINTERS - JANELA DESLIZANTE VARIÁVEL (SLIDING WINDOW)
// PALAVRAS-CHAVE: Subsegmento, Subarray, Substring, Soma contínua, Maior/Menor sequência.
// =========================================================================================

/*
   CASO DE USO CLÁSSICO:
   - O problema pede o "maior", "menor" ou "número de" subsegmentos CONSECUTIVOS.
   - A restrição tem um limite claro (ex: limite de tempo K, no máximo K caracteres únicos).
   - O PULO DO GATO: O ponteiro 'r' sempre avança incluindo itens. Se a regra for quebrada, 
     o ponteiro 'l' avança correndo atrás para excluir itens até a janela voltar a ser válida.
   - Complexidade: O(N), pois ambos os ponteiros andam no máximo N vezes para a direita.
*/

#include <bits/stdc++.h>
#define ll long long
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
using namespace std;

void solve() {
    ll n, k; 
    if (!(cin >> n >> k)) return;

    vector<ll> v(n);
    f (i, 0, n) cin >> v[i];

    ll l = 0;
    ll estado_atual = 0; // Pode ser a soma, um mapa de frequências, etc.
    ll ans = 0;          // Se o problema pedir o "menor subarray", inicie com INF

    // O ponteiro 'r' expande a janela sistematicamente, um passo de cada vez
    f (r, 0, n) {
        
        // 1. ADICIONA o elemento novo ao estado da janela
        estado_atual += v[r];

        // 2. CORRIGE A JANELA se a regra do problema for quebrada (ex: estourou limite K)
        // O (l <= r) é a trava de segurança para o 'l' não ultrapassar o 'r'
        while (estado_atual > k && l <= r) {
            estado_atual -= v[l]; // Remove o impacto do elemento da esquerda
            l++;                  // Encolhe a janela
        }

        // 3. ATUALIZA A RESPOSTA
        // (Neste ponto, temos 100% de certeza que a janela [l, r] é VÁLIDA!)
        
        // Para "Maior subarray":
        ans = max(ans, r - l + 1); 
        
        // DICA: Se a pergunta fosse "Quantos subarrays válidos existem?":
        // ans += (r - l + 1);
    }

    cout << ans << el;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    // ll t; cin >> t;
    // while (t--) 
    
    solve();
    
    return 0;
}