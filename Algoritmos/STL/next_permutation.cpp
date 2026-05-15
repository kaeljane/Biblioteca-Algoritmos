/* ===================================================================
 * 🔄 GERADOR DE PERMUTAÇÕES (FORÇA BRUTA)
 * ===================================================================
 * Função: Gera todas as combinações (embaralhamentos) possíveis de 
 * um vetor ou string de forma lexicográfica (alfabética).
 * * 🚨 REGRAS DE OURO:
 * 1. OBRIGATÓRIO DAR SORT ANTES: A função para de rodar quando o 
 * vetor atinge a ordem decrescente máxima. Se não ordenar antes, 
 * você pula combinações.
 * 2. USE DO-WHILE: Se usar apenas 'while', o vetor é embaralhado 
 * imediatamente e você perde o teste da configuração inicial.
 * * ⏱️ COMPLEXIDADE E LIMITES (O(N!)):
 * O(N!) cresce bizarramente rápido. Só use se:
 * - N <= 10 (10! = 3.628.800 operações) -> Roda em um piscar de olhos.
 * - N == 11 (11! = 39.916.800 operações) -> Roda perto de 1 segundo (arriscado).
 * - N >= 12 (12! = 479 milhões) -> Vai dar Time Limit Exceeded (TLE) na certa!
 * =================================================================== */
#include <bits/stdc++.h>
#define ll long long
#define all(v) (v).begin(), (v).end()
using namespace std;

void template_permutacao() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) cin >> v[i];

    // 1º PASSO: Garantir o ponto de partida (menor combinação possível)
    sort(all(v)); 

    // 2º PASSO: Estrutura do-while
    do {
        // -----------------------------------------------------------
        // AQUI DENTRO VOCÊ COLOCA A LÓGICA DO PROBLEMA
        // O vetor 'v' agora está em uma nova configuração única!
        // -----------------------------------------------------------
        
        bool achou_a_resposta = false; // Exemplo de condição
        
        // if (v[0] + v[1] == v[2]) ... (testa o vetor embaralhado)
        
        if (achou_a_resposta) {
            cout << "YES" << '\n';
            return; // Interrompe tudo se achou o que queria
        }

    } while (next_permutation(all(v))); // Gera a próxima. Se não houver, sai do laço.

    // Se varreu todas as permutações e não deu 'return' lá dentro:
    cout << "NO" << '\n';
}

/* * 💡 DICA EXTRA: Também funciona perfeitamente com STRINGS!
 * string s = "cba";
 * sort(all(s)); // vira "abc"
 * do { cout << s << endl; } while (next_permutation(all(s)));
 * Vai imprimir: abc, acb, bac, bca, cab, cba.
 */