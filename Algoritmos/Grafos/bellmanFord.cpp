// Bellman-Ford
//
// Encontra o menor caminho de um ponto a outro de um grafo
// que pode conter arestas negativas.
// Lida com o que o Dijkstra não consegue lidar!!


// --------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18 + 7;

// Estrutura limpa, igual a do Kruskal
struct Aresta {
    int u, v;
    long long peso;
};

void solve() {
    int n, m; // n = vértices, m = arestas
    if (!(cin >> n >> m)) return;

    vector<Aresta> arestas(m);
    for (int i = 0; i < m; i++) {
        cin >> arestas[i].u >> arestas[i].v >> arestas[i].peso;
        // Importante: O Bellman-Ford normalmente lida com arestas DIRECIONADAS.
        // Se a questão for não-direcionada, você deve adicionar a ida e a volta 
        // no vetor separadamente.
        // Nesse caso declare o vetor vazio de arestas e jogue as arestas dentro dele da seguinte forma arestas.push_back({u, v, w}); e arestas.push_back({v, u, w}); 

    }

    int origem = 1; // Vamos calcular do nó 1 para todos os outros
    vector<long long> dist(n + 1, INF); // 1-based
    dist[origem] = 0;

    // Passo 1 e 2: Relaxar todas as arestas N - 1 vezes
    // Relaxar -> Perguntar "chegando em v passando por u é mais barato do que o que eu já sei?"
    for (int i = 1; i <= n - 1; i++) { // n-1 por causa da qt de vertice...
        // Para otimizar, podemos checar se houve alguma mudança nesta rodada.
        // Se não houve, podemos parar o loop mais cedo (early exit).
        bool mudou = false;
        
        for (Aresta a : arestas) {
            // Só tentamos relaxar se já alcançamos o nó 'u'
            if (dist[a.u] != INF && dist[a.u] + a.peso < dist[a.v]) {
                dist[a.v] = dist[a.u] + a.peso;
                mudou = true;
            }
        }
        
        // Se rodou todas as arestas e nada mudou, o algoritmo já terminou!
        if (!mudou) break; 
    }

    // Passo 3: Checar por ciclos negativos rodando mais uma vez
    bool tem_ciclo_negativo = false;
    for (Aresta a : arestas) {
        /*
        Se após n-1 rodadas ainda existe alguma aresta que consegue melhorar
        uma distância, significa que há um ciclo negativo - pq num grafo normal
        isso seria impossível.
        */

        // Detecção de ciclo - faz isso só UMA vez
        if (dist[a.u] != INF && dist[a.u] + a.peso < dist[a.v]) {
            tem_ciclo_negativo = true;
            break; // Já achou o ciclo, pode parar
        }
    }

    if (tem_ciclo_negativo) {
        cout << "O grafo contem um ciclo de peso negativo!" << '\n';
    } 
    else {
        cout << "Menores distancias a partir do no " << origem << ":\n";
        for (int i = 1; i <= n; i++) { 
            if (dist[i] == INF) {
                cout << "No " << i << ": Inalcancavel\n";
            } 
            else {
                cout << "No " << i << ": " << dist[i] << '\n';
                
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}

