// =========================================================================================
// TÍTULO: BUSCA BINÁRIA PARALELA (PARALLEL BINARY SEARCH)
// PALAVRAS-CHAVE: PBS, Offline Queries, Múltiplas Consultas, DSU dinâmico, Eventos no Tempo.
// =========================================================================================

/*
   CASO DE USO CLÁSSICO:
   - O problema tem um cenário que evolui com o tempo (M eventos aplicados em ordem).
   - O problema te faz MÚLTIPLAS perguntas (Q queries) do tipo: 
     "Qual foi o instante MÍNIMO para que a condição X fosse satisfeita?".
   - O PULO DO GATO: Em vez de fazer uma Busca Binária para cada query (o que daria TLE),
     nós simulamos a evolução do cenário inteiro apenas log(M) vezes, checando todas as
     queries "em paralelo" nos instantes em que seus 'mids' caem.
*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
using namespace std;

// Exemplo de Estrutura para guardar as Consultas (Queries)
struct Query {
    ll u, v;     // Ex: Quais cidades queremos saber se conectaram?
    ll alvo;     // Ex: Qual a soma mínima que queremos atingir?
    ll id;       // ID original para imprimir a resposta na ordem certa
};

void solve() {
    ll n, m, q; 
    if (!(cin >> n >> m >> q)) return;

    // Lemos os eventos que modificam o estado (Ex: arestas, atualizações de valores)
    // vector<Evento> eventos(m + 1);
    
    // Lemos as Q consultas
    vector<Query> consultas(q);
    f (i, 0, q) {
        cin >> consultas[i].u >> consultas[i].v; // Adapte para a leitura real do problema
        consultas[i].id = i;
    }

    // Vetores de controle da Busca Binária para CADA query individualmente
    vector<ll> L(q, 1);       // O piso de cada query (Ex: dia 1)
    vector<ll> R(q, m);       // O teto de cada query (Ex: dia M)
    vector<ll> ans(q, -1);    // Guarda a resposta final de cada query

    bool mudou_alguem = true;

    // A mágica acontece aqui: Esse while vai rodar no máximo log2(M) vezes (ex: ~20 vezes)
    while (mudou_alguem) {
        mudou_alguem = false;

        // to_check[mid] vai guardar uma lista de QUAIS queries precisam ser 
        // testadas quando a simulação do tempo chegar no dia 'mid'
        vector<vector<ll>> to_check(m + 1);

        f (i, 0, q) {
            if (L[i] <= R[i]) {
                mudou_alguem = true; // Ainda tem query que não encontrou a resposta exata
                ll mid = L[i] + (R[i] - L[i]) / 2;
                to_check[mid].pb(i);
            }
        }

        if (!mudou_alguem) break;

        // ---------------------------------------------------------------------
        // PASSO CRÍTICO: Resetar a Estrutura de Dados
        // Como vamos simular o tempo do dia 1 ao M, o mapa precisa voltar a ficar vazio!
        // dsu = DSU(n); ou bit.assign(n + 1, 0);
        // ---------------------------------------------------------------------

        // Simulando a linha do tempo uma ÚNICA vez
        f (dia, 1, m + 1) {
            
            // 1. Aplica o evento do dia atual no mundo
            // Exemplo: dsu.union_sets(eventos[dia].u, eventos[dia].v);
            
            // 2. Olha para todas as queries que "chutaram" que a resposta seria esse dia
            for (ll idx_query : to_check[dia]) {
                
                // 3. Pergunta para o estado ATUAL do mundo se a condição já foi atendida
                bool condicao_atendida = false;
                
                // Exemplo: condicao_atendida = (dsu.find_set(consultas[idx_query].u) == dsu.find_set(consultas[idx_query].v));

                if (condicao_atendida) {
                    // Se já satisfez, guardamos a resposta e tentamos um dia ANTERIOR (mais rigoroso)
                    ans[idx_query] = dia;
                    R[idx_query] = dia - 1;
                } else {
                    // Se ainda não satisfez, precisamos avançar mais no tempo (mais eventos)
                    L[idx_query] = dia + 1;
                }
            }
        }
    }

    // Imprime todas as respostas de forma 'offline'
    f (i, 0, q) {
        if (ans[i] != -1) {
            cout << ans[i] << el;
        } else {
            cout << "Impossivel" << el; // Dependendo do problema, pode ser que nunca aconteça
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}