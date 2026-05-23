// =========================================================================================
// TÍTULO: VETOR DE DIFERENÇAS 1D (DIFFERENCE ARRAY)
// PALAVRAS-CHAVE: Range Update, Atualização em Lote, O(1), Reconstrução O(N).
// =========================================================================================

/*
   CASO DE USO CLÁSSICO:
   - O problema te dá um vetor inicial (geralmente zerado) de tamanho N.
   - Ele faz Q atualizações em lote do tipo: "Some V a todos os elementos de L a R".
   - No final, ele pede para você imprimir o vetor resultante.
   
   O PULO DO GATO: Marcamos +V no início (L) e -V logo após o fim (R + 1). 
   No final, fazemos um Prefix Sum clássico para "espalhar" os valores pelo vetor.
*/

#include <bits/stdc++.h>
#define ll long long
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
using namespace std;

void solve() {
    ll n, q;
    if (!(cin >> n >> q)) return;

    // Se o problema já der um vetor inicial com valores, você lê ele aqui.
    // Mas a maioria dos problemas começa com tudo zerado.
    vector<ll> arr(n + 1, 0); 
    /*
    f (i, 1, n + 1) {
        cin >> arr[i];
    }
    */

    // 1. Criamos o vetor de diferenças com tamanho N + 2.
    // O '+ 2' é crucial porque se R = N, faremos R + 1 = N + 1.
    vector<ll> diff(n + 2, 0);

    // 2. Processamos todas as Q atualizações instantaneamente em O(1)
    while (q--) {
        ll L, R, valor;
        cin >> L >> R >> valor; // Ex: Some 'valor' do índice L ao R

        // ATENÇÃO: Se os índices do problema forem base-0, converta:
        // L++; R++;

        // A Mágica das Bordas
        diff[L] += valor;           // Inicia a onda de soma
        diff[R + 1] -= valor;       // Corta a onda de soma
    }

    // 3. Reconstrução do vetor final (Prefix Sum sobre o vetor de diferenças)
    // Fazemos apenas uma vez no final, custando O(N)
    f (i, 1, n + 1) {
        // O valor real da célula é o acumulado das diferenças
        diff[i] += diff[i - 1]; 
        
        // Se havia um vetor inicial com valores, somamos a diferença nele
        arr[i] += diff[i]; 
    }

    // Imprime o resultado
    f (i, 1, n + 1) {
        cout << arr[i] << " ";
    }
    cout << el;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // ll t; cin >> t;
    // while(t--)
    solve();
    return 0;
}