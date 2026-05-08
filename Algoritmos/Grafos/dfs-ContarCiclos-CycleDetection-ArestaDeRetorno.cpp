// =========================================================================================
// TÍTULO: DETECÇÃO E CONTAGEM DE CICLOS (BACK-EDGES) EM GRAFOS NÃO-DIRECIONADOS (DFS)
// PALAVRAS-CHAVE: Cycle detection, contar ciclos, aresta de retorno, back edge, 
//                 grafo não-direcionado, pseudo-árvore, parent, w != parent.
// =========================================================================================

/*
    CASOS DE USO CLÁSSICOS:
    - Contar quantos "loops" independentes existem em um grafo não-direcionado.
    - Verificar se um grafo é uma ÁRVORE válida (componentes == 1 e ciclos == 0).
    - Problemas onde V == E (Pseudo-árvores), garantindo que cada componente tem exatos 1 ciclo.
   
    CUIDADO:
        - Esse algoritmo conta "Arestas de Retorno". Em grafos muito densos (ex: um triângulo com 
        uma linha no meio), ele não vai te dar todas as permutações possíveis de ciclos, mas sim 
        o número de arestas que precisam ser removidas para o grafo virar uma árvore.

    1. Verificador de Árvore (É árvore ou não?)
        IF (total_ciclos == 0) então é
        
        "quantas arestas precisam ser removidas para virar uma árvore?"
    
    2. Grafos do Tipo "Pseudo-Árvore"
        Um padrão absurdamente comum no AtCoder e CodeForces são problemas onde N cidades têm 
        exatamente N estradas. Pela matemática dos grafos, se V = E, é garantido que existe 
        exatamente 1 ciclo em cada componente conexo. Você usa essa DFS para localizar rapidamente
        quantas arestas fazem parte do cilo para depois processá-las.

    3. Encontrando a "Aresta Culpada" (O ciclo Ímpar)
        Ás vezes o problema mistura Bipartido com Ciclos. Se um grafo não é bipartido, é porquer
        existe um ciclo ímpar. Essa DFS te ajuda não apenas a contar o ciclo, mas você pode 
        modificá-la facilmente (usando um vetor que anota a profundidade atual) para imprimir o 
        tamanho exato do ciclo e achar quem estragou a festa!
        
    

*/
#include <bits/stdc++.h>
#define ll long long
#define el '\n'
using namespace std;

vector<vector<ll>> adj;
vector<bool> vis;
ll qtd_arestas_retorno = 0;

// DFS que carrega o 'pai' para não dar meia-volta
void dfs_ciclo(ll u, ll pai) {
    vis[u] = true;

    for (ll vizinho : adj[u]) {
        if (!vis[vizinho]) {
            // Se não foi visitado, avança na árvore da DFS
            // O nó 'u' atual se torna o 'pai' do 'vizinho'
            dfs_ciclo(vizinho, u);
        } 
        // Se já foi visitado E NÃO é o nó de onde acabamos de vir
        else if (vizinho != pai) {
            // Achamos um ciclo fechando!
            qtd_arestas_retorno++;
        }
    }
}

/* ================= EXEMPLO DE USO DENTRO DO SOLVE() ================= 

void solve() {
    ll n, m;
    if (!(cin >> n >> m)) return;

    adj.assign(n + 1, vector<ll>());
    vis.assign(n + 1, false);
    qtd_arestas_retorno = 0; // Zera a variável global

    for (ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Como o grafo pode ser desconexo, precisamos de um for para 
    // rodar a DFS em todos os componentes
    for (ll i = 1; i <= n; i++) {
        if (!vis[i]) {
            // Passamos -1 como 'pai' inicial, pois a raiz não tem pai
            dfs_ciclo(i, -1); 
        }
    }
    
    // Como é não-direcionado, cada aresta de retorno foi contada por ambas as pontas
    ll total_ciclos = qtd_arestas_retorno / 2;
    
    cout << "O grafo tem " << total_ciclos << " aresta(s) fechando ciclo(s)." << el;
}
======================================================================== */