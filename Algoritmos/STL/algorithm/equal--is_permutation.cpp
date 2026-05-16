/* ===================================================================
 * ⚖️ COMPARADORES ABSOLUTOS (equal, is_permutation)
 * ===================================================================
 * Função: Respondem com TRUE ou FALSE ao comparar dois vetores.
 * * 🚨 REGRAS DE OURO E A ARMADILHA DO TLE:
 * 1. O PERIGO DO IS_PERMUTATION: Se os vetores NÃO estiverem ordenados
 * e tiverem elementos repetidos, a complexidade dele vira O(N²)!
 * Em Maratonas, se N for 10^5, isso dá TLE na hora. É muito mais 
 * seguro e rápido você dar um sort() nos dois vetores e depois 
 * checar se são iguais (v1 == v2). Use 'is_permutation' apenas 
 * quando N for pequeno ou se você NÃO PUDER alterar/ordenar os vetores.
 * =================================================================== */
#include <bits/stdc++.h>
#define ll long long
#define all(v) (v).begin(), (v).end()
#define el '\n'
using namespace std;

void template_comparadores() {
    vector<ll> v1 = {1, 2, 3, 4, 5};
    vector<ll> v2 = {1, 2, 3, 4, 5};
    vector<ll> v3 = {5, 4, 3, 2, 1};

    // -----------------------------------------------------------
    // 1. EQUAL (IGUALDADE ESTRITA)
    // ⏱️ Complexidade: O(N)
    // Verifica se os elementos são iguais e estão na MESMA ORDEM.
    // Dica: Para vetores inteiros, (v1 == v2) faz a mesma coisa,
    // mas o equal permite checar apenas um pedaço: equal(v1.begin(), v1.begin()+3, v2.begin())
    // -----------------------------------------------------------
    if (equal(all(v1), all(v2))) {
        cout << "v1 e v2 sao clones perfeitos!" << el;
    }

    // -----------------------------------------------------------
    // 2. IS_PERMUTATION (MESMOS ELEMENTOS, ORDEM DIFERENTE)
    // ⏱️ Complexidade: O(N) se não houver repetições, O(N²) no pior caso.
    // Verifica se um vetor é um "anagrama" numérico do outro.
    // -----------------------------------------------------------
    if (is_permutation(all(v1), all(v3))) {
        cout << "v1 e v3 tem os mesmos elementos, so estao embaralhados!" << el;
    }
}