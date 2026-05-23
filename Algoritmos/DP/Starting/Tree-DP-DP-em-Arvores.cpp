// =========================================================================================
// TÍTULO: PROGRAMAÇÃO DINÂMICA EM ÁRVORES (TREE DP)
// PALAVRAS-CHAVE: DFS, Subárvore, Independent Set, Coloração, Relação Pai-Filho.
// =========================================================================================

/*
   CASOS DE USO CLÁSSICOS:
   - "Qual o subconjunto máximo de nós que posso escolher sem pegar dois vizinhos?"
   - "De quantas formas posso pintar a árvore sem desrespeitar a regra de adjacência?"
   
   O PULO DO GATO: O estado de um "Pai" depende unicamente da combinação (soma/multiplicação)
   dos estados dos seus "Filhos". A DFS mergulha até as folhas (casos base) e constrói a
   resposta de baixo para cima (Bottom-Up disfarçado de recursão).
*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
using namespace std;

const ll MOD = 1e9 + 7;
const int MAXN = 200005;

// Estruturas globais são padrão em competições para evitar estourar a memória da recursão
vector<ll> adj[MAXN];
ll dp[MAXN][2]; 

// =========================================================================
// A DFS COM DP (Onde a mágica acontece)
// u = nó atual, p = nó pai (crucial para não voltar pelo caminho que viemos)
// =========================================================================
void dfs(ll u, ll p) {
    // 1. CASOS BASE INICIAIS
    // Assumimos inicialmente que a subárvore deste nó é apenas ele mesmo.
    // Há 1 forma de ele ser branco, e 1 forma de ele ser preto.
    dp[u][0] = 1; // 0 = Branco
    dp[u][1] = 1; // 1 = Preto

    // Varremos todos os vizinhos do nó atual
    for (ll v : adj[u]) {
        
        // A Regra de Ouro da DFS em árvores: não volte para quem te chamou!
        if (v == p) continue; 

        // 2. MERGULHO PROFUNDO (Desce até as folhas)
        dfs(v, u);

        // 3. TRANSIÇÃO DA DP (Isso só executa na volta, quando o filho 'v' já terminou)
        
        // Se o PAI (u) for Branco (0), o filho (v) está livre: pode ser Branco (0) OU Preto (1)
        // Multiplicamos as possibilidades porque as escolhas para cada filho são independentes.
        dp[u][0] = (dp[u][0] * (dp[v][0] + dp[v][1]) % MOD) % MOD;
        
        // Se o PAI (u) for Preto (1), o filho (v) é OBRIGADO a ser Branco (0)
        // O estado [v][1] morre aqui, impedindo que dois pretos fiquem juntos.
        dp[u][1] = (dp[u][1] * dp[v][0]) % MOD;
    }
}

void solve() {
    ll n; 
    if (!(cin >> n)) return;

    // LIMPEZA OBRIGATÓRIA: Vital para problemas com múltiplos casos de teste (while t--)
    f (i, 1, n + 1) {
        adj[i].clear();
        dp[i][0] = dp[i][1] = 0;
    }

    // Leitura da Árvore (Uma árvore com N nós sempre tem N-1 arestas)
    f (i, 0, n - 1) {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u); // Árvores são sempre grafos não-direcionados
    }

    // Iniciamos a DFS sempre da raiz da árvore (nó 1). 
    // Passamos '0' como pai, assumindo que os nós válidos começam em 1.
    dfs(1, 0);

    // A resposta final de TODA a árvore fica acumulada na raiz.
    // Pode ser o cenário com a raiz branca OU o cenário com a raiz preta.
    ll ans = (dp[1][0] + dp[1][1]) % MOD;
    
    cout << "Formas validas de pintar a arvore: " << ans << el;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // ll t; cin >> t;
    // while(t--)
    solve();
    return 0;
}