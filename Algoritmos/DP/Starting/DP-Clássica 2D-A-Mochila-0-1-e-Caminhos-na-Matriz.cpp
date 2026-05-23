// =========================================================================================
// TÍTULO: PROGRAMAÇÃO DINÂMICA 2D (BOTTOM-UP / TABELA)
// PALAVRAS-CHAVE: Grid, Matriz, Caminho Mínimo, Mochila Clássica 2D.
// =========================================================================================

/*
   CASOS DE USO CLÁSSICOS:
   - "Qual o caminho de menor custo do canto superior esquerdo até o inferior direito?"
   - "Dada uma matriz, de quantas formas posso chegar ao fim andando só para direita e baixo?"
   - Mochila 0/1 completa (quando o problema exige que você saiba QUAIS itens foram pegos).
   
   O PULO DO GATO: Preenchemos a matriz linha por linha. O valor de dp[i][j] é sempre 
   calculado a partir dos vizinhos que já foram processados (cima e esquerda).
   - Complexidade: O(N * M) para tempo e memória.
*/

#include <bits/stdc++.h>
#define ll long long
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
using namespace std;

const ll INF = 1e18 + 7;

void solve() {
    // =========================================================================
    // CASO 1: CAMINHO MÍNIMO NA MATRIZ (Grid Paths)
    // Problema: Ir de (0,0) até (N-1, M-1) somando o menor custo possível.
    // Movimentos permitidos: Apenas para a Direita e para Baixo.
    // =========================================================================
    ll linhas, colunas;
    if (cin >> linhas >> colunas) {
        vector<vector<ll>> grid(linhas, vector<ll>(colunas));
        f(i, 0, linhas) {
            f(j, 0, colunas) {
                cin >> grid[i][j];
            }
        }

        // Tabela de DP para guardar o custo mínimo até a célula (i, j)
        vector<vector<ll>> dp_grid(linhas, vector<ll>(colunas, 0));

        // Ponto de partida
        dp_grid[0][0] = grid[0][0];

        // Preenche a primeira coluna (só posso chegar aqui vindo de cima)
        f(i, 1, linhas) {
            dp_grid[i][0] = dp_grid[i-1][0] + grid[i][0];
        }

        // Preenche a primeira linha (só posso chegar aqui vindo da esquerda)
        f(j, 1, colunas) {
            dp_grid[0][j] = dp_grid[0][j-1] + grid[0][j];
        }

        // Preenche o miolo da matriz
        f(i, 1, linhas) {
            f(j, 1, colunas) {
                // O custo para chegar em (i,j) é o custo da própria célula 
                // MAIS o menor custo entre vir de cima ou vir da esquerda
                dp_grid[i][j] = grid[i][j] + min(dp_grid[i-1][j], dp_grid[i][j-1]);
            }
        }

        cout << "1. Custo minimo do caminho: " << dp_grid[linhas-1][colunas-1] << el;
    }

    // =========================================================================
    // CASO 2: MOCHILA 0/1 - ABORDAGEM 2D CLÁSSICA
    // Diferente da versão 1D, essa versão 2D é obrigatória quando o problema 
    // pede para você IMPRIMIR QUAIS ITENS foram selecionados no final.
    // =========================================================================
    ll n_itens, capacidade;
    if (cin >> n_itens >> capacidade) {
        vector<ll> pesos(n_itens + 1), valores(n_itens + 1);
        
        // Lemos os itens usando base-1 para facilitar a DP
        f(i, 1, n_itens + 1) {
            cin >> pesos[i] >> valores[i];
        }

        // dp[i][w] = Valor máximo considerando os primeiros 'i' itens, pesando até 'w'
        vector<vector<ll>> dp_mochila(n_itens + 1, vector<ll>(capacidade + 1, 0));

        f(i, 1, n_itens + 1) {
            f(w, 0, capacidade + 1) {
                // Caso 1: O item atual é pesado demais, não cabe.
                // A melhor escolha é simplesmente não pegar e herdar o estado anterior.
                if (pesos[i] > w) {
                    dp_mochila[i][w] = dp_mochila[i-1][w];
                } 
                // Caso 2: O item cabe. Decidimos se vale mais a pena PEGAR ou NÃO PEGAR.
                else {
                    ll nao_pegar = dp_mochila[i-1][w];
                    ll pegar = dp_mochila[i-1][w - pesos[i]] + valores[i];
                    dp_mochila[i][w] = max(nao_pegar, pegar);
                }
            }
        }

        cout << "2. Valor maximo na mochila (2D): " << dp_mochila[n_itens][capacidade] << el;

        // ---------------------------------------------------------------------
        // BÔNUS: RECUPERAÇÃO DE CAMINHO (Backtracking na Tabela DP)
        // Isso é o que torna a DP 2D superior à 1D em alguns problemas!
        // ---------------------------------------------------------------------
        vector<ll> itens_escolhidos;
        ll w_atual = capacidade;
        
        for (ll i = n_itens; i > 0 && dp_mochila[i][w_atual] > 0; i--) {
            // Se o valor na linha de baixo é diferente do valor na linha de cima,
            // significa que o item 'i' FOI SELECIONADO para causar essa mudança.
            if (dp_mochila[i][w_atual] != dp_mochila[i-1][w_atual]) {
                itens_escolhidos.push_back(i);
                w_atual -= pesos[i]; // Deduz o peso do item da nossa capacidade
            }
        }
        
        reverse(itens_escolhidos.begin(), itens_escolhidos.end());
        
        cout << "Itens selecionados (Indices base-1): ";
        for (ll item : itens_escolhidos) cout << item << " ";
        cout << el;
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}