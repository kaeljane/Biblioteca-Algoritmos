// =========================================================================================
// TÍTULO: 0-1 BFS (BUSCA EM LARGURA COM PESOS BINÁRIOS) - MENOR CAMINHO COM DEQUE
// PALAVRAS-CHAVE: 0-1 BFS, Dijkstra rápido, labirinto quebrar parede, inversão de aresta,
//                 peso zero ou um, contramão, mudar direção, deque, push_front, push_back,
//                 O(V+E), penalidade, custo binário.
// =========================================================================================
/*
    0-1 BFS
    Busca em largura
    Encontra o menor caminho de um ponto a outro.
    Parecido com o Dijkstra porem mais eficiente
    já que cada aresta só tem peso 0 ou 1.
    O(n)

    Vai usar sempre que bater o olho em um problema de "menor caminho" em que você
    tem uma ação de graça e uma ação que custa algo.

    Problemas clássicos:
        Labirinto com paredes Quebráveis ------------------------------------------
            Imagine um grid onde algumas células são corredores livres (ponto .) e 
            outras são paredes (cerquilhas #). O problema pede: "Qual o menor número
            de paredes que preciso quebrar para chegar no destino?"
                
                - Aresta peso 0: Andar de um espaço livre para outro espaço livre.
                - Aresta peso 1: Mover para uma parede (significa que você quebrou).
                
                O 0-1 BFS resolve isso num piscar de olhos. achando a rota que fura 
                o menor número de bloqueios
        
        Consertando o Trânsito (Inversão de Arestas) -------------------------------
            O juiz te dá um grafo de ruas de mão única (direcionado). Você quer ir da
            cidade A para a cidade B, mas takvez precise andar na contramão em algumas 
            ruas.

                - P/ cada aresta original u -> v, você add uma aresta de u para v com
                peso 0.
                - Você add uma aresta "falsa" na contramão v -> u com peso 1 (que 
                representa a penalidade por inverter a rua).

                O 0-1 BFS te diz exatamente quantas ruas você foi forçado a inverter.
        
        Pista de Gelo / Espelhos (Mudança de Direção) -------------------------------
            Você está num labirinto de gelo. Se você empurrar um bloco, ele desliza
            direto até bater numa parede. "Qual o menor número de vezes que preciso
            empurrar o bloco para ele chegar no alvo?"
                - Aresta peso 0: Continuar desligando na mesma direção que você já 
                estava indo.
                - Aresta peso 1: Mudar a sua direção (fazer ua curva de 90 graus.)

*/


// Para esse algoritmo, precisamos armazenar o vizinho e o peso da aresta
// adj[u] guarda pares no formato {vizinho, peso}
#include <bits/stdc++.h>
#define ll long long
#define el '\n'
using namespace std;

ll INF = 1e18 + 7;
vector<vector<pair<ll, ll>>> adj; 

// Retorna o vetor com a menor distância da origem para TODOS os outros vértices
vector<ll> bfs_01(ll origem, ll n) {
    // Inicializa as distâncias com Infinito
    vector<ll> dist(n + 1, INF); 
    dist[origem] = 0;

    // A MÁGICA ACONTECE AQUI: Fila de duas pontas (Double-Ended Queue)
    deque<ll> dq;
    dq.push_front(origem);

    while (!dq.empty()) {
        ll u = dq.front();
        dq.pop_front();

        for (auto aresta : adj[u]) {
            ll v = aresta.first;  // Vizinho
            ll w = aresta.second; // Peso (Garantido que será 0 ou 1)

            // Relaxamento da aresta
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                
                // Regra de Ouro do 0-1 BFS:
                if (w == 1) {
                    // Custo 1: Vai processar no futuro -> Fim da fila
                    dq.push_back(v);
                } else {
                    // Custo 0: Vai processar agora mesmo -> Início da fila
                    dq.push_front(v);
                }
            }
        }
    }

    return dist;
}

/* ================= EXEMPLO DE USO DENTRO DO SOLVE() ================= 

void solve() {
    ll n, m; // N vértices, M arestas
    if (!(cin >> n >> m)) return;

    // Inicializa o grafo global para N vértices (1-based)
    adj.assign(n + 1, vector<pair<ll, ll>>());

    for (ll i = 0; i < m; i++) {
        ll u, v, w; 
        cin >> u >> v >> w; // Lembre-se: 'w' será sempre 0 ou 1 na lógica do problema
        
        // Se for direcionado:
        adj[u].pb({v, w});
        
        // Se for não-direcionado, adicione a volta:
        // adj[v].pb({u, w});
    }

    ll origem = 1;
    ll destino = n;

    // Roda a 0-1 BFS
    vector<ll> dist = bfs_01(origem, n);

    // Checa se o destino foi alcançado
    if (dist[destino] == INF) {
        cout << "IMPOSSIVEL" << el;
    } else {
        cout << dist[destino] << el;
    }
}
======================================================================== */