// =========================================================================================
// TÍTULO: FLOYD-WARSHALL (MENOR CAMINHO DE TODOS PARA TODOS / APSP)
// PALAVRAS-CHAVE: Floyd-Warshall, All-Pairs Shortest Path, N pequeno (N <= 400), 
//                 matriz de adjacência, grafos densos, arestas múltiplas, Dr. Wise.
// =========================================================================================

/*
   CASO DE USO CLÁSSICO:
   - Quando você precisa saber a menor distância de QUALQUER nó para QUALQUER outro nó.
   - O número de vértices (N) tem que ser pequeno (geralmente N <= 400), pois roda em O(N^3).
   - Resolve grafos com pesos negativos (ao contrário do Dijkstra), mas não com ciclos negativos.
   - O PULO DO GATO: O loop da escala 'k' OBRIGATORIAMENTE fica do lado de fora!
*/

#include <bits/stdc++.h>
#define ll long long
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
#define ___ ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

const ll INF = 1e18 + 7;

void solve() {
    ll n, m; // n = cidades, m = estradas
    if (!(cin >> n >> m)) return;

    // Criamos a Matriz de distâncias N x N, inicializada com Infinito
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));

    // A distância de uma cidade para ela mesma é sempre 0
    f (i, 1, n + 1) {
        dist[i][i] = 0;
    }

    // Lendo a entrada e preenchendo a matriz inicial
    f (i, 0, m) {
        ll u, v, peso;
        cin >> u >> v >> peso;
        
        // Se for um grafo bidirecional, atualizamos os dois lados.
        // O min() protege contra arestas múltiplas, guardando só a mais barata
        dist[u][v] = min(dist[u][v], peso);
        dist[v][u] = min(dist[v][u], peso); 
    }

    // O Algoritmo de Floyd-Warshall (A mágica de 3 linhas)
    // ATENÇÃO: O loop do 'k' (o nó intermediário/escala) TEM que ser o loop mais externo!
    f (k, 1, n + 1) {
        f (i, 1, n + 1) {
            f (j, 1, n + 1) {
                
                // Só tentamos melhorar o caminho se for possível chegar na escala 'k'
                // Isso evita overflow de somar INF + INF
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
                
            }
        }
    }

    // =========================================================================
    // Agora dist[i][j] tem a menor distância possível entre QUALQUER par de nós
    // =========================================================================

    ll consultas;
    cin >> consultas;
    while (consultas--) {
        ll origem, destino;
        cin >> origem >> destino;
        
        if (dist[origem][destino] == INF) {
            cout << "Impossivel chegar" << el;
        } else {
            cout << "Menor distancia: " << dist[origem][destino] << el;
        }
    }
}

signed main() {
    ___
    solve();
    return 0;
}