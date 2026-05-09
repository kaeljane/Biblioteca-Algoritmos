// =========================================================================================
// TÍTULO: BACKTRACKING EM GRAFOS - BUSCA POR CICLO HAMILTONIANO
// PALAVRAS-CHAVE: Ciclo Hamiltoniano, Grafo Complemento, Backtracking, Força Bruta, 
//                 Amigo Secreto, Borracha Mágica, Caminho Perfeito, N pequeno (N <= 15).
// =========================================================================================

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define el '\n'
using namespace std;

// Tudo dinâmico e seguro usando vectors!
vector<vector<bool>> conhece;
vector<vector<ll>> adj;
vector<bool> vis;
ll n, m;

// DFS que retorna 'true' se achar o ciclo perfeito, e 'false' se der errado
bool dfs_hamiltoniano(ll atual, ll visitados, ll origem) {
    
    // 1. CONDIÇÃO DE PARADA (A fila andou por todo mundo?)
    if (visitados == n) {
        // O último da fila consegue jogar o presente para a primeira pessoa (origem)?
        // Se eles NÃO se conhecem, a roda fechou com sucesso!
        if (!conhece[atual][origem]) {
            return true; 
        }
        return false; // Quase deu, mas o último conhecia o primeiro. Beco sem saída.
    }

    // 2. PINTANDO O CHÃO
    vis[atual] = true;

    // 3. TENTANDO OS VIZINHOS (Apenas pessoas que eu NÃO conheço)
    for (ll vizinho : adj[atual]) {
        if (!vis[vizinho]) {
            // Se afunda na recursão. Se o vizinho conseguir fechar a festa lá na frente, propaga o 'true'
            if (dfs_hamiltoniano(vizinho, visitados + 1, origem)) {
                return true; 
            }
        }
    }

    // 4. A BORRACHA MÁGICA (Backtracking)
    // Se o código chegou aqui, testamos todos os vizinhos e nenhum formou a roda final.
    // Apagamos a nossa "pegada" para que essa pessoa possa ser tentada em outra ordem.
    vis[atual] = false;

    return false; // Retorna falso para avisar o nó anterior que esse caminho deu ruim
}

void solve() {
    if (!(cin >> n >> m)) return;

    // Alocação dinâmica para o caso de teste atual (1-based)
    conhece.assign(n + 1, vector<bool>(n + 1, false));
    adj.assign(n + 1, vector<ll>());
    vis.assign(n + 1, false);

    // Lendo as amizades originais
    for (ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        conhece[u][v] = true;
        conhece[v][u] = true; // Relação de ida e volta!
    }

    // CONSTRUINDO O GRAFO COMPLEMENTO (Arestas de pessoas que NÃO se conhecem)
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            if (i != j && !conhece[i][j]) {
                adj[i].pb(j);
            }
        }
    }

    // Inicia a tentativa a partir da Pessoa 1
    // (atual = 1, visitados = 1, origem = 1)
    if (dfs_hamiltoniano(1, 1, 1)) {
        cout << "S" << el;
    } else {
        cout << "N" << el;
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}