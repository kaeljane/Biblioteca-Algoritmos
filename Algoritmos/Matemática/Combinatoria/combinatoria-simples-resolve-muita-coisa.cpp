// =========================================================================================
// TÍTULO: MATEMÁTICA - COMBINATÓRIA E ARITMÉTICA MODULAR
// PALAVRAS-CHAVE: nCr, Combinação, Fatorial, Inverso Modular, Exponenciação Rápida.
// =========================================================================================

/*
   CASOS DE USO CLÁSSICOS:
   - "De quantas formas posso escolher K itens de um total de N?" -> nCr(n, k)
   - "Quantos anagramas existem?" -> Permutação com repetição.
   
   O PULO DO GATO: Como não podemos fazer divisão normal com Módulo, usamos a 
   Exponenciação Rápida para achar o Inverso Modular. Pré-computamos os fatoriais
   em O(N) no início do código para que cada consulta nCr custe tempo O(1)!
*/

#include <bits/stdc++.h>
#define ll long long
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
using namespace std;

const ll MOD = 1e9 + 7; // Sempre verifique no problema se é 1e9+7 ou 998244353
const int MAXN = 200005; // Ajuste conforme o N máximo do problema (geralmente 2e5)

ll fat[MAXN];
ll invFat[MAXN];

// Exponenciação Rápida: Calcula (base^exp) % MOD em O(log exp)
ll fexp(ll base, ll exp) {
    ll res = 1;
    base = base % MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD; // Se o expoente for ímpar
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Inverso Modular: Acha o inverso de um número para podermos "dividir" usando módulo
ll modInverse(ll n) {
    return fexp(n, MOD - 2);
}

// Pré-computa os fatoriais e seus inversos em O(N)
void precompute() {
    fat[0] = 1;
    invFat[0] = 1;
    
    // Calcula os fatoriais normais
    f (i, 1, MAXN) {
        fat[i] = (fat[i - 1] * i) % MOD;
    }
    
    // Calcula o inverso do maior fatorial
    invFat[MAXN - 1] = modInverse(fat[MAXN - 1]);
    
    // Calcula os inversos dos menores vindo de trás para frente (Truque de Otimização!)
    for (ll i = MAXN - 2; i >= 1; i--) {
        invFat[i] = (invFat[i + 1] * (i + 1)) % MOD;
    }
}

// Função de Combinação: Escolher R itens dentre N em tempo O(1)
ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    ll ans = fat[n];
    ans = (ans * invFat[r]) % MOD;
    ans = (ans * invFat[n - r]) % MOD;
    return ans;
}

// Função de Arranjo: Escolher R itens dentre N onde a ORDEM IMPORTA
ll nPr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    ll ans = fat[n];
    ans = (ans * invFat[n - r]) % MOD;
    return ans;
}

void solve() {
    // =========================================================================
    // CASO 1: Permutação Simples (N!)
    // Problema: "De quantas formas posso organizar N livros numa estante?"
    // Entrada esperada: 5 (N)
    // =========================================================================
    ll n_livros;
    if (cin >> n_livros) {
        cout << "1. Permutacoes de " << n_livros << " livros: " << fat[n_livros] << el;
    }

    // =========================================================================
    // CASO 2: Combinação Simples (nCr)
    // Problema: "De um grupo de N pessoas, escolher um time de K pessoas (Ordem NÃO importa)"
    // Entrada esperada: 10 3 (N e K)
    // =========================================================================
    ll n_pessoas, k_time;
    if (cin >> n_pessoas >> k_time) {
        cout << "2. Formas de escolher o time: " << nCr(n_pessoas, k_time) << el;
    }

    // =========================================================================
    // CASO 3: Arranjo Simples (nPr)
    // Problema: "Em uma corrida de N carros, formar o pódio com os K primeiros (Ordem IMPORTA)"
    // Entrada esperada: 20 3 (N e K)
    // =========================================================================
    ll n_carros, k_podio;
    if (cin >> n_carros >> k_podio) {
        cout << "3. Formas de formar o podio: " << nPr(n_carros, k_podio) << el;
    }

    // =========================================================================
    // CASO 4: Permutação com Repetição
    // Problema: "Quantos anagramas únicos posso formar com uma palavra S?"
    // Entrada esperada: BANANA (String)
    // =========================================================================
    string s;
    if (cin >> s) {
        // Passo A: Contar a frequência de cada letra na palavra
        map<char, ll> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        // Passo B: Começamos com o fatorial do tamanho total da palavra
        ll anagramas = fat[s.length()]; 
        
        // Passo C: Para cada letra repetida, "dividimos" pelo fatorial da repetição
        for (auto par : freq) {
            ll repeticoes = par.second;
            if (repeticoes > 1) {
                // A mágica do Inverso Modular substituindo a divisão:
                anagramas = (anagramas * invFat[repeticoes]) % MOD;
            }
        }
        
        cout << "4. Anagramas unicos de " << s << ": " << anagramas << el;
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    // IMPORTANTE: Sempre chame a pré-computação ANTES de processar os casos de teste!
    precompute();
    
    // ll t; cin >> t;
    // while (t--) 
    solve();
    
    return 0;
}