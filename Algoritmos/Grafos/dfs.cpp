#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
DFS (Busca em Profundidade - Depth-First Search)
    Onde usar:
        - Componentes conexos: contar quantas "ilhas" isoladas existem no mapa.
        - Flood Fill: Pintar uma região de uma matriz (tipo a ferramenta "balde de tinta" do paint)
        - Checar Ciclos: Descobrir se dá para andar em círculas no grafo.
        - Árvores: quase todo problema de árvore no CodeForces sai com uma DFS simples.

*/

const int MAXN = 2e5 + 5; // Ajuste conforme o limite do problema
vector<int> adj[MAXN];    // Lista de adjacência
bool vis[MAXN];           // Vetor de visitados

// Chamada inicial na função solve(): dfs(1);
void dfs(int u) {
    vis[u] = true; // Marca o vértice atual como visitado
    
    // Visita todos os vizinhos
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v); // Vai o mais fundo possível nesse vizinho
        }
    }
}