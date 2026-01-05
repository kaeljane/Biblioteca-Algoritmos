#include <bits/stdc++.h>
using namespace std;
// Backtracking ou Força Bruta Inteligente
// Função auxiliar recursiva
void generate(int n, string current, vector<string>& result) {
    if (current.size() == n) {
        result.push_back(current);
        return;
    }

    // Decisão 1: adicionar '0'
    // (Sempre podemos adicionar 0, pois não cria conflito com "11")
    generate(n, current + "0", result);

    // Decisão 2: adicionar '1'
    // (Só podemos adicionar 1 se a string estiver vazia OU o último não for '1')
    if (current.empty() || current.back() != '1') {
        generate(n, current + "1", result);
    }

}

vector<string> binaryString(int n) {
    vector<string> result;
    generate(n, "", result);
    return result;
}

/*
Passo a passo da função binaryString:
1. A função binaryString inicializa um vetor para armazenar os resultados e chama a função auxiliar generate.
2. A função generate constrói recursivamente as strings binárias:
   - Se o tamanho da string atual for igual a n, adiciona-a ao resultado.
   - Sempre tenta adicionar '0' à string atual.
   - Tenta adicionar '1' somente se a string atual estiver vazia ou o último caractere não for '1', evitando assim "11".
3. A função retorna o vetor contendo todas as strings binárias válidas de comprimento n.

Input n -> Número inteiro não negativo representando o comprimento das strings binárias
Output -> Vetor de strings binárias de comprimento n sem "11"

Example:
Input: 3
Output: ["000", "001", "010", "100", "101"]

Explanation:
As strings binárias de comprimento 3 sem "11" são:
1. "000"
2. "001"
3. "010"
4. "100"
5. "101"
Portanto, a função retorna essas 5 strings.

*/