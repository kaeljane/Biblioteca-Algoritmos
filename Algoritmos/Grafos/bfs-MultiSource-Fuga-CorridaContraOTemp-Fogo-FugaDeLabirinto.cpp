// =========================================================================================
// TÍTULO: BFS DE FUGA (CORRIDA CONTRA MONSTROS/FOGO)
// PALAVRAS-CHAVE: Monsters, Fuga do Labirinto, Multi-source BFS + BFS Simples, 
//                 Competição de tempo, Escape das bordas, Grid Pathfinding.
// =========================================================================================

/*
   LÓGICA "MAIS RÁPIDO QUE O PERIGO":
   1. Roda Multi-source BFS para todos os monstros (M) -> guarda em distM.
   2. Roda BFS simples para o jogador (A) -> guarda em distA.
   3. O jogador SÓ PODE ir para (ni, nj) se (distA[i][j] + 1 < distM[ni][nj]).
   4. Se distA chegar em (i == 0 || i == L-1 || j == 0 || j == C-1), VITÓRIA!
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'

vector<ll> dl = {-1, 1, 0, 0};
vector<ll> dc = {0, 0, -1, 1};

void solve() {
    ll l, c;
    cin >> l >> c;
    vector<string> grid(l);
    pair<ll, ll> inicio;
    
    vector<vector<ll>> distM(l, vector<ll>(c, 1e18)); // Distância dos Monstros
    vector<vector<ll>> distA(l, vector<ll>(c, -1));   // Distância do Jogador
    queue<pair<ll, ll>> qM, qA;

    for(ll i = 0; i < l; i++) {
        cin >> grid[i];
        for(ll j = 0; j < c; j++) {
            if(grid[i][j] == 'M') {
                distM[i][j] = 0;
                qM.push({i, j});
            } else if(grid[i][j] == 'A') {
                inicio = {i, j};
            }
        }
    }

    // --- PASSO 1: Multi-source BFS dos Monstros ---
    while(!qM.empty()) {
        auto [li, ci] = qM.front(); qM.pop();
        for(int i = 0; i < 4; i++) {
            ll ni = li + dl[i], nj = ci + dc[i];
            if(ni >= 0 && ni < l && nj >= 0 && nj < c && grid[ni][nj] != '#' && distM[ni][nj] == 1e18) {
                distM[ni][nj] = distM[li][ci] + 1;
                qM.push({ni, nj});
            }
        }
    }

    // --- PASSO 2: BFS do Jogador ---
    distA[inicio.first][inicio.second] = 0;
    qA.push(inicio);

    // Checagem imediata: se o início já for na borda
    if(inicio.first == 0 || inicio.first == l-1 || inicio.second == 0 || inicio.second == c-1) {
        cout << "YES" << el << 0 << el;
        return;
    }

    while(!qA.empty()) {
        auto [li, ci] = qA.front(); qA.pop();

        for(int i = 0; i < 4; i++) {
            ll ni = li + dl[i], nj = ci + dc[i];
            
            // Condições: Dentro do mapa, não é parede, não visitado
            if(ni >= 0 && ni < l && nj >= 0 && nj < c && grid[ni][nj] == '.' && distA[ni][nj] == -1) {
                
                // A REGRA DE OURO: Chegar antes do monstro
                if(distA[li][ci] + 1 < distM[ni][nj]) {
                    distA[ni][nj] = distA[li][ci] + 1;
                    
                    // Condição de ESCAPE: Chegou na borda?
                    if(ni == 0 || ni == l-1 || nj == 0 || nj == c-1) {
                        cout << "YES" << el << distA[ni][nj] << el;
                        return;
                    }
                    qA.push({ni, nj});
                }
            }
        }
    }

    cout << "NO" << el;
}