// =========================================================================================
// TÍTULO: COIN CHANGE PROBLEM (COM RECUPERAÇÃO DE CAMINHO OTIMIZADA)
// PALAVRAS-CHAVE: Problema do Troco, Mochila Unbounded, Backtracking em DP, Greedy Choice.
// =========================================================================================

/*
   CASOS DE USO CLÁSSICOS:
   - "Qual o menor número de moedas para dar o troco N?"
   - "QUAIS moedas eu devo entregar para formar esse troco ótimo?"
   - "Em caso de empate, priorize a moeda de menor valor (ou ordem alfabética)."
   
   O PULO DO GATO: Nós resolvemos o Coin Change 1D normal. Depois, fazemos o caminho
   reverso (do valor N até 0). Para garantir a ordem alfabética, nós ORDENAMOS as moedas 
   antes de começar. Na volta, a primeira moeda que satisfizer a regra matemática do 
   caminho ótimo será escolhida, garantindo o desempate lexicográfico perfeito!
*/

#include <bits/stdc++.h>
#define ll long long
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
#define ___ ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

const ll INF = 1e18 + 7;

// Estrutura customizada para guardar o Nome e o Valor da "moeda"
struct Moeda {
    string nome;
    ll valor;
    
    // Sobrecarga de operador para ordenar as moedas em Ordem Alfabética (Lexicográfica)
    bool operator<(const Moeda& outra) const {
        return nome < outra.nome;
    }
};

void solve() {
    ll n;
    if (!(cin >> n)) return;

    // 1. Cadastramos todas as "moedas" disponíveis
    vector<Moeda> moedas = {
        {"ALAN", 1000}, {"CLOE", 480}, {"ELON", 80}, {"GABY", 20},
        {"IRMA", 5}, {"BETO", 600}, {"DUDA", 240}, {"FANY", 60},
        {"HUGO", 8}, {"JOSE", 1}
    };

    // 2. ORDENAÇÃO CRUCIAL PARA O DESEMPATE:
    // Como queremos a string lexicograficamente menor em caso de empate,
    // ordenamos nosso vetor de moedas por ordem alfabética logo de cara.
    sort(moedas.begin(), moedas.end());

    // 3. O ALGORITMO COIN CHANGE (Bottom-Up)
    // dp[i] guarda o número MÍNIMO de pessoas para alcançar a soma 'i'
    vector<ll> dp(n + 1, INF);
    dp[0] = 0; // Para a soma 0, precisamos de 0 pessoas

    f (i, 1, n + 1) {
        for (auto m : moedas) {
            if (i >= m.valor && dp[i - m.valor] != INF) {
                dp[i] = min(dp[i], dp[i - m.valor] + 1);
            }
        }
    }

    // 4. RECUPERAÇÃO DO CAMINHO (Backtracking na DP)
    // Vamos partir da soma N e descer até 0, recolhendo os nomes
    ll atual = n;
    string resultado = "";

    while (atual > 0) {
        for (auto m : moedas) {
            // A Regra de Ouro do Caminho Ótimo:
            // Se eu estou na soma 'atual', a moeda 'm' FAZ PARTE da resposta ótima se, e somente se,
            // o custo do estado atual for exatamente 1 passo maior que o estado de onde ela veio.
            if (atual >= m.valor && dp[atual] == dp[atual - m.valor] + 1) {
                resultado += m.nome;
                atual -= m.valor;
                
                // Achamos a melhor moeda para este passo! Damos break para recomeçar 
                // a busca a partir da nova soma 'atual'.
                break; 
            }
        }
    }

    // Como as moedas já foram testadas em ordem alfabética no laço 'for', a primeira
    // que o código encontrar e der 'break' garantirá a menor string possível.
    cout << resultado << el;
}

signed main() {
    ___
    solve();
    return 0;
}