// =========================================================================================
// TÍTULO: BFS COM RECONSTRUÇÃO DE CAMINHO (SHORTEST PATH RECONSTRUCTION)
// PALAVRAS-CHAVE: BFS, imprimir caminho exato, shortest path, parent array, vetor pai,
//                 trilha de migalhas, Message Route, recuperar rota, backtracking BFS.
// =========================================================================================

/*
   CASO DE USO CLÁSSICO:
        - Quando a questão pede o MENOR CAMINHO e exige que você IMPRIMA OS NÓS DA ROTA.
        - O array 'pai' (parent) anota "de onde eu vim" para reconstruir os passos no final.
        - Ideal para grafos sem peso. Se o grafo tiver peso, essa lógica do vetor 'pai' 
        deve ser colocada dentro do Dijkstra!
    
    EXEMPLOS DE PROBLEMA:
        1. Rota de Mensagens (CSES - Message Route)
            Você tem uma rede de computadores e quer enviar um pacote do computador 1 para 
            o computador N. O juiz pede: "Imprima o menor número de conexões e, na linha 
            seguinte, a sequência exata de computadores por onde o pacote passou".
            
            Como resolver: Roda exatamente esse código. O vetor ans terá exatamente o 
            caminho.

        2. Labirinto com Movimentos (Grid Pathing)
            Em vez de grafos normais, você está num grid e precisa achar a saída do labirinto. 
            Mas o juiz exige que você imprima os comandos diretos: "UURRDDL".
            
            Como adaptar: Em vez de fazer o vetor pai guardar o ID do nó, você faz um vetor 
            char direcao[MAX] ou usa pair. Quando você for para o vizinho de cima, você 
            anota direcao[vizinho] 'U'. No final, a reconstruçãodo caminho vai te dar a string 
            exata dos movimentos!

        3. Escada de Palavras (Word Ladder)
            Você tem a palavra "HIT" e quer transformar em "COG", mudando uma letra por vez,
            usando palavras do dicionário (Ex.: HIT -> HOT -> DOT -> DOG -> COG). O problema
            pede para imprimir as palavras intermediárias.

            Como resolver: Cada palavra é um nó. Palavras com uma letra de diferente têm uma
            aresta entre elas. A BFS acha a menor transformação e o vetor pai reconstrói a 
            escada exata de palavras.

*/
#include <bits/stdc++.h>
#define ll long long
#define el '\n'
using namespace std;

// Estruturas dinâmicas
vector<vector<ll>> adj;
vector<bool> vis;
vector<ll> dist;
vector<ll> pai; // A "trilha de migalhas"

// BFS Clássica + Registro de Pais
void bfs_path(ll origem) {
    queue<ll> q;
    
    q.push(origem);
    vis[origem] = true;
    dist[origem] = 0;
    
    // O pai da origem é ela mesma (condição de parada)
    pai[origem] = origem; 

    while (!q.empty()) {
        ll u = q.front();
        q.pop();

        for (ll v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                dist[v] = dist[u] + 1;
                
                // O PULO DO GATO: Anota que chegamos em 'v' vindo de 'u'
                pai[v] = u; 
                
                q.push(v);
            }
        }
    }
}

// Função para recuperar a rota da origem até o 'destino'
vector<ll> recupera_caminho(ll destino) {
    vector<ll> caminho;
    
    // Se não foi visitado, é impossível chegar lá
    if (!vis[destino]) return caminho; 

    ll atual = destino;
    caminho.push_back(atual);
    
    // Volta no tempo até achar a origem (onde pai[x] == x)
    while (pai[atual] != atual) { 
        atual = pai[atual];
        caminho.push_back(atual);
    }

    // A trilha foi montada de trás pra frente, então precisamos inverter!
    reverse(caminho.begin(), caminho.end()); // ou rev(caminho) usando sua macro
    
    return caminho;
}

/* ================= EXEMPLO DE USO DENTRO DO SOLVE() ================= 

void solve() {
    ll n, m; 
    if (!(cin >> n >> m)) return;

    // Prepara os vetores para o caso de teste atual
    adj.assign(n + 1, vector<ll>());
    vis.assign(n + 1, false);
    dist.assign(n + 1, -1);
    pai.assign(n + 1, -1); 

    for (ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll origem = 1;
    ll destino = n;

    bfs_path(origem);
    
    vector<ll> rota_exata = recupera_caminho(destino);

    if (rota_exata.empty()) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << rota_exata.size() << "\n"; // Quantidade de nós no caminho
        
        // Imprime o caminho na ordem correta
        for (ll no : rota_exata) {
            cout << no << " ";
        }
        cout << "\n";
    }
}
======================================================================== */