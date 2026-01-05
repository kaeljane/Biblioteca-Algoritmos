#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Escolher o pivô (aqui escolhemos o último elemento)
        int pivot = arr[high];
        int i = low - 1; // Índice do menor elemento

        for (int j = low; j < high; j++) {
            // Se o elemento atual é menor ou igual ao pivô
            if (arr[j] <= pivot) {
                i++; // Incrementa o índice do menor elemento
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]); // Coloca o pivô na posição correta
        int pi = i + 1; // Índice do pivô

        // Chama recursivamente quickSort para os subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

/*
Passo a passo da função quickSort:
1. A função quickSort é chamada com os índices inicial (low) e final (high) do array.
2. Se low for menor que high, escolhe-se um pivô (neste caso, o último elemento do array).
3. Um loop percorre o array, comparando cada elemento com o pivô:
    - Se o elemento atual for menor ou igual ao pivô, incrementa-se o índice do menor elemento e troca-se os elementos.
4. Após o loop, o pivô é colocado na posição correta, trocando-o com o elemento na posição i+1.
5. A função é chamada recursivamente para os subarrays à esquerda e à direita do pivô.

Input arr -> Vetor de inteiros não ordenados
Input low -> Índice inicial do array
Input high -> Índice final do array
Output arr -> Vetor de inteiros ordenados em ordem crescente

Example:
Input: arr = {10, 7, 8, 9, 1, 5}
Output: arr = {1, 5, 7, 8, 9, 10}

Explanation:
O array é ordenado em ordem crescente usando o algoritmo Quick Sort.


*/