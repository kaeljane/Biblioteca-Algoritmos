/* ===================================================================
 * ❌ COMPARADOR DE DIVERGÊNCIAS (mismatch)
 * ===================================================================
 * Função: Compara dois vetores/strings paralelamente e encontra o 
 * PRIMEIRO elemento onde eles deixam de ser iguais.
 * * * 🚨 REGRAS DE OURO:
 * 1. O RETORNO (PAIR): Ele retorna um 'pair' de iteradores. 
 * Use 'it.first' para pegar o iterador do 1º vetor e 'it.second' 
 * para pegar o iterador do 2º vetor.
 * 2. SEGURANÇA CONTRA ERROS: A partir do C++14, a forma mais segura 
 * de usar é passando o começo e o fim dos DOIS vetores, ou seja,
 * usando o seu all() nos dois. Assim o C++ não dá erro de memória
 * (SegFault) se um vetor for mais curto que o outro!
 * =================================================================== */

#include <bits/stdc++.h>
#define ll long long
#define vl vector<long long>
#define all(v) (v).begin(), (v).end()
#define el '\n'
using namespace std;

void template_mismatch() {
    // -----------------------------------------------------------
    // 1. MISMATCH BÁSICO (ACHANDO O ERRO)
    // ⏱️ Complexidade: O(N), onde N é o tamanho do menor vetor.
    // -----------------------------------------------------------
    vl v1 = {10, 20, 30, 40, 50};
    vl v2 = {10, 20, 99, 40, 50}; 
    // O erro acontece no índice 2 (30 vs 99)

    // A função retorna um par (pair) de iteradores
    auto erro = mismatch(all(v1), all(v2));

    // Se o 'first' chegou no final do v1, significa que eles 
    // combinaram 100% (pelo menos até onde o menor deles permitiu)
    if (erro.first != v1.end()) {
        ll indice = erro.first - v1.begin(); // Pega a posição numérica
        cout << "A divergencia comecou no indice: " << indice << el;
        
        // Usamos o '*' para desempacotar o valor de dentro do iterador
        cout << "No Vetor 1 tinha o numero: " << *erro.first << el;
        cout << "No Vetor 2 tinha o numero: " << *erro.second << el;
    } else {
        cout << "Os vetores sao iguais (ou um eh prefixo exato do outro)." << el;
    }


    // -----------------------------------------------------------
    // 2. MISMATCH EM STRINGS (CENÁRIO CLÁSSICO DE MARATONA)
    // Muito usado para encontrar onde duas palavras começam a ficar diferentes.
    // -----------------------------------------------------------
    string gabarito = "COMPETITIVA";
    string resposta = "COMPUTADOR";

    auto divergencia = mismatch(all(gabarito), all(resposta));

    if (divergencia.first != gabarito.end()) {
        ll pos = divergencia.first - gabarito.begin();
        cout << "\nAs palavras divergem na letra de indice " << pos << el;
        cout << "Esperava '" << *divergencia.first << "', mas veio '" << *divergencia.second << "'" << el;
        // Imprime: As palavras divergem na letra de indice 4
        // Esperava 'E', mas veio 'U'
    }
}