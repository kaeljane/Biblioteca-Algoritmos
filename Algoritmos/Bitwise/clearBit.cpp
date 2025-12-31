#include <bits/stdc++.h>
using namespace std;

int clearBit(int number, int position) {
    return number & ~(1 << position);
}

int main() {
    int number, position;
    cin >> number >> position;
    cout << "Number after clearing bit at position " << position << " is: " << clearBit(number, position) << endl;
    return 0;
}

/*
Passo a passo de como limpar o bit de um número em uma posição específica:
1. Criar um número com 0 na posição desejada e 1 em todas as outras posições. Isso é feito com ~(1 << position).
2. Realizar a operação AND bit a bit entre o número original e o número criado no passo 1.
3. O resultado é o número original com o bit na posição desejada definido como 0.

Exemplos de input e output:
Input:
number: 13 (1101 em binário)
position: 2
Output:
Number after clearing bit at position 2 is: 9 (1001 em binário)

Explicação:
Original number:  1101 (13 em decimal)
Mask:            1011 (máscara com 0 na posição 2)
Result:          1001 (9 em decimal)

*/