#include <bits/stdc++.h>
using namespace std;

// Helper function to merge two sorted segments
void merge(vector<vector<int>>& v, int start, int mid, int end, int n) {
    vector<int> temp;
    int i = start;    // Pointer for the left half
    int j = mid + 1;  // Pointer for the right half

    // Standard Merge Logic
    while (i <= mid && j <= end) {
        // Map 1D index 'i' to 2D coordinates (r1, c1)
        int r1 = i / n;
        int c1 = i % n;

        // Map 1D index 'j' to 2D coordinates (r2, c2)
        int r2 = j / n;
        int c2 = j % n;

        // Compare elements
        if (v[r1][c1] <= v[r2][c2]) {
            temp.push_back(v[r1][c1]);
            i++;
        } else {
            temp.push_back(v[r2][c2]);
            j++;
        }
    }

    // Add remaining elemnts from the left half
    while (i <= mid) {
        int r1 = i / n;
        int c1 = i % n;
        temp.push_back(v[r1][c1]);
        i++;
    }

    // Add remaining elements from the right half
    while (j <= end) {
        int r2 = j / n;
        int c2 = j % n;
        temp.push_back(v[r2][c2]);
        j++;
    }

    // Copy sorted elements back to original 2D array
    for (int k = 0; k < temp.size(); k++) {
        int idx = start + k;
        int r = idx / n;
        int c = idx % n;
        v[r][c] = temp[k];
    }
}

void mergeSortHelper(vector<vector<int>>& v, int start, int end, int n) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        // Recursively sort the first half
        mergeSortHelper(v, start, mid, n);

        // Recursively sort the second half
        mergeSortHelper(v, mid + 1, end, n);

        // Merge the two halves
        merge(v, start, mid, end, n);
    }
}

// Main function required by the problem
vector<vector<int>> mergeSort2D(vector<vector<int>>& v) {
    int m = v.size();    // Number of rows
    if (m == 0) return v;
    int n = v[0].size(); // Number of columns

    // Call the helper on the range [0, total_elements - 1]
    mergeSortHelper(v, 0, m * n - 1, n);
    return v;
}

/*
Passo a passo da função mergeSort2D:
1. A função mergeSort2D é chamada com uma matriz 2D.
2. Calcula o número de linhas (m) e colunas (n) da matriz.
3. Chama a função auxiliar mergeSortHelper com os índices inicial (0) e final (m*n - 1) da matriz "achatada".
4. A função mergeSortHelper divide recursivamente a matriz em duas metades até que cada segmento tenha um único elemento.
5. A função merge combina os segmentos ordenados, mapeando os índices 1D de volta para coordenadas 2D.

Input v -> Matriz 2D de inteiros não ordenados
Output v -> Matriz 2D de inteiros ordenados em ordem crescente

Example:
Input: v = {{3, 1, 4}, {2, 5, 6}}
Output: v = {{1, 2, 3}, {4, 5, 6}}

Explanation:
A matriz é ordenada em ordem crescente usando o algoritmo Merge Sort adaptado para matrizes 2D.
*/