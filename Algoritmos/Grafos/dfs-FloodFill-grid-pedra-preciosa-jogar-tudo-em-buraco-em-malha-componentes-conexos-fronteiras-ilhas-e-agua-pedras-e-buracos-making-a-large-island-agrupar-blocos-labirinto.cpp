#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, t, k, x, y, z, u, m;
string s, a, b, c;
ll INF = 1e18 + 7;
// =========================================================================================
// TÍTULO: DFS EM MALHA 2D (GRID) - COMPONENTES CONEXOS + FRONTEIRAS (PADRÃO "LARGE ISLAND")
// PALAVRAS-CHAVE: Flood Fill, Ilhas e Água, Pedras e Buracos, Componentes Conexos, 
//                 Fronteira, Making a Large Island, Agrupar Blocos, Labirinto, Grid DFS.
// =========================================================================================
/*
EXEMPLO DE QUESTAO:
    1. Fazendo uma Grande Ilha (Making A Large Island - LeetCode 827)
        Esse é o problema mais famoso que usa essa exata lógica. O juiz te dá um mapa de 0 s
        (água) e 1 (terra). As terras conectadas formam ilhas. Você tem o direito de transformar 
        apenas um quadrado de água (0) em terra (1). "Qual é o tamanho da maior ilha que você
        consegue formar?"

        Como o código resolve: A DFS calcula o tamanho de cada ilha e anota nas águas ao redor. 
        Se uma água (0) estiver entre duas ilhas (uma de tamanho 3 e outra de tamanho 4), o
        vetor "potencial" daquela água receberá 3 + 4 = 7. Quando você transformar essa água
        em terra (+1), a nova super-ilha terá tamanho 8. O código varre a matriz procurando a 
        água com o maior "potencial".

    2. O Bomberman Capitalista (Coleta de Recursos)
        Você está num mapa onde existem blocos de minérios (números > 0) e espaços de terra 
        vazios (0). Os minérios do mesmo tipo que se tocam formam um filão. Você tem apenas 1 
        bomba de extração que deve ser colocada na terra vazia. A bomba suga todo o minério dos 
        filões que encostarem nela. "Onde colocar a bomba para ficar mais rico?"
    
        Como o código resolve: É a história exata do Tupã que você resolveu! A DFS entra nos 
        filões, soma o valor total de ouro ali dentro, e doa esse "potencial de riqueza" para 
        as terras vazias na fronteira. O buraco com maior valor no final é onde a bomba deve 
        ser plantada.
    
    3. Planejamento Urbano (O Super Roteador / Hospital)
        O grid representa uma cidade. Quadrados com números > 0 são bairros habitados (o 
        número é a população). Quadrados com 0 são terrenos baldios. A prefeitura quer construir 
        um Super Roteador de Wi-Fi em um terreno baldio. O sinal desse roteador viaja por todos 
        os quarteirões habitados que estiverem conectados entre si e que tocarem o terreno do 
        roteador. "Onde construir o roteador para atender o máximo de pessoas?"
        
        Como o código resolve: Igualzinho! Cada bairro conectado é um "bloco". A DFS soma a 
        população do bloco e joga para os terrenos baldios vizinhos. O terreno baldio com o maior 
        número no vetor potencial é o vencedor.


*/
#include <bits/stdc++.h>
#define ll long long
#define el '\n'
#define vll vector<vector<ll>>
using namespace std;

// Vetores de Direção (Cima, Baixo, Esquerda, Direita)
vector<ll> dl = {-1, 1, 0, 0}; 
vector<ll> dc = {0, 0, -1, 1}; 
vector<vector<bool>> vis;

// Função DFS para descobrir o tamanho/soma de um bloco e mapear as fronteiras (vazios/buracos)
void dfs(ll l, ll c, ll n, ll m, vll &grid, ll &somaBloco, set<pair<ll, ll>> &fronteira) {
    vis[l][c] = true;
    
    // 1. Acumula o valor do bloco atual
    // (Se o problema pedir apenas o TAMANHO do bloco, mude para: somaBloco += 1;)
    somaBloco += grid[l][c]; 

    // 2. Olha para os 4 vizinhos
    for (ll i = 0; i < 4; i++) {
        ll nL = l + dl[i];
        ll nC = c + dc[i];

        // 3. Checa os limites da matriz (N linhas, M colunas)
        if (nL >= 0 && nL < n && nC >= 0 && nC < m) {
            
            // 4. Se for o MESMO TIPO de elemento (ex: pedra > 0) e não visitado, continua a DFS
            if (grid[nL][nC] > 0 && !vis[nL][nC]) {
                dfs(nL, nC, n, m, grid, somaBloco, fronteira);
            }
            // 5. Se for um espaço VAZIO (ex: buraco == 0), anota a coordenada na fronteira
            else if (grid[nL][nC] == 0) {
                fronteira.insert({nL, nC}); // O 'set' impede buracos duplicados pro mesmo bloco
            }
        }
    }
}

/* ================= EXEMPLO DE USO DENTRO DO SOLVE() ================= 

void solve() {
    ll n, m; // N linhas, M colunas
    cin >> n >> m;
    
    vll grid(n, vl(m));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // SEMPRE inicializar a matriz de visitados com o tamanho exato da entrada
    vis.assign(n, vector<bool>(m, false));
    
    // Matriz para guardar quanto "potencial" cada célula vazia recebe dos blocos vizinhos
    vll potencial(n, vl(m, 0));

    // 1. Percorrer toda a matriz buscando pedras/ilhas não visitadas
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            
            if (grid[i][j] > 0 && !vis[i][j]) {
                ll somaBloco = 0;
                set<pair<ll, ll>> fronteira;
                
                dfs(i, j, n, m, grid, somaBloco, fronteira);
                
                // 2. Doar o valor total do bloco para TODOS os buracos que encostam nele
                for (auto &x : fronteira) {
                    potencial[x.first][x.second] += somaBloco; 
                }
            }
        }
    }

    // 3. Encontrar a melhor célula vazia (maior potencial)
    ll ans = 0; 
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (grid[i][j] == 0) { // Só analisa quem é buraco/água originalmente
                ans = max(ans, potencial[i][j]);
            }
        }
    }
    
    cout << ans << el;
}
======================================================================== */