#include <bits/stdc++.h>
using namespace std;

// um pré binPow, ainda tem como otimizar, codigo do binpow está em theory bumbers
int exponenciacaoRapida(int base, int expoente) {
    int resultado = 1;
    while (expoente > 0) {
        // Se o expoente for ímpar, multiplica a base pelo resultado
        if (expoente & 1) {
            resultado *= base;
        }
        // Eleva a base ao quadrado
        base *= base;
        // Divide o expoente por 2 (deslocamento à direita)
        expoente >>= 1;
    }
    return resultado;
}

int main() {
    int base, expoente;
    cin >> base >> expoente;
    cout << base << " elevado a " << expoente << " é: " << exponenciacaoRapida(base, expoente) << endl;
    return 0;
}

/*
Passo a passo de como realizar a exponenciação rápida usando operações bitwise:
1. Inicializar uma variável resultado com 1, que armazenará o resultado final.
2. Enquanto o expoente for maior que 0, repetir os seguintes passos:
   a. Verificar se o expoente é ímpar usando a operação AND bit a bit (expoente & 1).
      - Se for ímpar, multiplicar o resultado pela base.
   b. Elevar a base ao quadrado (base *= base).
   c. Dividir o expoente por 2 usando o operador de deslocamento à direita (expoente >>= 1).
3. Quando o expoente se tornar 0, o resultado conterá o valor de base elevado ao expoente original.

Exemplos de input e output:

Input: 
base: 2
expoente: 10
Output:
2 elevado a 10 é: 1024
Explicação:
2^10 = 1024

Input:
base: 3
expoente: 5
Output:
3 elevado a 5 é: 243

*/