/*
O problema pede para achar o único número que não se repete, com duas restrições importantes:

Tempo Linear O(N): Você só pode passar pelo array uma vez (ou poucas vezes).

Sem espaço extra O(1): Você não pode criar outro array, mapa ou tabela de hash para contar frequências.

A solução perfeita usa a operação XOR (^ em C++).

*/

#include <bits/stdc++.h>
using namespace std;

// --- INICIO DO SNIPPET PARA O TEMPLATE ---

// Função para encontrar elemento único em array de duplicatas
// Complexidade: O(N) tempo, O(1) espaço
// Requisito: Todos os elementos aparecem 2 vezes, exceto um.
int findUnique(const vector<int>& nums) {
    int uniqueNum = 0;
    
    for (int num : nums) {
        uniqueNum ^= num; // Aplica XOR acumulativo
    }
    
    return uniqueNum;
}

// --- FIM DO SNIPPET ---

// Exemplo de uso dentro do seu formato de 'solve'
void solve() {
    // Exemplo do problema
    vector<int> nums = {1, 2, 3, 1, 4, 2, 3};
    
    int result = findUnique(nums);
    
    cout << "Input: { ";
    for(int n : nums) cout << n << " ";
    cout << "}" << endl;
    
    cout << "Unique number: " << result << endl;
}

int main() {
    solve();
    return 0;
}