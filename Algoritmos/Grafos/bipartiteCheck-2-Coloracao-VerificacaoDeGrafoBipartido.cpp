// =========================================================================================
// TÍTULO: VERIFICAÇÃO DE GRAFO BIPARTIDO (2-COLORAÇÃO COM BFS)
// PALAVRAS-CHAVE: Grafo Bipartido, bipartite check, coloração, 2-color, divisão de equipes,
//                 ciclo ímpar, inimigos, duas salas, XOR, componentes desconexos.
// =========================================================================================

/*
    - NO CODEFORCES E EM OUTRAS PLATAFORMAS, A PALAVRA "BIPARTIDO" QUASE NUNCA APARECE NO TEXTO
    DO PROBLEMA. VOCÊ PRECISAR SABER IDENTIFICAR OS DISFARCES!!

    CASO DE USO CLÁSSICO:
        - Dividir elementos em DOIS grupos onde não pode haver conexão interna.
        - Detectar se o grafo possui um CICLO ÍMPAR (se tiver, retorna false).
        - O vetor 'cor' serve como resposta: cor[i] == 0 (Time A), cor[i] == 1 (Time B).

    EXEMPLOS CLÁSSICOS:
        1. Divisão de Inimigos / Equipes Rivais
            O juiz te dá um grupo de N pessoas e uma lista de pares que "se odeiam" e não podem
            ficar juntos. 

            A pergunta é: "É possível dividir todo mundo em exatamente 2 turmas/times sem que 
            nenhum inimigo fique na mesma turma?"

            Como resolver: Cada pessoa é um nó. O ódio é uma aresta. Se o isBipartite retornar 
            true, é possível! As cores 0 e 1 representam em qual sala cada um deve ficar.
        
        2. O tabuleiro de Xadrez Genérico 
            Muitos problemas em malhas 2D (grids) funcionam com a lógica bipartida. Pense num
            tabuleiro de xadrez: você só pode ir de uma casa preta para uma branca. Se o problema
            envolve movimentação de peças que trocam de estado (ou grafos que imitam grids),
            verificar se a estrutura subjacente é bipartida destravar a solução da questão.

        3. Bugs no Sistema / Casamento Estável
            Você tem processos rodando e eles não podem acessar o mesmo recurso simultaneamente
            (uma "fase" de execução 1 e "fase" 2). O problema pergunta se o sistema vai travar
            devido a conflitos cíclicos. Encontrar ciclos ímpares (a falha do grafo bipartido)
            responde à questão.



*/
#include <bits/stdc++.h>
#define ll long long
#define el '\n'
using namespace std;

// Recebe o número de vértices 'n' e a lista de adjacência do grafo.
// Funciona em O(V + E). Assumindo grafo 1-based (vértices de 1 até N).
bool isBipartite(ll n, vector<vector<ll>>& adj) {
    // Vetor de cores: tamanho N+1. -1 (não visitado), 0 (Cor A), 1 (Cor B)
    vector<ll> cor(n + 1, -1); 
    bool eh_bipartido = true;
    
    // O laço externo garante que todos os componentes conexos sejam checados
    for (ll i = 1; i <= n; ++i) {
        if (cor[i] == -1) {
            queue<ll> q;
            q.push(i);
            cor[i] = 0; // Pinta o primeiro nó do componente com a cor 0
            
            while (!q.empty()) {
                ll atual = q.front();
                q.pop();
                
                for (ll vizinho : adj[atual]) {
                    // Se não foi pintado, pinta com a cor INVERSA do atual
                    if (cor[vizinho] == -1) {
                        cor[vizinho] = cor[atual] ^ 1; // 0 vira 1, 1 vira 0
                        q.push(vizinho);
                    } 
                    // Se já foi pintado, a cor DEVE ser diferente da cor atual
                    else if (cor[vizinho] == cor[atual]) {
                        eh_bipartido = false;
                        // Opcional: Se só quiser saber se é ou não, pode dar 'return false;' aqui
                        // para otimizar, mas manter a BFS rodando preenche o vetor inteiro.
                    }
                }
            }
        }
    }

    return eh_bipartido;
}

/* ================= EXEMPLO DE USO DENTRO DO SOLVE() ================= 

void solve() {
    ll n, m; 
    if (!(cin >> n >> m)) return;

    // Inicialização dinâmica para 1-based (n + 1 posições)
    vector<vector<ll>> adj(n + 1);

    for (ll i = 0; i < m; i++) {
        ll u, v; 
        cin >> u >> v;
        // u e v já são lidos como 1-based, basta inserir direto:
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (isBipartite(n, adj)) {
        cout << "SIM, e possivel dividir em dois grupos!" << el;
        // Para imprimir quem ficou em qual grupo, basta iterar sobre o vetor 'cor'
        // de i = 1 até i <= n.
    } else {
        cout << "NAO, impossivel!" << el;
    }
}
======================================================================== */