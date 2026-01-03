#include <bits/stdc++.h>
using namespace std;

bool checkIfArrayIsSorted(const vector<int>& arr, int index = 0) {
    // Caso base: Se chegamos ao final do array, está ordenado
    if (index >= arr.size() - 1) {
        return true;
    }
    
    // Verifica o par atual e faz a chamada recursiva para o próximo índice
    if (arr[index] > arr[index + 1]) {
        return false; // Encontrou um par fora de ordem
    }
    
    return checkIfArrayIsSorted(arr, index + 1);
}