#include <bits/stdc++.h>
using namespace std;

int clearLastIBits(int number, int i) {
    return number & (~0 << i);
}

int main() {
    int number, i;
    cin >> number >> i;
    cout << "Number after clearing last " << i << " bits is: " << clearLastIBits(number, i) << endl;
    return 0;
}

/*
Passo a passo de como limpar os últimos i bits de um número:
1. Criar uma máscara que tenha 0s nos últimos i bits e 1s em todas as outras posições. Isso é feito com (~0 << i).
2. Realizar a operação AND bit a bit entre o número original e a máscara criada no passo 1.
3. O resultado é o número original com os últimos i bits definidos como 0.

Exemplos de input e output:

Input:
number: 29 (11101 em binário)
i: 3

Output:
Number after clearing last 3 bits is: 24 (11000 em binário)

Explicação:
Original number:  11101 (29 em decimal)
Mask:            11000 (máscara com 0s nos últimos 3 bits)
Result:          11000 (24 em decimal)
*/