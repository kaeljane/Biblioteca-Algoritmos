// =========================================================================================
// TÍTULO: TWO POINTERS - JANELA DESLIZANTE FIXA (FIXED SLIDING WINDOW)
// PALAVRAS-CHAVE: Subsegmento de tamanho K, Maior soma de K elementos, Janela Rígida.
// =========================================================================================

/*
   CASO DE USO CLÁSSICO:
   - O problema pede algo sobre um subsegmento de tamanho EXATAMENTE K.
   - Ex: "Qual a maior soma possível escolhendo K livros consecutivos?"
   - O PULO DO GATO: Em vez de somar tudo do zero a cada passo (O(N*K)), você soma
     apenas os K primeiros. Depois, ao deslizar a janela para a direita, você SOMA o 
     elemento novo que está entrando na frente, e SUBTRAI o elemento velho que ficou para trás.
   - Complexidade: O(N) cravado.
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

    // Trava de segurança: Se a janela exigida for maior que o próprio array, é impossível.
    if (k > n) {
        cout << 0 << el;
        return;
    }

    ll soma_atual = 0;

    // PASSO 1: Montar a 1ª janela (A moldura inicial de tamanho cravado em K)
    f (i, 0, k) {
        soma_atual += v[i];
    }

    ll ans = soma_atual;

    // PASSO 2: Deslizar a janela até o final do array
    // O loop começa do índice 'k', que é exatamente o próximo elemento FORA da primeira janela
    f (i, k, n) {
        
        // A MÁGICA ACONTECE AQUI:
        // Entra o elemento novo apontado pelo 'i'
        // Sai o elemento velho que ficou lá atrás no 'i - k'
        soma_atual += v[i] - v[i - k];
        
        // Atualiza a resposta com a melhor janela encontrada
        ans = max(ans, soma_atual);
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