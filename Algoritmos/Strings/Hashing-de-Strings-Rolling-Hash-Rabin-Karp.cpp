// =========================================================================================
// TÍTULO: STRINGS - ROLLING HASH (RABIN-KARP / DOUBLE HASHING)
// PALAVRAS-CHAVE: Comparar Substrings, Palíndromos, Rabin-Karp, Colisão, O(1).
// =========================================================================================

/*
   CASO DE USO CLÁSSICO:
   - "A substring de L1 a R1 é igual à substring de L2 a R2?"
   - "Qual o tamanho do maior prefixo que também é sufixo?"
   - O PULO DO GATO: Comparamos hashes em O(1) em vez de comparar as strings letra por letra.
   - USAMOS DOUBLE HASH: Dois pares de (Base, Módulo) para chance de colisão ser praticamente zero.
*/

#include <bits/stdc++.h>
#define ll long long
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
using namespace std;

// Os dois Módulos e as duas Bases (sempre números primos)
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;
const ll B1 = 313;
const ll B2 = 317;

struct HashString {
    vector<ll> h1, h2;
    vector<ll> p1, p2;

    // Construtor que pré-calcula os hashes de todos os prefixos em O(N)
    HashString(const string& s) {
        ll n = s.size();
        h1.assign(n + 1, 0); h2.assign(n + 1, 0);
        p1.assign(n + 1, 1); p2.assign(n + 1, 1);

        f (i, 0, n) {
            // Calcula as potências das bases
            p1[i + 1] = (p1[i] * B1) % MOD1;
            p2[i + 1] = (p2[i] * B2) % MOD2;

            // Calcula o hash acumulado (Rolling Hash)
            h1[i + 1] = (h1[i] * B1 + s[i]) % MOD1;
            h2[i + 1] = (h2[i] * B2 + s[i]) % MOD2;
        }
    }

    // Retorna o Hash duplo da substring s[L...R] em O(1) (Índices base-0)
    pair<ll, ll> get_hash(ll l, ll r) {
        ll hash1 = (h1[r + 1] - (h1[l] * p1[r - l + 1]) % MOD1 + MOD1) % MOD1;
        ll hash2 = (h2[r + 1] - (h2[l] * p2[r - l + 1]) % MOD2 + MOD2) % MOD2;
        return {hash1, hash2};
    }
};

void solve() {
    string texto;
    if (!(cin >> texto)) return;

    // 1. Inicializa a estrutura (Custa O(N), mas só é feito uma vez)
    HashString hs(texto);

    ll q; cin >> q;
    while (q--) {
        ll l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2; 
        
        // Convertendo para base-0 caso o problema dê índices 1-based
        l1--; r1--; l2--; r2--; 

        // 2. Extrai e compara as duas substrings em O(1)!
        pair<ll, ll> pedaco_A = hs.get_hash(l1, r1);
        pair<ll, ll> pedaco_B = hs.get_hash(l2, r2);

        if (pedaco_A == pedaco_B) {
            cout << "As substrings sao EXATAMENTE iguais!" << el;
        } 
        else {
            cout << "As substrings sao diferentes." << el;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    // ll t; cin >> t;
    // while (t--) 
    solve();
    
    return 0;
}