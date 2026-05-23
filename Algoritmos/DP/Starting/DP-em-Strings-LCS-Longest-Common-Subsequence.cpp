// =========================================================================================
// TÍTULO: PROGRAMAÇÃO DINÂMICA EM STRINGS (LCS E DISTÂNCIA DE EDIÇÃO)
// PALAVRAS-CHAVE: LCS, Longest Common Subsequence, Edit Distance, Subsequência Comum.
// =========================================================================================

/*
   CASOS DE USO CLÁSSICOS:
   - "Qual o tamanho da maior subsequência que aparece em ambas as strings?" (LCS)
   - "Quantas inserções/remoções são necessárias para a string A virar a string B?"
   
   O PULO DO GATO: O tamanho da matriz é (N+1) x (M+1). A linha 0 e a coluna 0 representam 
   a comparação com uma string vazia (cujo resultado é sempre 0). Isso evita que 
   precisemos escrever dezenas de "ifs" para tratar bordas da matriz!
*/

#include <bits/stdc++.h>
#define ll long long
#define all(v) (v).begin(), (v).end()
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
using namespace std;

void solve() {
    string s1, s2;
    if (!(cin >> s1 >> s2)) return;

    ll n = s1.length();
    ll m = s2.length();

    // dp[i][j] = Tamanho da LCS usando os primeiros 'i' caracteres de s1 e 'j' de s2
    // Inicializamos tudo com 0. As posições [0][j] e [i][0] já ficam prontas!
    vector<vector<ll>> dp_lcs(n + 1, vector<ll>(m + 1, 0));

    // =========================================================================
    // CONSTRUÇÃO DA TABELA (Bottom-Up)
    // =========================================================================
    f (i, 1, n + 1) {
        f (j, 1, m + 1) {
            
            // CUIDADO AQUI: Na matriz estamos no índice 'i', mas na string original 
            // (que é base-0), a letra correspondente está no índice 'i - 1'.
            
            if (s1[i - 1] == s2[j - 1]) {
                // MATCH! As letras bateram. 
                // Pegamos o melhor resultado da diagonal (sem essas letras) e somamos 1.
                dp_lcs[i][j] = dp_lcs[i - 1][j - 1] + 1;
            } 
            else {
                // MISMATCH! Letras diferentes.
                // O melhor resultado é o MÁXIMO entre ignorar a letra atual de s1 (olhar pra cima)
                // ou ignorar a letra atual de s2 (olhar pra esquerda).
                dp_lcs[i][j] = max(dp_lcs[i - 1][j], dp_lcs[i][j - 1]);
            }
        }
    }

    cout << "Tamanho da LCS: " << dp_lcs[n][m] << el;

    // =========================================================================
    // RECUPERAÇÃO DA STRING (Backtracking)
    // Como extrair a string exata caminhando do fim para o começo da matriz
    // =========================================================================
    string lcs_str = "";
    ll i = n, j = m;
    
    while (i > 0 && j > 0) {
        // Se as letras baterem, essa letra FAZ PARTE da nossa resposta.
        if (s1[i - 1] == s2[j - 1]) {
            lcs_str += s1[i - 1]; // Guarda a letra
            i--; j--;             // Recua na diagonal
        } 
        // Se não bateram, descobrimos de onde veio o maior valor (cima ou esquerda) e seguimos ele
        else if (dp_lcs[i - 1][j] > dp_lcs[i][j - 1]) {
            i--; // Veio de cima
        } 
        else {
            j--; // Veio da esquerda
        }
    }
    
    // Como andamos do fim para o começo, a string foi montada de trás pra frente
    reverse(all(lcs_str));
    
    if (lcs_str.empty()) cout << "Nao ha caracteres em comum." << el;
    else cout << "A subsequencia e: " << lcs_str << el;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}