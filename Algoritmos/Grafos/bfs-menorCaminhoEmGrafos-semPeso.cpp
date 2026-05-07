/*
=========================================================================================
TÍTULO: BUSCA EM LARGURA CLÁSSICA (BFS) - MENOR CAMINHO EM GRAFOS SEM PESO
PALAVRAS-CHAVE: BFS, Busca em Largura, fila, queue, menor caminho, shortest path, 
                grafos não ponderados, propagação em ondas, camadas, graus de separação,
                labirinto simples, número mínimo de passos, distância mínima.
=========================================================================================

    CASOS DE USO CLÁSSICO:
        - Encontrar o CAMINHO MAIS CURTO (menor número de arestas/passo) entre dois pontos.
        - Só funciona se o grafo NÃO tiver pesos nas arestas (ou se todas as arestas 
        custarem 1).
        - Se a questão falar de "distância mínima", "menor número de movimentos" ou "grau
        de separação" e não houver custo diferente entre as ações, a resposta é BFS!

    EXEMPLO DE PROBLEMAS:
        1. Menor caminho entre dois nós
            Dado um grafo não-direcionado com N vértices e M arestas, encontre o menor numero
            de arestas para ir do vértice 1 ao vértice N. Se não for possível, imprima -1.

        2. Labirinto (grid)
            Dado um labirinto NxM onde ' . ' é caminho livre e # é parede, encontre o menor
            número de passos para ir da posição (0, 0) até (N-1, M-1). Pq BFS? Cada passo
            custa 1, quer o mínima de passos.
        3. Grau de separação / rede social
            Em uma rede com N pessoas e M amizades, qual o menor número de intermediários
            para conectar a pessoa 1 à pessoa M? Diff imprimir (dist[n] - 1) pq ele quer só
            intermediários
        4. Componentes Conexos
            Dado um grafo com N vértices e M arestas, quantos grupos isolados de vértices
            existem? Cada BFS visita todos os nós de um componente. Conta quantas vezes você 
            precisa iniciar uma BFS nova

*/


#include <bits/stdc++.h>
#define ll long long
#define el '\n'
using namespace std;

const int MAXN = 100005;

// No seu código competitivo, a lista de adjacência costuma ficar global
vector<vector<ll>> adj(MAXN);
vector<bool> vis(MAXN);
vector<ll> dist(MAXN); // Guarda o menor número de arestas desde a origem

void bfs(int origem) {
    queue<int> fila;
    
    // Passo 1: Inicia pela origem
    vis[origem] = true;
    dist[origem] = 0;
    fila.push(origem);

    // Passo 2: Processa a fila até esvaziar
    while (!fila.empty()) {
        int atual = fila.front(); // Olha o primeiro da fila
        fila.pop();               // Tira ele da fila

        // Olha todos os vizinhos do nó atual
        for (int vizinho : adj[atual]) {
            if (!vis[vizinho]) {
               // Se não foi vis, descobrimos o menor caminho para ele! 
                vis[vizinho] = true;
                dist[vizinho] = dist[atual] + 1; // A distância é a do pai + 1
                
                fila.push(vizinho); // Coloca o vizinho no final da fila para processar os amigos dele depois
            }
        }
    }
}
/*
EXEMPLO DE USO DO SOLVE()

void solve() {
    int n, m; // n vértices, m arestas
    if (!(cin >> n >> m)) return;

    // Lendo as arestas (assumindo grafo não-direcionado)
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // para nao-direcionado (vai para os dois lados)
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Limpa os arrays de controle antes de rodar (boa prática)
    for(int i = 1; i <= n; i++){
        vis[i] = false;
        dist[i] = -1; // -1 indica inalcançável
    }

    // Inicia a BFS a partir do vértice 1
    bfs(1);

    // Mostra as distâncias
    cout << "dists a partir do no 1:\n";
    for (int i = 1; i <= n; i++) {
        cout << "No " << i << ": " << dist[i] << " passos\n";
    }
}
 
2. LABIRINTO -----------------------------------------------------------------------------

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto& row : grid) cin >> row;

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int,int>> q;
    q.push({0, 0});
    dist[0][0] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m 
                && grid[nx][ny] == '.' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    cout << dist[n-1][m-1] << el;
}



*/
