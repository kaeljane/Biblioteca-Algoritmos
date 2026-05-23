// =========================================================================================
// TÍTULO: PROGRAMAÇÃO DINÂMICA 1D (BOTTOM-UP)
// PALAVRAS-CHAVE: Fibonacci, Coin Change, Problema do Troco, Mochila 1D (Knapsack Space-Optimized).
// =========================================================================================

/*
   CASOS DE USO CLÁSSICOS:
   - "Qual o N-ésimo termo de uma sequência?" (Fibonacci)
   - "Qual o número mínimo de moedas para dar o troco V?" (Coin Change)
   - "Qual o valor máximo que cabe numa mochila de peso W?" (Mochila 0/1 com memória O(W))
   
   O PULO DO GATO: Na DP Bottom-Up, nós começamos dos casos base (ex: dp[0] = 0) e 
   vamos preenchendo um vetor iterativamente até chegar na resposta final dp[N].
*/

#include <bits/stdc++.h>
#define ll long long
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
using namespace std;

const ll INF = 1e18 + 7;

void solve() {
    // =========================================================================
    // CASO 1: FIBONACCI OTIMIZADO (Contagem de Caminhos)
    // Problema: "De quantas formas posso subir N degraus pulando 1 ou 2 por vez?"
    // Entrada: 5 (N degraus)
    // =========================================================================
    ll n_degraus;
    if (cin >> n_degraus) {
        vector<ll> dp_fibo(n_degraus + 1, 0);
        
        // Casos Base
        dp_fibo[0] = 1; // 1 forma de ficar parado no chão
        if (n_degraus >= 1) dp_fibo[1] = 1; 

        // Transição: Para chegar no degrau 'i', eu vim do 'i-1' ou do 'i-2'
        f (i, 2, n_degraus + 1) {
            dp_fibo[i] = dp_fibo[i - 1] + dp_fibo[i - 2];
        }
        
        cout << "1. Formas de subir " << n_degraus << " degraus: " << dp_fibo[n_degraus] << el;
    }

    // =========================================================================
    // CASO 2: PROBLEMA DO TROCO (Minimização)
    // Problema: "Qual o mínimo de moedas necessárias para formar o valor V?"
    // Entrada: 11 (Valor) | 3 (Qtd Moedas) -> 1 5 10 (Valores das moedas)
    // =========================================================================
    ll valor, qtd_moedas;
    if (cin >> valor >> qtd_moedas) {
        vector<ll> moedas(qtd_moedas);
        f (i, 0, qtd_moedas) cin >> moedas[i];

        // Inicializamos com INF porque queremos achar o MÍNIMO
        vector<ll> dp_troco(valor + 1, INF);
        dp_troco[0] = 0; // 0 moedas para formar o valor 0

        // Transição: Para cada valor 'i', testamos usar cada uma das moedas disponíveis
        f (i, 1, valor + 1) {
            f (j, 0, qtd_moedas) {
                ll moeda_atual = moedas[j];
                
                // Se a moeda cabe no valor atual e o estado anterior foi alcançado
                if (i >= moeda_atual && dp_troco[i - moeda_atual] != INF) {
                    dp_troco[i] = min(dp_troco[i], dp_troco[i - moeda_atual] + 1);
                }
            }
        }
        
        if (dp_troco[valor] == INF) cout << "2. Impossivel dar o troco exato." << el;
        else cout << "2. Minimo de moedas para o troco: " << dp_troco[valor] << el;
    }

    // =========================================================================
    // CASO 3: MOCHILA 0/1 (Otimização Extrema de Memória para 1D)
    // Problema: "Maximizar o valor sem estourar o peso limite W"
    // O grande truque aqui é que a Mochila Clássica é 2D (Itens x Peso), mas
    // podemos reescrevê-la usando apenas 1D se percorrermos o vetor de trás pra frente!
    // =========================================================================
    ll capacidade, n_itens;
    if (cin >> capacidade >> n_itens) {
        vector<ll> pesos(n_itens), valores(n_itens);
        f (i, 0, n_itens) cin >> pesos[i] >> valores[i];

        vector<ll> dp_mochila(capacidade + 1, 0);

        // Para cada item...
        f (i, 0, n_itens) {
            ll p = pesos[i];
            ll v = valores[i];
            
            // ...nós varremos a capacidade DE TRÁS PRA FRENTE.
            // Se varrêssemos de frente pra trás, usaríamos o mesmo item várias vezes!
            for (ll w = capacidade; w >= p; w--) {
                dp_mochila[w] = max(dp_mochila[w], dp_mochila[w - p] + v);
            }
        }

        cout << "3. Valor maximo na mochila: " << dp_mochila[capacidade] << el;
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}