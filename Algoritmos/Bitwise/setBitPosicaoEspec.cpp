#include <bits/stdc++.h>
using namespace std;

int setBit(int number, int position) {
    return number | (1 << position);
}

int main() {
    int number, position;
    cin >> number >> position;
    cout << "Number after setting bit at position " << position << " is: " << setBit(number, position) << endl;
    return 0;
}

/*
output:
Number after setting bit at position 10 is: 1073

number: 10  -> 1010 (binário)
position: 1 -> 10 | (1 << 1) = 10 | 2 = 10 + 2 = 12

number: 10
position: 0 -> 10 | (1 << 0) = 10 | 1 = 10 + 1 = 11

*/
/*
Passo a passo de como definir o bit de um número em uma posição específica:
1. Criar um número com 1 na posição desejada e 0 em todas as outras posições. Isso é feito com (1 << position).
2. Realizar a operação OR bit a bit entre o número original e o número criado no passo 1.
3. O resultado é o número original com o bit na posição desejada definido como 1.
*/