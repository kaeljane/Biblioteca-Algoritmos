#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// --- INICIO DO SNIPPET PARA O TEMPLATE ---

// Função para rotacionar matriz N x N em 90 graus HORÁRIO
// Complexidade: O(N^2) tempo, O(1) espaço extra
void rotate90CW(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // Passo 1: Transpor a matriz (trocar linhas por colunas)
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // Passo 2: Inverter cada linha
    for (int i = 0; i < n; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// --- FIM DO SNIPPET ---

// Exemplo de uso dentro do seu formato de 'solve'
void solve() {
    // Exemplo do problema
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotate90CW(matrix);

    // Imprimir para conferir (formato de saída do problema)
    cout << "[";
    for (int i = 0; i < matrix.size(); i++) {
        cout << "[";
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << (j < matrix[i].size() - 1 ? "," : "");
        }
        cout << "]" << (i < matrix.size() - 1 ? "," : "");
    }
    cout << "]" << endl;
}

int main() {
    solve();
    return 0;
}

/*
   MACEITES DE MATRIZES (N x N)
   
   1. Transpor (Troca linha por coluna):
      for(i=0..n) for(j=i+1..n) swap(m[i][j], m[j][i]);

   2. Inverter Linhas (Espelho Horizontal):
      for(i=0..n) reverse(all(m[i]));

   -------------------------------------------------
   
   -> 90° HORÁRIO (Clockwise):
      1. Transpor
      2. Inverter Linhas
      
   -> 90° ANTI-HORÁRIO (Counter-Clockwise):
      1. Inverter Linhas
      2. Transpor
      
   -> 180°:
      1. reverse(all(m)); // Inverte ordem das linhas (vertical)
      2. Inverter Linhas (horizontal)
*/
