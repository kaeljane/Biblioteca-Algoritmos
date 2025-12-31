#include <bits/stdc++.h>
using namespace std;

int getBit(int number, int position) {
    return (number >> position) & 1;
}

int main() {
    int number, position;
    cin >> number >> position;
    cout << "The bit at position " << position << " is: " << getBit(number, position) << endl;
    return 0;
}

/*
Passo a passo de como obter o bit de um número em uma posição específica:
1. Deslocar o número para a direita pela quantidade de posições desejadas. Isso move o bit na posição desejada para a posição 0 (menos significativa).
2. Aplicar a operação AND bit a bit com 1. Isso isola o bit na posição 0. Se o bit for 1, o resultado será 1; se for 0, o resultado será 0. 
*/