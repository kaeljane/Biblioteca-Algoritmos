#include <bits/stdc++.h>
using namespace std;

// Função auxiliar para ordenar cada LINHA individualmente
void sortRows(vector<vector<int>>& v) {
    for (auto& row : v) {
        sort(row.begin(), row.end());
    }
}

// Função auxiliar para ordenar cada COLUNA individualmente
void sortCols(vector<vector<int>>& v) {
    if (v.empty()) return;
    int rows = v.size();
    int cols = v[0].size();
    
    for (int j = 0; j < cols; j++) {
        vector<int> col;
        // Extrai a coluna
        for (int i = 0; i < rows; i++) {
            col.push_back(v[i][j]);
        }
        // Ordena
        sort(col.begin(), col.end());
        // Devolve para a matriz
        for (int i = 0; i < rows; i++) {
            v[i][j] = col[i];
        }
    }
}

// Função recursiva principal
vector<vector<int>> mergeSort(int m, int n, vector<vector<int>> v) {
    // Caso Base: 1x1 ou vazio
    if (m <= 1 && n <= 1) return v;

    // Pontos de divisão (metade arredondada para cima para ímpares)
    int r_mid = (m + 1) / 2;
    int c_mid = (n + 1) / 2;

    // Se tivermos linhas suficientes para dividir, dividimos em Topo e Fundo
    // Se não, tratamos como uma única faixa
    vector<vector<int>> top, bot;
    
    // Divide as linhas
    if (m > 1) {
        for (int i = 0; i < r_mid; i++) top.push_back(v[i]);
        for (int i = r_mid; i < m; i++) bot.push_back(v[i]);
    } else {
        top = v; // Apenas 1 linha, tudo vai pro "top"
    }

    // Agora, para cada metade (Top e Bot), dividimos as colunas (Esq e Dir)
    auto splitAndSolve = [&](vector<vector<int>>& subMat) -> vector<vector<int>> {
        if (subMat.empty()) return {};
        int rows = subMat.size();
        int cols = subMat[0].size();
        
        if (cols <= 1) {
            // Se só tem 1 coluna, não divide colunas, mas pode ter vindo de uma divisão de linhas
            // Precisamos recursar se a dimensão original (rows) foi dividida?
            // Na verdade, a recursão completa cuida disso.
            // Se chegamos aqui e rows > 1, já foi dividido antes.
            // O caso base (1x1) já foi tratado no inicio da função principal,
            // mas aqui estamos tratando submatrizes.
            // Vamos chamar mergeSort recursivamente para garantir.
            return mergeSort(rows, cols, subMat);
        }

        vector<vector<int>> left, right;
        for (int i = 0; i < rows; i++) {
            vector<int> l_row, r_row;
            for (int j = 0; j < c_mid; j++) l_row.push_back(subMat[i][j]);
            for (int j = c_mid; j < cols; j++) r_row.push_back(subMat[i][j]);
            left.push_back(l_row);
            right.push_back(r_row);
        }

        // Recursão nos quadrantes
        left = mergeSort(left.size(), left[0].size(), left);
        right = mergeSort(right.size(), right[0].size(), right);

        // MERGE HORIZONTAL (Junta Esq + Dir)
        // 1. Concatena
        vector<vector<int>> result = left;
        for (int i = 0; i < rows; i++) {
            result[i].insert(result[i].end(), right[i].begin(), right[i].end());
        }
        // 2. Ordena Linhas, depois Colunas (conforme o enunciado)
        sortRows(result);
        sortCols(result);
        return result;
    };

    // Se m=1, só precisamos dividir colunas. Se m>1, dividimos linhas e depois colunas.
    // Para simplificar, usamos a lógica:
    // Se m > 1: Temos Top e Bot. Processamos recursivamente.
    // Se m = 1: Top é a própria matriz. Processamos recursivamente (vai dividir colunas).
    
    if (m > 1) {
        top = splitAndSolve(top);
        bot = splitAndSolve(bot);
        
        // MERGE VERTICAL (Junta Topo + Fundo)
        vector<vector<int>> finalRes = top;
        finalRes.insert(finalRes.end(), bot.begin(), bot.end());
        
        sortRows(finalRes);
        sortCols(finalRes);
        return finalRes;
    } else {
        // Apenas 1 linha, mas colunas > 1
        return splitAndSolve(v);
    }
}