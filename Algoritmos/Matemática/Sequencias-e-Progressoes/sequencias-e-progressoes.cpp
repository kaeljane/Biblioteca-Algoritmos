// ------------ Repetition repetition repetition repetition repetition repet... ------------
#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll, int>
#define vl vector<long long>
#define vll vector<vector<long long>>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define soma(v) accumulate(all(v), 0LL)
#define max_el(v) *max_element(all(v))
#define min_el(v) *min_element(all(v))
#define f(i,b,e) for (ll i = (b); i < (e); i++)
#define rf(i,b,e) for (ll i = (b); i >= (e); i--)
#define fi first
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define sec second
#define el '\n'
#define imp(v, t, e) copy(v.begin(), v.end(), ostream_iterator<t> (cout, e))
#define uset unordered_set
#define ___ ios::sync_with_stdio(false); cin.tie(nullptr);
// 16/03/2026 by Kaeljane
using namespace std;

ll MOD = 1e9 + 7;
ll INF = 1e18 + 7;
const int MAXN = 1e5 + 5;
// matriz vll mat(n, vl(m, 0))

ll n, t, k, x, y, z;
string s, a, b, c;

/* (mind) 
    
    
*/
void solve() {
    /* =========================================================================
    [CHUNK: SEQUÊNCIAS E PROGRESSÕES]
    Fórmulas essenciais de PA, PG e Séries para Programação Competitiva.
    ========================================================================= */

    // ---------------------------------------------------------
    // 1. SEQUÊNCIAS NOTÁVEIS (Sempre útil em problemas Greedy/Math)
    // ---------------------------------------------------------

    // Soma dos N primeiros números naturais: 1 + 2 + 3 + ... + N
    ll somaN(ll n) {
        // n * (n + 1) / 2
        // Dica: Cuidado com overflow se N for até 1e9. Faça a divisão no par primeiro.
        if (n % 2 == 0) return (n / 2) * (n + 1);
        else return n * ((n + 1) / 2);
    }

    // Soma dos quadrados: 1^2 + 2^2 + ... + N^2
    ll somaQuadrados(ll n) {
        return (n * (n + 1) / 2) * (2 * n + 1) / 3; 
    }

    // Soma dos cubos: 1^3 + 2^3 + ... + N^3
    ll somaCubos(ll n) {
        ll s = somaN(n);
        return s * s; 
    }

    // ---------------------------------------------------------
    // 2. PROGRESSÃO ARITMÉTICA (PA)
    // ---------------------------------------------------------

    // Encontra o N-ésimo termo da PA: a_n = a_1 + (n - 1) * r
    ll termoPA(ll a1, ll r, ll n) {
        return a1 + (n - 1) * r;
    }

    // Soma dos N primeiros termos da PA: S_n = n * (a_1 + a_n) / 2
    ll somaPA(ll a1, ll an, ll n) {
        // Novamente, cuidado com overflow ao multiplicar antes de dividir
        if (n % 2 == 0) return (n / 2) * (a1 + an);
        else return n * ((a1 + an) / 2);
    }

    // Soma dos N primeiros termos da PA sabendo a RAZÃO (r)
    ll somaPA_com_razao(ll a1, ll r, ll n) {
        // Calculamos a parte de dentro dos colchetes primeiro: [2*a1 + (n-1)*r]
        ll termo_interno = 2 * a1 + (n - 1) * r;
        
        // Malandragem do CP para evitar overflow: divide por 2 antes de multiplicar
        if (n % 2 == 0) return (n / 2) * termo_interno;
        else return n * (termo_interno / 2); 
    }

    // ---------------------------------------------------------
    // 3. PROGRESSÃO GEOMÉTRICA (PG) E ARITMÉTICA MODULAR
    // ---------------------------------------------------------

    // Exponenciação Rápida Modular (binPow) - O(log N)
    // Necessário para PG em competições
    ll binpow(ll a, ll b, ll m = MOD) {
        a %= m;
        ll res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % m;
            a = (a * a) % m;
            b >>= 1;
        }
        return res;
    }

    // Inverso Modular (Fermat's Little Theorem)
    // Necessário para fazer divisão com módulo na fórmula da soma da PG
    ll modInverse(ll n, ll m = MOD) {
        return binpow(n, m - 2, m);
    }

    // Encontra o N-ésimo termo da PG com módulo: a_n = a_1 * q^(n-1)
    ll termoPG_mod(ll a1, ll q, ll n, ll m = MOD) {
        a1 %= m;
        ll q_pow = binpow(q, n - 1, m);
        return (a1 * q_pow) % m;
    }

    // Soma dos N primeiros termos da PG com módulo: S_n = a_1 * (q^n - 1) / (q - 1)
    // Em Codeforces, se a razão (q) for grande, a divisão normal dá Wrong Answer!
    ll somaPG_mod(ll a1, ll q, ll n, ll m = MOD) {
        if (q == 1) return (a1 * n) % m; // Se a razão for 1, é só somar a1 N vezes

        ll num = (binpow(q, n, m) - 1 + m) % m; // (q^n - 1) % M
        ll den = modInverse((q - 1 + m) % m, m); // Inverso modular de (q - 1)
        
        ll res = (num * den) % m;
        return (a1 * res) % m;
    }


    
}
signed main() {
    ___
    cin>>t;
    while(t--)
    solve();
    
    return 0;
}