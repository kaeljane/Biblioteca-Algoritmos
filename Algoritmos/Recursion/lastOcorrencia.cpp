#include <bits/stdc++.h>
using namespace std;

int lastOccurrence(const vector<int>& arr, int target, int index) {
    // Caso base: Se chegamos ao início do array sem encontrar o alvo
    if (index < 0) {
        return -1; // Indica que o alvo não foi encontrado
    }
    
    // Verifica se o elemento atual é o alvo
    if (arr[index] == target) {
        return index; // Retorna o índice da última ocorrência
    }
    
    // Chamada recursiva para o índice anterior
    return lastOccurrence(arr, target, index - 1);
}