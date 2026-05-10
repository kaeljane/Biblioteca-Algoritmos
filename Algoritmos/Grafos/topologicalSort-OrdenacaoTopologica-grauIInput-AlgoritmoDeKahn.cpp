// =========================================================================================
// TÍTULO: ORDENAÇÃO TOPOLÓGICA (TOPOSORT)
// PALAVRAS-CHAVE: Toposort, DAG, Dependências, Pré-requisitos, Algoritmo de Kahn, Ciclos.
// =========================================================================================

/*
   CASO DE USO CLÁSSICO:
   - Quando você tem tarefas com pré-requisitos (A tem que acontecer antes de B).
   - Ex: Grade curricular da faculdade, ordem de compilação de arquivos.
   - SÓ FUNCIONA EM DAG (Grafo Direcionado Acíclico).
   
   MÉTODO 1 (KAHN / BFS): Melhor para detectar se existe um ciclo impossível no meio. (Recomendado)
   MÉTODO 2 (DFS): Mais curto de digitar, mas a ordem é construída de trás para frente.

    EXEMPLOS CLÁSSICOS:
        1. A Grade Curricular (Course Schedule)
            Esse é o problema mais "arroz com feijão" de Toposort. Quase toda plataforma 
            tem uma versão dele.
            
            A História: Você tem N matérias para cursar na faculdade. Para cursar
            "Cálculo 2", você precisa já ter passado em "Cálculo 1". O problema te dá 
            uma lista de pares (A, B) dizendo que A é pré-requisito de B.
            
            A Pergunta: "É possível o aluno se formar?" ou "Qual a ordem em que ele deve
            pegar as matérias?"Como Resolver: É a aplicação direta do seu Algoritmo de
            Kahn. A pergunta "É possível se formar?" é na verdade uma checagem de ciclo.
            Se o Kahn disser que existe um ciclo (ex: A precisa de B, B precisa de C, e 
            C precisa de A), o aluno fica travado para sempre e a resposta é "Não".


        2. O Dicionário Alienígena (Alien Dictionary)
            Esse é um clássico absoluto em entrevistas de Big Techs (Google, Meta) e
            aparece muito no CodeForces.
            
            A História: Você recebe uma lista de palavras que estão em uma língua 
            alienígena. Você sabe que a lista já está ordenada "alfabeticamente", mas 
            você não sabe qual é a ordem do alfabeto deles (por exemplo, talvez o 'Z' 
            venha antes do 'A').
            
            A Pergunta: "Descubra a ordem das letras do alfabeto alienígena".
            Como Resolver: O desafio aqui é montar o grafo. Você compara a Palavra 1 com 
            a Palavra 2. A primeira letra que for diferente entre elas te dá uma regra! 
            Se a palavra CBA vem antes de CZA, isso significa que o B vem antes do Z no 
            alfabeto deles. Você cria uma aresta direcionada B -> Z. Depois de 
            comparar todas as palavras vizinhas e montar o grafo, é só rodar a sua 
            Ordenação Topológica normal para descobrir o alfabeto inteiro!

        3. A Ordem Desempate (Lexicograficamente Menor)
            Os autores de problemas adoram colocar uma restrição a mais para ver se você 
            realmente entende como o algoritmo de Kahn funciona por baixo dos panos.


            A História: Você tem várias tarefas com pré-requisitos. Porém, o chefe diz: 
            "Se em algum momento você tiver várias tarefas liberadas ao mesmo tempo, faça 
            primeiro a que tem o menor número de ID".

            A Pergunta: "Qual é a sequência exata das tarefas?"

            Como Resolver: Você usa exatamente o seu template do Kahn, mas com uma 
            alteração minúscula: em vez de usar uma queue<ll> fila normal, você usa uma 
            priority_queue (a mesma que você usa no Dijkstra, configurada com greater 
            para o menor ficar no topo). Assim, se as tarefas 4, 7 e 2 estiverem prontas 
            ao mesmo tempo, a fila de prioridade sempre vai jogar a tarefa 2 para fora 
            primeiro.

        4. DP em DAG (O Caminho Mais Longo)
            Às vezes, a Ordenação Topológica não é a resposta final, mas sim o Passo 1 
            obrigatório da questão.

            A História: Você está jogando um videogame (que forma um mapa sem ciclos). 
            Cada fase tem moedas. Você quer descobrir qual é a maior quantidade de moedas 
            que consegue pegar do início ao fim.

            A Pergunta: "Qual o caminho mais longo / de maior peso?" (Lembrando que 
            Dijkstra não funciona para caminho mais longo).

            Como Resolver: Quando o grafo é um DAG, você pode usar Programação Dinâmica 
            (DP). Mas para a DP funcionar, você precisa resolver os estados em uma ordem 
            lógica (não dá para calcular o máximo de moedas da Fase 5 se você ainda não 
            calculou as da Fase 4). Então você roda a sua Ordenação Topológica para ter 
            uma lista linear das fases, e depois faz um laço for processando a DP 
            exatamente na ordem dessa lista.

*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
using namespace std;

// =========================================================================
// OPÇÃO 1: ALGORITMO DE KAHN (BFS) - MAIS SEGURO PARA COMPETIÇÃO
// =========================================================================
void solve_kahn() {
    ll n, m; 
    if (!(cin >> n >> m)) return;
    
    vector<vector<ll>> adj(n + 1);
    vector<ll> grau_in(n + 1, 0); 
    
    f (i, 0, m) {
        ll u, v; 
        cin >> u >> v; // Aresta Direcionada: u -> v
        adj[u].pb(v);
        grau_in[v]++;  // Conta quantas setas chegam no vértice 'v' (pré-requisitos)
    }
    
    queue<ll> fila;
    
    // 1. Coloca na fila as matérias do 1º período (sem pré-requisitos)
    f (i, 1, n + 1) {
        if (grau_in[i] == 0) {
            fila.push(i);
        }
    }
    
    vector<ll> ordem;
    
    // 2. Processa a fila
    while (!fila.empty()) {
        ll u = fila.front();
        fila.pop();
        
        ordem.pb(u);
        
        // 3. Remove as dependências dos vizinhos
        for (ll vizinho : adj[u]) {
            grau_in[vizinho]--; 
            
            // Se o vizinho zerou as dependências, ele está pronto para ser cursado
            if (grau_in[vizinho] == 0) {
                fila.push(vizinho);
            }
        }
    }
    
    // 4. Verificação de Ciclo (A grande vantagem do Kahn)
    if (ordem.size() != n) {
        cout << "IMPOSSIVEL! Existe um ciclo de dependencias." << el;
    } else {
        f (i, 0, ordem.size()) cout << ordem[i] << " ";
        cout << el;
    }
}

// =========================================================================
// OPÇÃO 2: MÉTODO DFS (Código super enxuto)
// =========================================================================
void solve_dfs() {
    ll n, m; 
    if (!(cin >> n >> m)) return;
    
    vector<vector<ll>> adj(n + 1);
    
    f (i, 0, m) {
        ll u, v; 
        cin >> u >> v;
        adj[u].pb(v);
    }
    
    vector<bool> vis(n + 1, false);
    vector<ll> ordem;
    
    // DFS usando Lambda: Fica elegante e acessa os vetores externos automaticamente
    function<void(ll)> dfs = [&](ll u) {
        vis[u] = true;
        
        for (ll vizinho : adj[u]) {
            if (!vis[vizinho]) dfs(vizinho);
        }
        
        // Quando não tem mais vizinhos, adiciona na resposta
        ordem.pb(u); 
    };
    
    // Chama a DFS para todos os vértices não visitados
    f (i, 1, n + 1) {
        if (!vis[i]) dfs(i);
    }
    
    // Na DFS, a ordem topológica sai de trás para frente. Precisamos inverter!
    reverse(all(ordem));
    
    f (i, 0, ordem.size()) cout << ordem[i] << " ";
    cout << el;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    // ll t; cin >> t;
    // while (t--) 
    
    solve_kahn(); // Normalmente usamos o Kahn
    
    return 0;
}