/* ===================================================================
 * 🔍 BUSCAS LINEARES (find, find_if, find_first_of...)
 * ===================================================================
 * Função: Procura a primeira ocorrência de um valor, condição ou 
 * subsequência dentro de um vetor/string.
 * * 🚨 REGRAS DE OURO:
 * 1. O RETORNO (ITERADOR): Eles retornam um iterador. Para saber se 
 * ACHOU, compare com v.end(). Para saber o ÍNDICE (posição numérica),
 * subtraia v.begin() do resultado.
 * 2. CUIDADO COM TLE: Sempre olhe o limite de N da questão antes de usar!
 * =================================================================== */
#include <bits/stdc++.h>
#define ll long long
#define all(v) (v).begin(), (v).end()
#define el '\n'
using namespace std;

void template_find() {
    ll n = 6;
    vector<ll> v = {10, 20, 30, 40, 50, 60};

    // -----------------------------------------------------------
    // 1. FIND (BUSCA EXATA)
    // ⏱️ Complexidade: O(N) no pior caso. 
    // Acha a primeira aparição de um valor específico.
    // -----------------------------------------------------------
    ll alvo = 30;
    auto it1 = find(all(v), alvo);

    if (it1 != v.end()) {
        ll indice = it1 - v.begin(); // <-- O truque para virar índice (0, 1, 2...)
        cout << "Achei o 30 no indice: " << indice << el;
    } 
    else {
        cout << "Nao existe 30 no vetor." << el;
    }


    // -----------------------------------------------------------
    // 2. FIND_IF e FIND_IF_NOT (BUSCA COM CONDIÇÃO / LAMBDA)
    // ⏱️ Complexidade: O(N) no pior caso.
    // Acha o primeiro elemento que PASSA (if) ou FALHA (if_not) num teste.
    // -----------------------------------------------------------
    auto it2 = find_if(all(v), [](ll x) { return x > 35; });
    
    // find_if_not acharia o primeiro número que NÃO é maior que 35 (ou seja, o 10).
    // auto it3 = find_if_not(all(v), [](ll x) { return x > 35; });

    if (it2 != v.end()) {
        cout << "Primeiro > 35 eh o: " << *it2 << el; // Usa '*' para ler o valor direto
    }


    // -----------------------------------------------------------
    // 3. FIND_FIRST_OF (INTERSEÇÃO DE VETORES/STRINGS)
    // ⏱️ Complexidade: O(N * M) onde N e M são os tamanhos das strings/vetores.
    // Cuidado: Se as duas strings tiverem tamanho 10^5, isso dá 10^10 operações (TLE!).
    // Acha o primeiro elemento do Vetor A que também existe no Vetor B.
    // -----------------------------------------------------------
    string palavra = "cbtrux";
    string vogais = "aeiou";
    
    // Procura na 'palavra' o primeiro caractere que apareça em 'vogais'
    auto it4 = find_first_of(all(palavra), all(vogais));
    
    if (it4 != palavra.end()) cout << "A primeira vogal eh: " << *it4 << el; // Imprime 'u'


    // -----------------------------------------------------------
    // 4. FIND_END (BUSCA DE SUB-VETOR / PADRÃO)
    // ⏱️ Complexidade: O(N * M) no pior caso.
    // Acha a ÚLTIMA vez que um vetor pequeno aparece dentro de um grandão.
    // Nota: O nome engana! Ele procura um padrão inteiro, mas pega a última ocorrência.
    // -----------------------------------------------------------
    
    vector<ll> grandao = {1, 2, 3, 4, 1, 2, 3, 8};
    vector<ll> padrao = {1, 2, 3};
    // Ele vai ignorar o "1, 2, 3" do começo e retornar o iterador do segundo "1, 2, 3".
    
    auto it5 = find_end(all(grandao), all(padrao));
    
    if (it5 != grandao.end()) {
        ll indice = it5 - grandao.begin();
        cout << "A ultima vez que o padrao apareceu comecou no indice: " << indice << el;
    }


    // -----------------------------------------------------------
    // 5. ADJACENT_FIND (BUSCA POR VIZINHOS)
    // ⏱️ Complexidade: O(N) no pior caso. Ele faz exatamente N-1 comparações.
    // Acha o primeiro par de elementos consecutivos que são iguais
    // ou que cumprem uma condição específica usando Lambda dupla.
    // -----------------------------------------------------------
    
    // Exemplo A: Procurando vizinhos que são exatamente iguais
    vector<ll> duplicados = {10, 20, 30, 30, 40, 50};
    auto it6 = adjacent_find(all(duplicados));

    if (it6 != duplicados.end()) {
        ll indice = it6 - duplicados.begin();
        cout << "Achei vizinhos iguais (" << *it6 << ") no indice: " << indice << el;
    }

    // Exemplo B: Lambda de 2 parâmetros (a = esq, b = dir)
    // Achar onde a ordem estritamente crescente quebra (esquerda > direita)
    vector<ll> baguncado = {1, 3, 5, 4, 8, 9}; 
    
    auto it7 = adjacent_find(all(baguncado), [](ll a, ll b) {
        return a > b; 
    });

    if (it7 != baguncado.end()) {
        ll pos = it7 - baguncado.begin();
        cout << "A ordem quebrou no indice: " << pos << " (par: " << *it7 << " > " << *(it7 + 1) << ")" << el;
    }
}