#include <bits/stdc++.h>
using namespace std;

string numeroDecimalParaBinario(int numero) {
    if (numero == 0) return "0";
    string binario = "";
    while (numero > 0) {
        binario = to_string(numero & 1) + binario; // Adiciona o bit menos significativo
        numero >>= 1; // Desloca o número para a direita
    }
    return binario;
}

int main() {
    int numero;
    cin >> numero;
    cout << "Número " << numero << " em binário é: " << numeroDecimalParaBinario(numero) << endl;
    return 0;
}

/*
Passo a passo de como converter um número decimal para binário usando operações bitwise:
1. Inicializar uma string vazia para armazenar a representação binária.
2. Enquanto o número for maior que 0, repetir os seguintes passos:
   a. Obter o bit menos significativo do número usando a operação AND bit a bit (numero & 1).
   b. Adicionar o bit obtido no passo 2a ao início da string binária.
   c. Deslocar o número para a direita em uma posição usando o operador de deslocamento à direita (numero >>= 1).
3. Quando o número se tornar 0, a string conterá a representação binária do número original.
4. Retornar a string binária.

Exemplos de input e output:

Input:
numero: 10
Output:
Número 10 em binário é: 1010
Explicação:
10 em decimal é representado como 1010 em binário:
10 & 1 = 0 -> binário = "0"
10 >> 1 = 5
5 & 1 = 1 -> binário = "10"
5 >> 1 = 2
2 & 1 = 0 -> binário = "010"
2 >> 1 = 1
1 & 1 = 1 -> binário = "1010"
1 >> 1 = 0 (fim do loop)
Resultado final: "1010"

*/