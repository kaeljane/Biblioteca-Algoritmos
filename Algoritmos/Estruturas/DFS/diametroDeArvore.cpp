#include <bits/stdc++.h>
using namespace std;

// Definições para facilitar (baseado no seu template)
#define pb push_back
#define vi vector<int>
#define all(v) (v).begin(), (v).end()

// Variáveis globais para a DFS
const int MAXN = 200005; // Tamanho seguro para N
vi adj[MAXN];
int max_dist = -1;
int farthest_node = -1;

// Função DFS para achar o nó mais distante
void dfs(int u, int p, int d) {
    // Se a distância atual for maior que a máxima vista, atualiza
    if (d > max_dist) {
        max_dist = d;
        farthest_node = u;
    }
    
    for (int v : adj[u]) {
        if (v != p) { // Evita voltar para o pai
            dfs(v, u, d + 1);
        }
    }
}

void solve() {
    int n;
    if (!(cin >> n)) return; // Leitura segura do N

    // Limpar a lista de adjacência para cada caso de teste (se houver múltiplos)
    for(int i = 0; i <= n; i++) adj[i].clear();

    // Ler as n-1 arestas
    // Nota: Os exemplos mostram rótulos de 0 a N-1 ou 1 a N. 
    // O código funciona para ambos, pois usa lista de adjacência.
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    // --- Passo 1: Primeira DFS ---
    // Começamos arbitrariamente do nó 0 (ou o primeiro nó válido da entrada)
    // Se os nós forem 1-indexados, pode começar do 1. 
    // Como o grafo é conexo, qualquer nó serve. Vamos tentar o 0.
    // Resetando variáveis
    max_dist = -1;
    dfs(0, -1, 0); // Busca o nó mais longe do 0

    int ponta_A = farthest_node; // Esse é o nó "A" da explicação

    // --- Passo 2: Segunda DFS ---
    // Agora começamos do nó A para achar a outra ponta do diâmetro
    max_dist = -1;
    dfs(ponta_A, -1, 0);

    // O max_dist agora contém o diâmetro
    cout << max_dist << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}



#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define all(v) (v).begin(), (v).end()

const int MAXN = 200005; 
vi adj[MAXN];
int max_dist = -1;
int farthest_node = -1;

void dfs(int u, int p, int d) {
    if (d > max_dist) {
        max_dist = d;
        farthest_node = u;
    }
    
    for (int v : adj[u]) {
        if (v != p) { 
            dfs(v, u, d + 1);
        }
    }
}

void solve() {
    int n;
    cin >> n; 

    for(int i = 0; i <= n; i++) adj[i].clear();

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    max_dist = -1;
    dfs(0, -1, 0); 

    int ponta_A = farthest_node; 

    max_dist = -1;
    dfs(ponta_A, -1, 0);

    cout << max_dist << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}