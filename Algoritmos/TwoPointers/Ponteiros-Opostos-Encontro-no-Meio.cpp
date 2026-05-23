// =========================================================================================
// TÍTULO: TWO POINTERS - PONTEIROS OPOSTOS (ENCONTRO NO MEIO)
// PALAVRAS-CHAVE: Array ordenado, Two Sum, Soma de pares, Palíndromo, Inversão.
// =========================================================================================

/*
   CASO DE USO CLÁSSICO:
   - O problema pede para encontrar um PAR de elementos (i, j) que atenda a uma condição (ex: soma == alvo).
   - O array é (ou pode ser) ordenado.
   - O PULO DO GATO: Um ponteiro começa no 0 e o outro no N-1. Se a soma está pequena demais, 
     você avança o da esquerda para aumentar. Se a soma está grande demais, você recua o da direita para diminuir.
   - Complexidade: O(N) para a busca + O(N log N) se precisar ordenar o array antes.
*/

#include <bits/stdc++.h>
#define ll long long
#define all(v) (v).begin(), (v).end()
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
using namespace std;

void solve() {
    ll n, alvo; 
    if (!(cin >> n >> alvo)) return;

    vector<ll> v(n);
    f (i, 0, n) cin >> v[i];

    // PASSO 1: A Mágica só funciona se os dados estiverem em ordem crescente!
    sort(all(v));

    // PASSO 2: Posiciona os jogadores nas pontas do campo
    ll l = 0;
    ll r = n - 1;
    bool encontrou = false;

    // A trava de segurança: eles caminham até se esbarrarem
    while (l < r) {
        
        ll soma_atual = v[l] + v[r];

        // Caso 1: Bingo! Achamos o que queríamos.
        if (soma_atual == alvo) {
            cout << "Par encontrado: " << v[l] << " e " << v[r] << el;
            encontrou = true;
            
            // Se o problema pedir apenas UM par, damos 'break'.
            break; 
            
            // DICA: Se o problema pedir TODOS os pares únicos, você faria:
            // l++; r--; 
            // (e colocaria um 'while' extra para pular números repetidos se houvesse)
        } 
        // Caso 2: A balança está leve demais.
        else if (soma_atual < alvo) {
            // Como o array está ordenado, andar para a direita aumenta o valor de v[l]
            l++;
        } 
        // Caso 3: A balança está pesada demais.
        else {
            // Como o array está ordenado, andar para a esquerda diminui o valor de v[r]
            r--;
        }
    }

    if (!encontrou) {
        cout << "Nenhum par encontrado." << el;
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    // ll t; cin >> t;
    // while (t--) 
    
    solve();
    
    return 0;
}