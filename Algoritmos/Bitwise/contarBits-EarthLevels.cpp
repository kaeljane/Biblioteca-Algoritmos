#include <bits/stdc++.h>
using namespace std;

int contarBits(int number) {
    int count = 0;
    while (number) {
        count += number & 1; // Incrementa se o último bit for 1
        number >>= 1;        // Desloca o número para a direita
    }
    return count;
}

int contarBitsHackerRank(int number) {
    int count = 0;
    while (number) {
        number &= (number - 1); // Remove o último bit definido como 1
        count++;
    }
    return count;
}

int minJumpsBuiltIn(int n) {
    return __builtin_popcount(n);
}

int main() {
    int number;
    cin >> number;
    cout << "Número de bits definidos como 1 em " << number << " é: " << contarBits(number) << endl;

    cout << "Número de bits definidos como 1 em " << number << " (método HackerRank) é: " << contarBitsHackerRank(number) << endl;
    
    return 0;
}

/*
Passo a passo de como contar o número de bits definidos como 1 em um número:

1. Inicializar um contador para armazenar o número de bits definidos como 1.
2. Usar um loop para iterar enquanto o número for diferente de zero.
3. Em cada iteração, verificar o último bit do número usando a operação AND bit a bit com 1 (number & 1).
   - Se o resultado for 1, incrementa o contador.
4. Deslocar o número para a direita em uma posição usando o operador de deslocamento à direita (>>= 1).
5. Repetir os passos 3 e 4 até que o número se torne zero
6. Retornar o valor do contador, que representa o número de bits definidos como 1.

Exemplos de input e output:
Input:
number: 29 (11101 em binário)
Output:
Número de bits definidos como 1 em 29 é: 4
Explicação:
29 em binário é 11101, que tem quatro bits definidos como 1.

*/