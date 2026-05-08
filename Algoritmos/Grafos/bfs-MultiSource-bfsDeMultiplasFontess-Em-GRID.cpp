// =========================================================================================
// TÍTULO: BFS DE MÚLTIPLAS FONTES (MULTI-SOURCE BFS) EM GRID
// PALAVRAS-CHAVE: Multi-source BFS, Múltiplas origens, Distância Manhattan em Grid, 
//                 Ondas simultâneas, Menor distância para QUALQUER alvo, Monstros no mapa,
//                 Fogo espalhando, Garimpando Master Coins.
// =========================================================================================

/*
    CASO DE USO CLÁSSICO:
        - Quando o problema pede a menor distância de um ponto até QUALQUER UM de vários alvos.
        - Ex: Fogo espalhando de várias árvores ao mesmo tempo.
        - Ex: Zumbis nascendo em vários pontos do mapa e correndo atrás de você.
        - Como funciona: Colocamos todas as origens na fila ANTES de começar o laço while.

    EXEMPLOS DE EXERCÍCIOS:
        1. O Fogo na Floresta (ou Laranjas Podres)
            O mapa tem árvores (T), espaços vazios (.) e árvores em chamas (F). A cada minuto,
            o fogo se espalha para as árvores vizinhas. A pergunta é: "Quantos minutos vai
            demorar para a floresta inteira queimar?" Ou "Vai sobrar alguma árvore?"

            Como usar o template: Coloque todos os F na fila inicial com distância 0. Rode a 
            BFS. A distância máxima no final é o tempo total. Se alguma árvore (T) terminar
            com a distância -1, significa que o fogo não chegou lá!!
        
        2. A Fuga dos Monstros (Clássico Absoluto)
            Você é um personagem (A) num labirinto e quer chegar em qualquer borda do mapa para
            fugir. Mas existem vários Monstros (M) espalhados pelo mapa que também andam 1 casa
            por segundo em sua direção: "É possível fugir sem ser pego?"

            Como usar o template: Aqui você usa duas matrizes de distância! Primeiro, você roda
            o seu template de Multi-source BFS colocando todos os Monstros (M) na fila. Isso vai 
            te dar uma matriz com o "Tempo de Chegada dos Monstros" em cada casa. Depois, você 
            roda uma BFS normal saindo de você A. Se você conseguir chegar numa casa da borda
            num tempo menor que o tempo do monstro para aquela mesma casa, você fugiu!
            --> Algoritmos/Grafos/bfs-MultiSource-Fuga-CorridaContraOTemp-Fogo-FugaDeLabirinto.cpp
        
        3. O Roteador / Hospital Mais Próximo
            O mapa tem várias casas (C) e vários hospitais (H). O problema pede para imprimir,
            para cada casa, a qual distância ela está do hospital mais perto dela.

            Como usar o template: É literalmente o que acabamos de fazer na questão das Master 
            Coins! Coloque todos os H na fila. Quando a BFS terminar, a matriz de distâncias 
            terá exatamente a resposta para cada casa. Em vez de calcular a distância casa por 
            casa, a onda dos hospitais faz todo o trabalho.

*/

#include <bits/stdc++.h>
#define ll long long
#define el '\n'
using namespace std;

// Vetores de direção (Cima, Baixo, Esquerda, Direita)
vector<ll> dl = {-1, 1, 0, 0}; 
vector<ll> dc = {0, 0, -1, 1}; 

void solve() {
    ll l, c;
    if (!(cin >> l >> c)) return;

    vector<string> grid(l);
    for(ll i = 0; i < l; i++) cin >> grid[i];

    // Matriz de distâncias inicializada com -1 (não visitado)
    vector<vector<ll>> dist(l, vector<ll>(c, -1));
    queue<pair<ll, ll>> fila;

    // 1. O PULO DO GATO: Coloca TODOS os servidores na fila com distância 0
    for(ll i = 0; i < l; i++) {
        for(ll j = 0; j < c; j++) {
            if(grid[i][j] == 'X') {
                dist[i][j] = 0;
                fila.push({i, j});
            }
        }
    }

    ll dist_maxima = 0;

    // 2. BFS Padrão: As ondas vão se espalhar perfeitamente
    while(!fila.empty()) {
        auto atual = fila.front();
        fila.pop();

        ll linha_atual = atual.first;
        ll col_atual = atual.second;

        for(ll i = 0; i < 4; i++) {
            ll nL = linha_atual + dl[i];
            ll nC = col_atual + dc[i];

            // Checa os limites da matriz e se já foi visitado
            if(nL >= 0 && nL < l && nC >= 0 && nC < c) {
                if(dist[nL][nC] == -1) { 
                    // A distância dessa nova casa é a distância da anterior + 1
                    dist[nL][nC] = dist[linha_atual][col_atual] + 1;
                    
                    // Atualiza o recorde do torneio "MAX"
                    dist_maxima = max(dist_maxima, dist[nL][nC]);
                    
                    fila.push({nL, nC});
                }
            }
        }
    }

    // 3. Conta quantas vezes a distância máxima apareceu nos espaços vazios
    ll quantidade = 0;
    for(ll i = 0; i < l; i++) {
        for(ll j = 0; j < c; j++) {
            if(grid[i][j] == '.' && dist[i][j] == dist_maxima) {
                quantidade++;
            }
        }
    }

    cout << dist_maxima << " " << quantidade << el;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}