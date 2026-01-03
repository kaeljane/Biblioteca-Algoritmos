#include <bits/stdc++.h>
using namespace std;

int substituirBits(int numeroDestino, int numeroFonte, int i, int j) {
    // Passo 1: Limpar os bits de i a j em numeroDestino
    int allOnes = ~0; // Máscara com todos os bits definidos como 1

    // Máscara com 1s antes do bit j e 0s do bit j em diante
    int leftMask = allOnes << (j + 1);

    // Máscara com 1s após o bit i e 0s até o bit i
    int rightMask = (1 << i) - 1;

    // Combina as duas máscaras para criar a máscara final
    int mask = leftMask | rightMask;

    // Aplica a máscara ao numeroDestino usando AND bit a bit
    int numeroDestinoLimpo = numeroDestino & mask;

    // Passo 2: Preparar os bits de numeroFonte para inserção
    int numeroFonteShifted = numeroFonte << i;

    // Passo 3: Combinar os dois números usando OR bit a bit
    return numeroDestinoLimpo | numeroFonteShifted;
}

int main() {
    int numeroDestino, numeroFonte, i, j;
    cin >> numeroDestino >> numeroFonte >> i >> j;
    int resultado = substituirBits(numeroDestino, numeroFonte, i, j);
    cout << "Número após substituir os bits de " << i << " a " << j << " é: " << resultado << endl;
    return 0;
}

/* Passo a passo de como substituir os bits de i a j em um número:
1. Criar uma máscara para limpar os bits de i a j em numeroDestino.
2. Aplicar a máscara ao numeroDestino usando AND bit a bit para limpar os bits no intervalo [i, j].
3. Deslocar numeroFonte para a esquerda por i posições para alinhar os bits corretamente
4. Combinar o numeroDestino limpo e o numeroFonte deslocado usando OR bit a bit para substituir os bits.

Exemplos de input e output:
Input:
numeroDestino: 1024 (1000[00000]00 em binário)
numeroFonte: 19 (10011 em binário)
i: 2 -> ultimo bit a ser substituído
j: 6 -> primeiro bit a ser substituído
Output:
Número após substituir os bits de 2 a 6 é: 1100 (1000[10011]00 em binário)

Explicação:
Original numeroDestino:  10000000000 (1024 em decimal)
Mask:                   11110000011 (máscara com 0s dos bits 2 a 6)
numeroDestino limpo:    10000000000 (1024 em decimal)
numeroFonte deslocado:  00000010011 << 2 = 000001001100 (76 em decimal)
Result:                 10001001100 (1100 em decimal)



*/