#include <bits/stdc++.h>
using namespace std;

// Função para calcular o número de maneiras de emparelhar n amigos
// Complexidade: O(N)
int friendsPairing(int n) {
    // Casps bases simples para evitar acessar índices negativos
    if (n <= 2) return n;
    // Se n=1 retorna 1 (so {1})
    // Se n=2 retorna 2 ({1,2} ou {1}{2})

    vector<int> dp(n+1);

    // Preechendo os base cases no array dp
    dp[1] = 1;
    dp[2] = 2;

    //Construindo de baixo para cima (Bottom-Up)
    for (int i = 3; i <= n; i++) {
        // Dois casos:
        // 1. O amigo i fica sozinho -> dp[i-1]
        // 2. O amigo i se emparelha com qualquer um dos (i-1) amigos -> (i-1)*dp[i-2]
        dp[i] = dp[i-1] + (i-1) * dp[i-2];
    }

    return dp[n];
}


/*
Passo a passo da função friendsPairing:
1. Verifica os casos base: se n é 1 ou 2, retorna n diretamente.
2. Cria um vetor dp para armazenar o número de maneiras de emparelhar amigos    de 1 até n.
3. Inicializa os valores base dp[1] e dp[2].
4. Usa um loop para preencher o vetor dp de 3 até n, aplicando a fórmula de recursão.
5. Retorna o valor dp[n], que contém o número total de maneiras de emparelhar n amigos.

Input n -> Número inteiro não negativo representando o número de amigos
Output -> Número de maneiras de emparelhar n amigos
Example:
Input: 4
Output: 10

Explanation:
Para n=4, as possíveis maneiras de emparelhar são:
1. {1}{2}{3}{4} (todos sozinhos)
2. {1,2}{3}{4} (1 e 2 emparelhados)
3. {1}{2,3}{4} (2 e 3 emparelhados)
4. {1}{2}{3,4} (3 e 4 emparelhados)
5. {1,2}{3,4} (1 e 2 emparelhados; 3 e 4 emparelhados)
6. {1,3}{2}{4} (1 e 3 emparelhados)
7. {1,4}{2}{3} (1 e 4 emparelhados)
8. {1,2}{3,4} (1 e 2 emparelhados; 3 e 4 emparelhados) - já considerado acima
9. {1,3}{2,4} (1 e 3 emparelhados; 2 e 4 emparelhados)
10. {1,4}{2,3} (1 e 4 emparelhados; 2 e 3 emparelhados)

Portanto há um total de 10 maneiras de emparelhar os amigos.

*/