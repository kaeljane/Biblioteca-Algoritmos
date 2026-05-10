// =========================================================================================
// TÍTULO: DIJKSTRA (MENOR CAMINHO DE ÚNICA ORIGEM)
// PALAVRAS-CHAVE: Dijkstra, SSSP, Menor Caminho, Grafos com pesos positivos, Min-Heap.
// =========================================================================================

/*
   CASO DE USO CLÁSSICO:
   - Encontrar a menor distância de UM nó de origem para TODOS os outros nós.
   - O grafo DEVE ter pesos maiores ou iguais a zero (Não funciona com pesos negativos).
   - Extremamente rápido. Complexidade: O(E * log V).
*/

#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll> // Usando ll para os dois lados garante zero overflow
#define pb push_back
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
#define ___ ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

const ll INF = 1e18 + 7;

// Estruturas dinâmicas para evitar lixo de memória entre casos de teste
vector<vector<ii>> adj;
vector<ll> dist;

void dijkstra(ll origem, ll n) {
    // Passo 1: Inicializa todas as distâncias como Infinito
    dist.assign(n + 1, INF);
    dist[origem] = 0;

    // Passo 2: Cria a Fila de Prioridade (Min-Heap)
    // A declaração fica super limpa usando a nossa macro 'ii'
    priority_queue<ii, vector<ii>, greater<ii>> pq;

    // Começamos pela origem com distância 0
    pq.push({0, origem});

    // Passo 3: Roda enquanto a fila não esvaziar
    while (!pq.empty()) {
        ll d = pq.top().first; // A distância acumulada para chegar nesse nó
        ll u = pq.top().second; // O nó atual
        pq.pop();

        // Otimização crucial: Ignorar distâncias antigas/piores que ficaram presas na fila
        if (d > dist[u]) continue;

        // Passo 4: Relaxamento dos vizinhos
        for (auto aresta : adj[u]) {
            ll v = aresta.first;
            ll peso = aresta.second;

            // Se o caminho passando por 'u' for mais curto, achamos um atalho!
            if (dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso; 
                pq.push({dist[v], v}); // Joga na fila com o novo recorde
            }
        }
    }
}

void solve() {
    ll n, m; 
    if (!(cin >> n >> m)) return;

    // Prepara a lista de adjacência limpa para o caso atual
    adj.assign(n + 1, vector<ii>());

    // Lendo o grafo com pesos
    f (i, 0, m) {
        ll u, v, peso;
        cin >> u >> v >> peso;
        
        // Se for um grafo bidirecional, adiciona ida e volta
        adj[u].pb({v, peso});
        adj[v].pb({u, peso});
    }

    // Roda o algoritmo a partir da origem desejada (ex: nó 1)
    dijkstra(1, n);

    // =========================================================================
    // Agora o vetor dist[i] guarda o menor caminho da origem até o nó 'i'
    // =========================================================================

    cout << "Menor custo a partir do no 1:" << el;
    f (i, 1, n + 1) {
        if (dist[i] == INF) {
            cout << "No " << i << ": Inalcancavel" << el;
        } else {
            cout << "No " << i << ": " << dist[i] << el;
        }
    }
}

signed main() {
    ___
    // ll t; cin >> t;
    // while (t--) 
    solve();
    return 0;
}