#include <bits/stdc++.h>
using namespace std;

int updateBit(int number, int position, int bitValue) {
    number = number & ~(1 << position);
    return number | (bitValue << position);
}
int main() {
    int number, position, bitValue;
    cin >> number >> position >> bitValue;
    cout << "Number after updating bit at position " << position << " to " << bitValue << " is: " << updateBit(number, position, bitValue) << endl;
    return 0;
}

/*
Passo a passo de como atualizar o bit de um número em uma posição específica:
1. Limpar o bit na posição desejada. Isso é feito com number & ~(1 << position).
2. Definir o bit para o valor desejado (0 ou 1). Isso é feito com number | (bitValue << position).
3. O resultado é o número original com o bit na posição desejada atualizado para o valor especificado.
Exemplos de input e output:
Input:
number: 13 (1101 em binário)
position: 1
bitValue: 0
Output:
Number after updating bit at position 1 to 0 is: 13 (1101 em binário)

Explicação:
Original number:  1101 (13 em decimal)
Mask to clear:   1101 (máscara com 0 na posição 1)
Result after clear: 1101 (13 em decimal)
Set bit to 0:    0000 (0 << 1)
Final Result:    1101 (13 em decimal)

Input:
number: 13 (1101 em binário)
position: 0
bitValue: 0
Output:
Number after updating bit at position 0 to 0 is: 12 (1100 em binário)
Explicação:
Original number:  1101 (13 em decimal)
Mask to clear:   1110 (máscara com 0 na posição 0)
Result after clear: 1100 (12 em decimal)
Set bit to 0:    0000 (0 << 0)
Final Result:    1100 (12 em decimal)
*/