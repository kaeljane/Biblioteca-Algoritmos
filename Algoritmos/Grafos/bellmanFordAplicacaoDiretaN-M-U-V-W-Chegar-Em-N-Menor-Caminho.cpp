#include <bits/stdc++.h>
#define ll long long
#define el '\n'
using namespace std;
ll n, t, k, x, y, z, u, m;
string s, a, b, c;
ll INF = 1e18 + 7;

struct Aresta {
    ll u, v, w;
};

void solve() {
    cin>>n>>m;
    
    vector<Aresta> arestas(m); // se for nao direcionado nao declare tamanho
    for (ll i = 0; i < m; i++) {
        cin >> arestas[i].u >> arestas[i].v >> arestas[i].w;
        /*
        Em caso de ser nao-direcionado caso declare o vetor vazio de arestas 
        e jogue as arestas dentro dele da seguinte forma 
        arestas.push_back({u, v, w}); e arestas.push_back({v, u, w}); 
        
        */ 
    }

    ll origem = 1;
    vector<ll> dist(n+1, INF);
    dist[origem] = 0;

    for (ll i = 1; i < n; i++) {
        bool mudou = false;

        for (Aresta a : arestas) {
            if (dist[a.u] != INF && dist[a.u] + a.w < dist[a.v]) {
                dist[a.v] = dist[a.u] + a.w;
                mudou = true;
            }
        }
        if (!mudou) break;
    }

    for (ll i = 1; i < n; i++) { 
        for (Aresta a : arestas) {
            if (dist[a.u] != INF && dist[a.v] != -INF) {
                if (dist[a.u] == -INF || dist[a.u] + a.w < dist[a.v]) {
                    dist[a.v] = -INF;
                }
            }
        }
    }

    if (dist[n] == -INF) { // porque o nó está dentro ou alcançável por um ciclo negativo
        cout << "-INF" << el;
    }
    else {
        cout << dist[n] << el;
    }
    
    
}