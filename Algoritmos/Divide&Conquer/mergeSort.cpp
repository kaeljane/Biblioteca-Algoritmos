#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int s, int e) {
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    // len1 -> tamanho do primeiro subarray
    // len2 -> tamanho do segundo subarray

    // criando arrays temporarios
    vector<int> left(len1);
    vector<int> right(len2);

    // copiando os valores para os arrays temporarios
    for (int i = 0; i < len1; i++) {
        left[i] = arr[s + i];
    }
    for (int j = 0; j < len2; j++) {
        right[j] = arr[mid + 1 + j];
    }

    // merge os arrays temporarios de volta para arr[s..e]
    int i = 0; // indice inicial do primeiro subarray
    int j = 0; // indice inicial do segundo subarray
    int k = s; // indice inicial do subarray mesclado

    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // copiando os elementos restantes de left[], se houver algum
    while (i < len1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // copiando os elementos restantes de right[], se houver algum
    while (j < len2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int s, int e) {
    // base case
    if (s >= e) return;

    // rec case
    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    return merge(arr, s, e);

}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size();

    cout << "Array original: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "Array ordenado: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
Passo a passo da função mergeSort:
1. A função mergeSort é chamada recursivamente para dividir o array em subarrays menores até que cada subarray tenha um único elemento (caso base).
2. Após atingir o caso base, a função merge é chamada para mesclar os subarrays de volta em um array ordenado.
3. A função merge cria arrays temporários para os dois subarrays, copia os elementos para esses arrays, e então mescla-os de volta no array original em ordem crescente.

Input arr -> Vetor de inteiros não ordenados
Input s -> Índice inicial do array
Input e -> Índice final do array
Output -> Vetor de inteiros ordenados em ordem crescente

Example:
Input: arr = {38, 27, 43, 3, 9, 82, 10}
Output: arr = {3, 9, 10, 27, 38, 43, 82}

Explanation:
O array original é dividido repetidamente até que cada subarray contenha um único elemento. Em seguida, esses subarrays são mesclados de volta em ordem crescente, resultando em um array totalmente ordenado.

*/