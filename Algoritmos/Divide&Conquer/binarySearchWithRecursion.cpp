#include <bits/stdc++.h>
using namespace std;

// --- INICIO DO SNIPPET PARA O TEMPLATE ---

// Função Auxiliar Recursiva
// Recebe o vetor por referência (const vector<int>&) para economizar memória

// x -> elemento a ser buscado
// start -> índice inicial do intervalo de busca
// end -> índice final do intervalo de busca

int binarySearchHelper(const vector<int>& v, int x, int start, int end) {
    // Caso Base 1: O espaço de busca acabou (start passou do end)
    // Significa que o elemento não existe.
    if (start > end) {
        return -1;
    }

    // Calcula o meio.
    // Usamos essa fórmula para evitar 'Integer Overflow' em vetores gigantes
    int mid = start + (end - start) / 2;

    // Caso Base 2: Encontramos o elemento!
    if (v[mid] == x) {
        return mid;
    }

    // Recursão 1: O valor do meio é MAIOR que x?
    // Então x só pode estar na esquerda (números menores).
    if (v[mid] > x) {
        return binarySearchHelper(v, x, start, mid - 1);
    }

    // Recursão 2: O valor do meio é MENOR que x?
    // Então x só pode estar na direita (números maiores).
    return binarySearchHelper(v, x, mid + 1, end);
}

// Função Principal (Wrapper)
int binarySearch(vector<int> v, int x) {
    // Chama a auxiliar definindo o intervalo inicial como o vetor inteiro
    return binarySearchHelper(v, x, 0, v.size() - 1);
}

// --- FIM DO SNIPPET ---

// Exemplo de uso
void solve() {
    vector<int> arr = {1, 3, 5, 7, 9};
    int x = 3;
    
    int index = binarySearch(arr, x);
    
    cout << "Array: {1, 3, 5, 7, 9}" << endl;
    cout << "Procurando: " << x << endl;
    
    if (index != -1) {
        cout << "Encontrado no indice: " << index << endl;
    } else {
        cout << "Nao encontrado." << endl;
    }
}

int main() {
    solve();
    return 0;
}


/*
Passo a passo da função binarySearch:
1. A função binarySearch é chamada com o vetor e o elemento a ser buscado.
2. A função auxiliar binarySearchHelper é chamada com os índices inicial (start) e final (end) do vetor.
3. Na função auxiliar, verifica-se se o espaço de busca acabou (start > end). Se sim, retorna -1 (elemento não encontrado).
4. Calcula-se o índice do meio do intervalo atual.
5. Compara-se o elemento do meio com o elemento buscado (x):
    - Se forem iguais, retorna o índice do meio.
    - Se o elemento do meio for maior que x, chama-se a função recursivamente para a metade esquerda do vetor.
    - Se o elemento do meio for menor que x, chama-se a função recursivamente para a metade direita do vetor.

Input v -> Vetor de inteiros ordenados
Input x -> Elemento a ser buscado
Output -> Índice do elemento x no vetor v ou -1 se não encontrado

Example:
Input: v = {1, 3, 5, 7, 9}, x = 3
Output: 1

Explanation:
O elemento 3 está presente no vetor na posição de índice 1.

*/