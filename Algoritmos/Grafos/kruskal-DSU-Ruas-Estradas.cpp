// =========================================================================================
// TÍTULO: KRUSKAL (ÁRVORE GERADORA MÍNIMA - MST) + DSU
// PALAVRAS-CHAVE: Kruskal, Minimum Spanning Tree, MST, Disjoint Set Union, Union-Find,
//                 Conectar todas as cidades com menor custo, Redes, Fibra óptica.
// =========================================================================================

/*
   CASO DE USO CLÁSSICO:
   - Quando você tem vários pontos soltos e precisa conectar TODOS eles.
   - O objetivo é gastar O MÍNIMO POSSÍVEL para que não exista nenhum nó isolado.
   - Não importa a distância da origem até o destino, só importa que haja um caminho.
   - Extremamente rápido. Complexidade: O(E log E) devido à ordenação das arestas.

   SE NAS TAGS DO CODEFORCES TIVER GRAPHS, DSU E SORTING JUNTAS NA MESMA QUESTAO, A 
   CHANCE DE SER ÁRVORE GERADORA MÍNIMA PEDINDO O SEU TEMPLATE DE KRUSKAL BEIRA OS 
   100%.


    EXEMPLOS CLÁSSICOS:
        1. Conexão de Infraestrutura
            Esse é o problema mais "puro" de Kruskal. O enunciado não tenta te enganar.

            História: Um prefeito que asfaltar estradas de terra para que as cidades
            fiquem conectadas. Ou uma empresa de telecomunições quer passar fibra ótica
            entre vários servidores.

            A Pergunta: "Qual é o custo mínimo para garantir que exista um caminho
            (direto ou indireto) entre qualquer par de cidades/computadores?"

            Como Resolver: É só plugar o template direto. Ordena as ruas pelo preço 
            do asfalto roda o Kruskal e impreme o custo_total.

        2. O Problema da "Economia" (Estradas Escuras) 
            Esse é um dos disfarces mais famosos do mundo da programação competitiva
            (tem uma questão clássica com esse nome). Ele inverte a pergunta para te 
            confundir.

            História: O mapa já está 100% conectado com estradas caras (ou postes de luz
            ligados). O governo está em crise e precisa "apagar/destruir" a maior qt
            possível de estradas para economizar dinheiro, mas sem isolar nenhuma cidade.

            Como resolver: Em vez de focar no que você vai destruir, foque no que você
            vai manter.
                1. Some o custo de todas as estradas do input (esse é o Custo Original)
                2. Rode o Kruskal normal para achar o custo mínimo de manter todo mundo
                conectado (Custo MST)
                3. A resposta é Custo_Original - Custo_MST.
        
        3. O Grafo "Parcialmente Construído"
            Esse costuma derruvar muita gente que usa o algoritmo de Prim em vez de 
            Kruskal.

            História: Existem N cidades. O prefeito anterior já asfaltou algumas 
            estradas, mas o projeto parou na metade. Agora você precisa asfaltar novas
            estradas para conectar o resto do país.

            A Pergunta: "Qual é o custo mínima para terminar o projeto?"

            Como resolver: O seu DSU brilha muito aqui.
                1. Você ler as entradas que já existem e dá um dsu.union_sets(u, v) 
                direto nelas, sem somar custo nenhum.
                2. Depois você ler as estradas que podem ser construídas, ordena por
                peso e roda o for do kruskal normalmente. O DSU já vai saber 
                inteligentemente que não precisa gastar dinheiro asfaltando rotas que a
                gestão anterior já conectou!
        
        4. Coordenadas no Plano Cartesiano (Grafos Densos)
            Messe tipod e problema, o input não te dá as arestas prontas. Você tem que
            construí-las do zero.

            História: você recebe as coordenadas (X, Y) de N ilhas (ou acampamentos).
            Você pode construir pontes entre qualquer par de ilhas. O custo da ponte é
            a distância geométrica entre elas.

            A Pergunta: "Qual o menor comprimento total de pontes para ligar todas as 
            ilhas?"

            Como resolver: Você precisa um grafo completo.
                1. Roda o Kruskal no vetor de arestas que você acabou de criar.
                Atenção: Como você cria arestas de todos para todos, a qt de arestas
                fica gigantescar (M aprox N^2). Por isso, esse tipo de problema costuma
                ter um N menor (até uns 2.000)
            

*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
using namespace std;

// 1. Estrutura elegante para ler e ordenar arestas facilmente
struct Aresta {
    ll u, v, peso;
    bool operator<(Aresta const& outra) {
        return peso < outra.peso; // Ensina o C++ a ordenar do menor para o maior peso
    }
};

// 2. Estrutura do Disjoint Set Union (Totalmente blindada e reaproveitável)
struct DSU {
    vector<ll> pai, tamanho;
    
    // Construtor: Já cria os vetores do tamanho certo e cada nó é seu próprio chefe
    DSU(ll n) {
        pai.assign(n + 1, 0);
        tamanho.assign(n + 1, 1);
        f (i, 1, n + 1) pai[i] = i;
    }
    
    // Acha o chefe supremo com Compressão de Caminho (O(1) amortizado)
    ll find_set(ll v) {
        if (v == pai[v]) return v;
        return pai[v] = find_set(pai[v]);
    }
    
    // Une dois grupos. Retorna 'true' se uniu, ou 'false' se já formavam um ciclo
    bool union_sets(ll a, ll b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            // União por Tamanho (o menor se submete ao maior)
            if (tamanho[a] < tamanho[b]) swap(a, b);
            pai[b] = a;
            tamanho[a] += tamanho[b];
            return true; 
        }
        return false; 
    }
};

void solve() {
    ll n, m; 
    if (!(cin >> n >> m)) return;

    vector<Aresta> arestas(m);
    f (i, 0, m) {
        cin >> arestas[i].u >> arestas[i].v >> arestas[i].peso;
    }

    // Passo 1: Ordena as arestas da mais barata para a mais cara
    sort(arestas.begin(), arestas.end());

    // Inicializa a nossa estrutura DSU limpinha para 'n' nós
    DSU dsu(n);

    ll custo_total = 0;
    ll arestas_usadas = 0;
    // vector<Aresta> mst; // Descomente se precisar imprimir quais ruas foram usadas

    // Passo 2: Tenta usar cada aresta, começando pela mais barata
    for (auto a : arestas) {
        
        // Se a união deu certo (não formou ciclo), adicionamos na resposta!
        if (dsu.union_sets(a.u, a.v)) {
            custo_total += a.peso;
            arestas_usadas++;
            // mst.pb(a);
            
            // Otimização extra: Uma árvore sempre tem (N - 1) arestas. 
            // Se já pegamos isso, o mapa inteiro já está conectado!
            if (arestas_usadas == n - 1) break;
        }
    }

    // Checagem de segurança: e se o grafo original for desconexo?
    if (arestas_usadas < n - 1 && n > 1) {
        cout << "Impossivel conectar todas as cidades!" << el;
    } else {
        cout << "Custo da Arvore Geradora Minima: " << custo_total << el;
    }
}

signed main() {
    // ll t; cin >> t;
    // while (t--) 
    solve();
    return 0;
}