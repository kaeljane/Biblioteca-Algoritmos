#include <bits/stdc++.h>
using namespace std;

int rotated_search(vector<int>& a, int key) {
    int n = a.size();

    // logic
    int s = 0;
    int e = n - 1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (a[mid] == key) {
            return mid;
        }

        // 2 cases
        // left half is sorted
        if (a[s] <= a[mid]) {
            if (key >= a[s] && key <= a[mid]) {
                e = mid - 1;
            } 
            else {
                s = mid + 1;
            }
        }
        // right half is sorted
        else {
            if (key >= a[mid] && key <= a[e]) {
                s = mid + 1;
            } 
            else {
                e = mid - 1;
            }
        }
    }

    return -1;

}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int key = 0;
    int index = rotated_search(arr, key);
    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    return 0;
}

/*
Passo a passo da função rotated_search:
1. A função rotated_search é chamada com o vetor rotacionado e o elemento a ser buscado.
2. Inicializa os índices de início (s) e fim (e) do vetor.
3. Enquanto o índice de início for menor ou igual ao índice de fim:
    - Calcula o índice do meio (mid).
    - Se o elemento no meio for igual ao elemento buscado, retorna o índice mid.
    - Verifica qual metade do vetor está ordenada:
        a. Se a metade esquerda estiver ordenada:
            - Verifica se o elemento buscado está dentro dessa metade.
                - Se sim, ajusta o índice de fim (e) para mid - 1.
                - Caso contrário, ajusta o índice de início (s) para mid + 1.
        b. Se a metade direita estiver ordenada:
            - Verifica se o elemento buscado está dentro dessa metade.
                - Se sim, ajusta o índice de início (s) para mid + 1.
                - Caso contrário, ajusta o índice de fim (e) para mid - 1.
*/