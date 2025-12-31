#include <bits/stdc++.h>
using namespace std;

// --- INICIO DO SNIPPET PARA O TEMPLATE ---

// Função para zerar linhas e colunas se não houver um 0
// Complexidade: O(N*M) tempo, O(N+M) espeço

void makeZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) return;
    int m = matrix[0].size(); 

    // vetores auxiliares para "lembrar" onde tem zero
    vector<bool> zeroRow(n, false);
    vector<bool> zeroCol(m, false);

    // Passo 1: Varrer e marcar
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j]  == 0) {
                zeroRow[i] = true;
                zeroCol[j] = true;
            }
        }
    }

    // Passo 2: Preencer com zeros baseados nas marcas
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j) {
            if (zeroRow[i] || zeroCol[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}

// --- FIM DO SNIPPET ---

// Exemplo de uso dentro do seu formato de 'solve'
void solve() {
    vector<vector<int>> matrix = {
        {5, 4, 3, 9},
        {2, 0, 7, 6},
        {1, 3, 4, 0},
        {9, 8, 3, 4}
    };

    makeZeroes(matrix);

    // Imprimir para conferir
    cout << "{" << endl;
    for (int i = 0; i < matrix.size(); i++) {
        cout << "  {";
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << (j < matrix[i].size() - 1 ? ", " : "");
        }
        cout << "}" << (i < matrix.size() - 1 ? "," : "") << endl;
    }
    cout << "}" << endl;
}

int main() {
    solve();
    return 0;
}