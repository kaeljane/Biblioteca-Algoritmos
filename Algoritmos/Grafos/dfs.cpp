// =========================================================================================
// TÍTULO: DFS BÁSICA (BUSCA EM PROFUNDIDADE) - EXPLORAÇÃO E COMPONENTES CONEXOS
// PALAVRAS-CHAVE: DFS, Busca em Profundidade, componentes conexos, flood fill, árvores,
//                 caminho possível, labirinto, recursão, contar ilhas, conectividade.
// =========================================================================================

/*
   CASO DE USO CLÁSSICO:
   - Contar quantas "ilhas" ou grupos isolados existem no grafo.
   - Flood Fill: Pintar/marcar uma região conectada (tipo o "balde de tinta" do Paint).
   - Travessia em Árvores: Quase todo problema de árvore no Codeforces usa DFS para 
     calcular tamanho de subárvores, profundidade ou propriedades dos nós.
   - Checar conectividade: Verificar se existe *qualquer* caminho de A até B.
*/
#include <bits/stdc++.h>
#define ll long long
#define el '\n'
using namespace std;
// Estruturas globais dinâmicas (evita TLE/MLE e facilita a limpeza entre casos de teste)
vector<vector<ll>> adj;
vector<bool> vis;

// DFS Clássica: "Mergulha" o mais fundo possível antes de voltar (Backtracking)
void dfs(ll u) {
    vis[u] = true; // Marca o nó atual como visitado
    
    // --- Opcional: Processe o nó 'u' aqui ---
    // Ex: tamanho_do_bloco++; 
    // Ex: soma_valores += peso[u];

    // Olha para todos os vizinhos do nó atual
    for (ll v : adj[u]) {
        if (!vis[v]) {
            dfs(v); // Chama recursivamente para o vizinho não visitado
        }
    }
}

/* ================= EXEMPLO DE USO DENTRO DO SOLVE() ================= 

void solve() {
    ll n, m; 
    if (!(cin >> n >> m)) return;

    // Aloca a memória exata para o caso de teste atual (Assumindo 1-based)
    adj.assign(n + 1, vector<ll>());
    vis.assign(n + 1, false);

    for (ll i = 0; i < m; i++) {
        ll u, v; 
        cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u); // Remova esta linha se o grafo for DIRECIONADO
    }

    // --- Exemplo Prático: Contando Componentes Conexos ---
    ll componentes_conexos = 0;
    
    // Varre todos os vértices do grafo
    for (ll i = 1; i <= n; i++) {
        // Se achei um nó que ainda não foi visitado, descobri uma "ilha" nova!
        if (!vis[i]) {
            componentes_conexos++;
            dfs(i); // A DFS vai "pintar" (vis[x]=true) todos os nós dessa ilha
        }
    }

    if (componentes_conexos == 1) {
        cout << "O grafo inteiro e totalmente conectado!" << el;
    } 
    else {
        cout << "O grafo possui " << componentes_conexos << " ilhas isoladas." << el;
    }
}
======================================================================== */