#include <bits/stdc++.h>
using namespace std;
// N -> azuleijos de tamanho 1*M
// N*M -> tamanho do piso
// Forma de ocorrencia identica a do fibonnaci

/*
    Função para contar maneiras de cobrir piso NxM com azulejos 1xM
    Complexidade: O(N) tempo, O(N) espaço
*/

long long countWays(int n, int m) {
    // Vetor de DP para armazenar os resultados dos subproblemas
    // dp[i] significa: "quantas maneiras de preencher um chão de altura i"
    vector<long long> dp(n + 1, 0);
    
    dp[0] = 1; // Caso base: chão de altura 0 tem 1 maneira (não fazer nada)
    
    for (int i = 1; i <= n; i++) {
        // Opção 1: Colocar azulejo na horizontal (ocupa 1 linha)
        dp[i] = dp[i - 1];
        
        // Opção 2: Colocar M azulejos na vertical (ocupa M linhas)
        // Só é possível se a altura atual (i) for maior ou igual a M
        if (i >= m) {
            dp[i] += dp[i - m];
        }
    }
    
    return dp[n];
}

// --- FIM DO SNIPPET ---

// Exemplo de uso
void solve() {
    int n = 4;
    int m = 3;
    
    cout << "Entrada: " << n << " " << m << endl;
    long long ways = countWays(n, m);
    
    cout << "Numero de maneiras: " << ways << endl; 
    // Para N=4, M=3, a saída deve ser 3.
}

int main() {
    solve();
    return 0;
}

/*
Passo a passo da função countWays:
1. Inicializa um vetor dp de tamanho n+1 para armazenar o número de maneiras de preencher o chão de altura i.
2. Define o caso base dp[0] = 1, que representa uma maneira de preencher um chão de altura 0 (não fazer nada).
3. Itera de 1 até n, preenchendo o vetor dp:
   - Para cada altura i, adiciona dp[i-1] (colocando um azulejo na horizontal).
   - Se i for maior ou igual a m, adiciona dp[i-m] (colocando m azulejos na vertical).
4. Retorna dp[n], que contém o número total de maneiras de preencher o chão de altura n.

Input n -> Altura do piso (número de linhas)
Input m -> Largura do azulejo (número de linhas que o azulejo ocupa quando colocado verticalmente)
Output -> Número de maneiras de cobrir o piso NxM com azulejos 1xM

Example:
Input: 4 3
Output: 3

Explanation:
Para N=4 e M=3, as maneiras de cobrir o piso são:
1. Quatro azulejos na horizontal.
2. Três azulejos na horizontal e um azulejo na vertical.
3. Um azulejo na vertical e três azulejos na horizontal.
Portanto, a função retorna 3.
*/