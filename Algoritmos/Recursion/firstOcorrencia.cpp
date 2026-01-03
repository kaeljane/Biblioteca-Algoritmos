#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(const vector<int>& arr, int target, int index = 0) {
    // Caso base: Se chegamos ao final do array sem encontrar o alvo
    if (index >= arr.size()) {
        return -1; // Indica que o alvo não foi encontrado
    }
    
    // Verifica se o elemento atual é o alvo
    if (arr[index] == target) {
        return index; // Retorna o índice da primeira ocorrência
    }
    
    // Chamada recursiva para o próximo índice
    return firstOccurrence(arr, target, index + 1);
}