#include <bits/stdc++.h>
using namespace std;

// Função auxiliar recursiva
void generate(int n, string current, vector<string>& result) {
    if (current.size() == n) {
        result.push_back(current);
        return;
    }

    // Decisão 1: adicionar '0'
    // (Sempre podemos adicionar 0, pois não cria conflito com "11")
    generate(n, current + "0", result);

    // Decisão 2: adicionar '1'
    // (Só podemos adicionar 1 se a string estiver vazia OU o último não for '1')
    if (current.empty() || current.back() != '1') {
        generate(n, current + "1", result);
    }

}

vector<string> binaryString(int n) {
    vector<string> result;
    generate(n, "", result);
    return result;
}