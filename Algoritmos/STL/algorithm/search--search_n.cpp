/* ===================================================================
 * 🔎 CAÇADORES DE SUB-BLOCOS (search, search_n)
 * ===================================================================
 * Função: Procuram padrões compostos dentro de um vetor ou string.
 * Retornam um iterador (use it - v.begin() para achar o índice).
 * * 🚨 REGRAS DE OURO:
 * 1. O IRMÃO DO FIND_END: Lembra que o find_end achava a ÚLTIMA 
 * aparição de um padrão? O 'search' acha a PRIMEIRA aparição!
 * =================================================================== */
#include <bits/stdc++.h>
#define ll long long
#define all(v) (v).begin(), (v).end()
#define el '\n'
using namespace std;

void template_search() {
    vector<ll> grandao = {9, 1, 2, 3, 8, 1, 2, 3, 7};
    vector<ll> padrao = {1, 2, 3};

    // -----------------------------------------------------------
    // 1. SEARCH (CAÇADOR DE PADRÕES)
    // ⏱️ Complexidade: O(N * M) no pior caso.
    // Encontra a PRIMEIRA vez que o 'padrao' inteiro aparece no 'grandao'.
    // -----------------------------------------------------------
    auto it_search = search(all(grandao), all(padrao));

    if (it_search != grandao.end()) {
        ll indice = it_search - grandao.begin();
        cout << "O padrao [1,2,3] comecou pela primeira vez no indice: " << indice << el; 
        // Imprime: indice 1
    }


    // -----------------------------------------------------------
    // 2. SEARCH_N (CAÇADOR DE REPETIÇÕES CONSECUTIVAS)
    // ⏱️ Complexidade: O(N)
    // Encontra a primeira vez que um mesmo número aparece N vezes seguidas.
    // Parâmetros: (início, fim, quantidade de vezes, número procurado)
    // -----------------------------------------------------------
    vector<ll> fila = {10, 5, 5, 20, 20, 20, 20, 30};
    
    // Quero achar a primeira vez que o número '20' aparece 3 vezes seguidas.
    ll quantidade = 3;
    ll valor_alvo = 20;
    
    auto it_search_n = search_n(all(fila), quantidade, valor_alvo);

    if (it_search_n != fila.end()) {
        ll pos = it_search_n - fila.begin();
        cout << "Achei tres 20s consecutivos comecando no indice: " << pos << el;
        // Imprime: indice 3
    }
}