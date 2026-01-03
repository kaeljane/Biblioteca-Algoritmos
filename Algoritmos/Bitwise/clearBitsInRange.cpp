#include <bits/stdc++.h>
using namespace std;

void clearBitsInRange(int &number, int i, int j) {
    int allOnes = ~0; // Máscara com todos os bits definidos como 1

    // Máscara com 1s antes do bit j e 0s do bit j em diante
    int leftMask = allOnes << (j + 1);

    // Máscara com 1s após o bit i e 0s até o bit i
    int rightMask = (1 << i) - 1;

    // Combina as duas máscaras para criar a máscara final
    int mask = leftMask | rightMask;

    // Aplica a máscara ao número original usando AND bit a bit
    number = number & mask;
}

int main() {
    int number, i, j;
    cin >> number >> i >> j;
    clearBitsInRange(number, i, j);
    cout << "Number after clearing bits from " << i << " to " << j << " is: " << number << endl;
    return 0;
}

/*
// Passo a passo de como limpar os bits em um intervalo [i, j] de um número:
// 1. Criar uma máscara com todos os bits definidos como 1 (~0).
// 2. Criar uma máscara à esquerda com 1s antes do bit j e 0s do bit j em diante (allOnes << (j + 1)).
// 3. Criar uma máscara à direita com 1s após o bit i e 0s até o bit i ((1 << i) - 1).
// 4. Combinar as duas máscaras usando OR bit a bit para criar a máscara final
// 5. Aplicar a máscara ao número original usando AND bit a bit para limpar os bits no intervalo [i, j].

Exemplos de input e output:

Input:
number: 29 (11101 em binário)
i: 1
j: 3
Output:
Number after clearing bits from 1 to 3 is: 17 (10001 em binário)

Explicação:
Original number:  11101 (29 em decimal)
Mask:            10001 (máscara com 0s dos bits 1 a 3)
Result:          10001 (17 em decimal) em decimal)

*/