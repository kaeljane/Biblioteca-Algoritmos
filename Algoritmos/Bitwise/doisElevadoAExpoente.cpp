#include <bits/stdc++.h>
using namespace std;

int verificarSePoderDeDois(int number) {
    return (number > 0) && ((number & (number - 1)) == 0);
}

int doisPoderes(int exponent) {
    return 1 << exponent;
}

int main() {
    int exponent;
    cin >> exponent;
    cout << "2 elevado a " << exponent << " é: " << doisPoderes(exponent) << endl;

    // dois poderes verificacao
    int number;
    cin >> number;
    if (verificarSePoderDeDois(number)) {
        cout << number << " é uma potência de 2." << endl;
    } 
    else {
        cout << number << " não é uma potência de 2." << endl;
    }

    return 0;
}

/*
Passo a passo de como calcular 2 elevado a um número usando operações bitwise:
1. Entender que 2 elevado a n pode ser representado como 1 deslocado para a esquerda n vezes.
2. Usar o operador de deslocamento à esquerda (<<) para deslocar o bit 1 para a esquerda pelo número de posições igual ao expoente.
3. O resultado da operação é 2 elevado ao expoente desejado.

Exemplos de input e output:
Input:
exponent: 5
Output:
2 elevado a 5 é: 32

Explicação:
1 em binário:        00000001
Deslocar 1 para a esquerda 5 vezes:
Resultado:          00100000 (32 em decimal)

*/