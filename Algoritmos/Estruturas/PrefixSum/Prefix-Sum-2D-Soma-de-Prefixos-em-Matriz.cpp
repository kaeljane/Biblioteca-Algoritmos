// =========================================================================================
// TÍTULO: SOMA DE PREFIXOS 2D (2D PREFIX SUM)
// PALAVRAS-CHAVE: Matriz, Subgrid, Retângulo, Inclusão-Exclusão, Range Query 2D.
// =========================================================================================

/*
   CASO DE USO CLÁSSICO:
   - O problema dá uma grade/matriz de tamanho N x M.
   - Pede a soma de todos os valores dentro do retângulo delimitado por 
     (linha1, coluna1) até (linha2, coluna2).
   
   O PULO DO GATO: A construção e a consulta usam o Princípio da Inclusão-Exclusão.
   Trabalhar com índices iniciando em 1 (Base-1) é OBRIGATÓRIO aqui para evitar 
   escrever dezenas de 'ifs' nas bordas superiores e esquerdas.
*/

#include <bits/stdc++.h>
#define ll long long
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
using namespace std;

void solve() {
    ll linhas, colunas, q;
    if (!(cin >> linhas >> colunas >> q)) return;

    // 1. Matriz original (Base-1)
    vector<vector<ll>> matriz(linhas + 1, vector<ll>(colunas + 1, 0));
    f (i, 1, linhas + 1) {
        f (j, 1, colunas + 1) {
            cin >> matriz[i][j];
        }
    }

    // 2. Construção da Matriz de Prefixos O(N * M)
    vector<vector<ll>> pref(linhas + 1, vector<ll>(colunas + 1, 0));
    f (i, 1, linhas + 1) {
        f (j, 1, colunas + 1) {
            // A soma do grandão = Cima + Esquerda - Intersecção Dupla + Célula Atual
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + matriz[i][j];
        }
    }

    // 3. Respondendo as Q consultas em tempo O(1)
    while (q--) {
        ll l1, c1, l2, c2;
        cin >> l1 >> c1 >> l2 >> c2; // (Linha 1, Coluna 1) até (Linha 2, Coluna 2)

        // ATENÇÃO: Se o problema der índices base-0, converta somando 1:
        // l1++; c1++; l2++; c2++;

        // A Mágica da Inclusão-Exclusão para Consulta:
        // Pegamos o retângulo total até o limite inferior direito (l2, c2)
        ll soma = pref[l2][c2];

        // Cortamos o retângulo que ficou para cima do nosso limite
        soma -= pref[l1 - 1][c2];

        // Cortamos o retângulo que ficou à esquerda do nosso limite
        soma -= pref[l2][c1 - 1];

        // Adicionamos de volta a intersecção (que foi subtraída duas vezes sem querer!)
        soma += pref[l1 - 1][c1 - 1];

        cout << soma << el;
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // ll t; cin >> t;
    // while(t--)
    solve();
    return 0;
}