#include <bits/stdc++.h>
using namespace std;

// --- INICIO DO SNIPPET PARA O TEMPLATE ---

// Define o limite máximo da soma possível. 
// Em competições, geralmente 20000 ou 100000 cobre a maioria dos casos.
// Se os números forem pequenos (<=1000) e N <= 100, 100000 sobra.
const int MAX_SUM = 20000; 

// Complexidade: O(N * MAX_SUM / 64) -> Muito rápido por causa das operações de bit
vector<bool> subsetSumQueries(vector<int>& num, vector<int>& query) {
    bitset<MAX_SUM> dp;
    dp[0] = 1; // A soma 0 é sempre possível (subconjunto vazio)
    
    // Passo 1: Pré-calcular TODAS as somas possíveis
    for (int x : num) {
        // A mágica: Desloca os bits existentes por 'x' e une com o estado atual
        dp |= (dp << x);
    }
    
    // Passo 2: Responder as queries em O(1)
    vector<bool> results;
    for (int q : query) {
        if (q < MAX_SUM) {
            results.push_back(dp[q]); // Verifica se o bit 'q' está ligado
        } else {
            results.push_back(false); // Soma maior que o limite definido
        }
    }
    
    return results;
}

// --- FIM DO SNIPPET ---

// Exemplo de uso
void solve() {
    vector<int> num = {1, 2, 3};
    vector<int> query = {5, 3, 8};
    
    vector<bool> result = subsetSumQueries(num, query);
    
    // Formatar saída como booleanos
    cout << "{";
    for(size_t i = 0; i < result.size(); i++) {
        cout << (result[i] ? "Yes" : "No");
        if(i < result.size() - 1) cout << ", ";
    }
    cout << "}" << endl;
}

int main() {
    solve();
    return 0;
}