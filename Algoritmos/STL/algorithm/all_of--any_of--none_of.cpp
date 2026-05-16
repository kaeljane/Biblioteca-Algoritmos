/* ===================================================================
 * 🕵️ VERIFICADORES EM MASSA (all_of, any_of, none_of)
 * ===================================================================
 * Função: Substitui os laços 'for' usados para checar se os elementos
 * de um vetor cumprem uma determinada regra. Retorna true ou false.
 * * 🚨 REGRAS DE OURO:
 * 1. A FUNÇÃO LAMBDA: O terceiro parâmetro exige uma regra. Para não 
 * ter que criar uma função separada lá em cima do código, a gente 
 * cria uma função "descartável" ali mesmo. A sintaxe é:
 * [](ll x) { return condicao; }
 * * 2. SHORT-CIRCUIT (Otimização): Eles são inteligentes! 
 * - No 'all_of', se o 1º elemento falhar, ele nem olha o resto.
 * - No 'any_of', se o 1º elemento passar, ele já para e dá true.
 *
 * ⏱️ COMPLEXIDADE:
 * Tempo O(N) no pior dos casos. Super rápido, pode usar sem medo!
 * =================================================================== */
#include <bits/stdc++.h>
#define ll long long
#define all(v) (v).begin(), (v).end()
#define el '\n'
using namespace std;

void template_verificadores() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) cin >> v[i];

    // -----------------------------------------------------------
    // 1. ALL_OF (TODOS)
    // Retorna TRUE se TODOS os elementos passarem no teste.
    // Ex: Verificar se todos os números do vetor são pares
    // -----------------------------------------------------------
    bool todos_pares = all_of(all(v), [](ll x) { return x % 2 == 0; });
    
    if (todos_pares) cout << "Todos sao pares!" << el;
    else cout << "Tem pelo menos um intruso impar..." << el;


    // -----------------------------------------------------------
    // 2. ANY_OF (PELO MENOS UM)
    // Retorna TRUE se PELO MENOS UM elemento passar no teste.
    // Ex: Verificar se existe algum número negativo no vetor
    // -----------------------------------------------------------
    bool tem_negativo = any_of(all(v), [](ll x) { return x < 0; });
    
    if (tem_negativo) cout << "Cuidado, achei um numero negativo!" << el;


    // -----------------------------------------------------------
    // 3. NONE_OF (NENHUM)
    // Retorna TRUE se NENHUM elemento passar no teste.
    // Ex: Verificar se não existe nenhum zero no vetor
    // -----------------------------------------------------------
    bool sem_zeros = none_of(all(v), [](ll x) { return x == 0; });
    
    if (sem_zeros) cout << "O vetor esta limpo de zeros!" << el;
}