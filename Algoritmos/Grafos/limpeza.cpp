#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
Como limpar a sujeira para o próximo caso de teste (t--)
Como no Codeforces os problemas têm múltiplos casos de teste (while(t--)), o maior erro de quem começa a usar grafos é esquecer de limpar as variáveis globais. Sempre coloque isso no início da sua função solve():

*/
void solve() {
    int n, m;
    cin >> n >> m;
    
    // LIMPEZA OBRIGATÓRIA PARA MÚLTIPLOS TESTES
    for(int i = 0; i <= n; i++) {
        adj[i].clear();
        vis[i] = false;
        dist[i] = 0;
    }
    
    // Leitura das arestas...
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Remova se for grafo direcionado
    }
    
    // Chama dfs() ou bfs() aqui...
}