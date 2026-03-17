// Dijkstra
//
// Encontra o menor caminho do vértice de index s até os outros vértices
//
// O(n log(n))

const int INF = 0x3f3f3f3f;
vector<vector<pair<ll, ll>>> adj; // {to, weight} É o seu mapa. Ele diz: "A partir da cidade X, eu posso ir para a cidade Y, e essa rua tem peso Z".

int dijkstra(ll n, ll s) {
    vector<int> dist(n, INF); // ele anota a menor distancia descoberta até agora para chegar em cada cidade

    // origem
    dist[s] = 0; // a distancia da sua cidade de origem (s) para ela mesmo é igual a zero.

    using pi = pair<ll,ll>;
    priority_queue<pi, vector<pi>, greater<pi>> q; // garante que o elemento com o menor peso (distancia) sempre pule para a frente da fila.
    q.emplace(0,s); // vc entra na fila. Seu peso acumulado é 0, e você está na cidade s.
    
    while (!q.empty()) { // enquanto houver "cidades" para explorar
        auto [w,u] = q.top(); // você pega o primeiro da fila (w: dist acumulada até agora, u: cidade atual)
        q.pop();

        if (u == n-1) break; // se ja chegamos no destino final podemos parar
        if (w != dist[u]) continue; // otimizacao: as vezes a mesma cidade entra na fila varias vezes com distancias diferentes

        for (auto [W,v] : adj[u]) { // coracao do Dijkstra
            if (w+W < dist[v]) {
                dist[v] = w+W;
                q.emplace(w+W,v);
            }
        }
    }

    return dist[n-1];
} 