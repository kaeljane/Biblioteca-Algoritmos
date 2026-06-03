// =========================================================================================
// TÍTULO: PALÍNDROMOS E RANGE DP (INSERÇÕES MÍNIMAS & SUBSEQUÊNCIA)
// PALAVRAS-CHAVE: Palindrome, Min Insertions, Longest Palindromic Subsequence, Range DP.
// =========================================================================================

/*
   CASOS DE USO CLÁSSICOS:
   - "Qual o mínimo de letras a inserir para S virar um palíndromo?"
   - "Qual a maior subsequência palindrômica dentro de S?"
   
   O PULO DO GATO: Nós analisamos a string encolhendo-a pelas bordas (esquerda 'l' e direita 'r').
   Se as pontas forem iguais, ganhamos 2 pontos e olhamos o miolo.
   Se forem diferentes, testamos ignorar a ponta esquerda ou ignorar a direita, e pegamos o melhor.
*/

#include <bits/stdc++.h>
#define ll long long
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
#define ___ ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;

    ll n = s.length();

    // dp[l][r] = Tamanho da maior subsequência palindrômica no intervalo de 'l' até 'r'
    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    // Casos base: Toda letra sozinha é um palíndromo de tamanho 1
    f (i, 0, n) {
        dp[i][i] = 1;
    }

    // RANGE DP: Preenchemos a matriz pelo "tamanho da janela" (gap)
    // Janelas de tamanho 2 até N
    f (gap, 1, n) {
        for (ll l = 0, r = gap; r < n; l++, r++) {
            
            // Se as pontas baterem, a resposta é o miolo + 2
            if (s[l] == s[r]) {
                dp[l][r] = dp[l + 1][r - 1] + 2;
            } 
            // Se não baterem, quem traz o melhor resultado? Encolher pela esquerda ou pela direita?
            else {
                dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
            }
            
        }
    }

    ll maior_subsequencia = dp[0][n - 1];
    ll insercoes_minimas = n - maior_subsequencia;

    // RESPOSTAS PRONTAS:
    cout << "1. Tamanho da Maior Subsequencia Palindromica: " << maior_subsequencia << el;
    cout << "2. Minimo de insercoes para virar palindromo: " << insercoes_minimas << el;
}

signed main() {
    ___
    // ll t; cin >> t;
    // while(t--)
    solve();
    return 0;
}