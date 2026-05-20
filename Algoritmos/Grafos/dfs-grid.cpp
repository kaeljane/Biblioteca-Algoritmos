// =========================================================================================
// TÍTULO: DFS EM MALHA 2D (GRID) / FLOOD FILL
// PALAVRAS-CHAVE: Matriz, Grid, Mapa, Flood fill, Componentes conexos, Labirinto, 
//                 Vetores de direção, Contar ilhas/quartos.
// =========================================================================================

/*
   CASO DE USO CLÁSSICO:
   - O problema te dá um mapa de caracteres (Ex: '.' é chão livre, '#' é parede).
   - Ele pede para contar quantos "blocos" de chão existem, ou o tamanho do maior bloco.
   - A REGRA DE OURO: Não crie listas de adjacência! Ande diretamente em cima da matriz.
*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
using namespace std;

void solve() {
    ll l, c; 
    if (!(cin >> l >> c)) return;

    // Lemos a matriz de caracteres como um vetor de strings (muito mais rápido e seguro)
    vector<string> mat(l);
    f (i, 0, l) {
        cin >> mat[i];
    }

    // Matriz de visitados zerada com as dimensões exatas do mapa
    vector<vector<bool>> vis(l, vector<bool>(c, false));

    // Vetores de Direção: Cima, Baixo, Esquerda, Direita
    // É isso que permite andar na matriz com um simples 'for' de 0 a 3
    vector<ll> dl = {-1, 1, 0, 0}; 
    vector<ll> dc = {0, 0, -1, 1}; 

    // DFS usando Lambda para enxergar 'mat' e 'vis' automaticamente
    function<void(ll, ll)> dfs_grid = [&](ll linha, ll coluna) {
        
        vis[linha][coluna] = true; // Pinta o chão atual

        // Tenta dar um passo para os 4 vizinhos ortogonais
        f (i, 0, 4) {
            ll nL = linha + dl[i]; // Nova Linha
            ll nC = coluna + dc[i]; // Nova Coluna

            // O Guarda de Fronteira: Não deixa o código acessar fora do mapa
            if (nL >= 0 && nL < l && nC >= 0 && nC < c) {
                
                // Só entra na casa vizinha se for chão livre ('.') e ainda não foi visitada
                if (mat[nL][nC] == '.' && !vis[nL][nC]) {
                    dfs_grid(nL, nC);
                }
                
            }
        }
    };

    ll componentes_conexos = 0;
    
    // Varredura completa: Procuramos por qualquer pedaço de chão que ainda não mapeamos
    f (i, 0, l) {
        f (j, 0, c) {
            
            // Se achei um chão livre não visitado, é uma nova sala/ilha!
            if (mat[i][j] == '.' && !vis[i][j]) {
                dfs_grid(i, j); // A DFS vai pintar a sala inteira
                componentes_conexos++; // Contabilizamos a sala
            }
            
        }
    }

    cout << "Quantidade de blocos isolados: " << componentes_conexos << el;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    // ll t; cin >> t;
    // while (t--) 
    
    solve();
    
    return 0;
}