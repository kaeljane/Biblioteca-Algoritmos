// =========================================================================================
// TÍTULO: SOMA DE PREFIXOS 1D (PREFIX SUM)
// PALAVRAS-CHAVE: Range Query, Soma em Intervalo, O(1), Vetor Acumulado.
// =========================================================================================

/*
   CASO DE USO CLÁSSICO:
   - O problema te dá um vetor estático de tamanho N.
   - Ele faz Q perguntas do tipo: "Qual a soma dos elementos do índice L ao R?"
   
   O PULO DO GATO: Usar array 1-based (começando do índice 1). 
   Isso evita bugs fatais, pois a fórmula pref[R] - pref[L - 1] não vai 
   dar Segmentation Fault quando L for 1 (pois vai acessar pref[0], que é 0).
*/

#include <bits/stdc++.h>
#define ll long long
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
using namespace std;

void solve() {
    ll n, q;
    if (!(cin >> n >> q)) return;

    // 1. Lemos os valores originais. Usamos base-1 para facilitar a matemática!
    vector<ll> arr(n + 1, 0);
    f (i, 1, n + 1) {
        cin >> arr[i];
    }

    // 2. Construção do Prefix Sum em O(N)
    vector<ll> pref(n + 1, 0);
    f (i, 1, n + 1) {
        pref[i] = pref[i - 1] + arr[i];
    }

    // 3. Respondendo a Q consultas instantaneamente em O(1)
    while (q--) {
        ll L, R;
        cin >> L >> R;

        // ATENÇÃO: Se o enunciado do problema disser que os índices são base-0 
        // (indo de 0 a N-1), você DEVE somar 1 nas variáveis antes da fórmula:
        // L++; R++;
        
        // Fórmula mágica: Tudo até R, menos o que ficou para trás de L
        ll soma = pref[R] - pref[L - 1];
        
        cout << soma << el;
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // ll t; cin >> t;
    // while (t--)
    solve();
    return 0;
}