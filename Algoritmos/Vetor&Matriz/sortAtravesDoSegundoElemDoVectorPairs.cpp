#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Necessário para usar o sort

using namespace std;

// Função principal solicitada pelo problema
vector<pair<string, int>> sortFruits(vector<pair<string, int>> v, string S) {
    
    if (S == "price") {
        // Ordena pelo preço (segundo elemento do par)
        sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second < b.second; // Ordem crescente de preço
        });
    } 
    else if (S == "name") {
        // Ordena pelo nome (primeiro elemento do par)
        sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.first < b.first; // Ordem alfabética (lexicográfica)
        });
    }
    
    return v;
}

// Main para testar o exemplo da imagem
int main() {
    vector<pair<string, int>> fruits = {
        {"Mango", 100},
        {"Guava", 70},
        {"Grapes", 40},
        {"Apple", 60},
        {"Banana", 30}
    };

    string S = "price";

    vector<pair<string, int>> sortedFruits = sortFruits(fruits, S);

    cout << "Ordenado por " << S << ":" << endl;
    for (auto p : sortedFruits) {
        cout << "(\"" << p.first << "\", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}