// =========================================================================================
// TÍTULO: PALINDROME REORDER (ANAGRAMA PALINDROMICO)
// PALAVRAS-CHAVE: Frequência, O(N), Guloso, CSES, Construção de String.
// =========================================================================================

/*
   CASOS DE USO CLÁSSICOS:
   - "É possível reordenar as letras para formar um palíndromo?"
   - "Imprima qualquer palíndromo válido feito com essas letras."
   
   O PULO DO GATO: Um palíndromo perfeito exige simetria. Portanto, no máximo UMA letra 
   pode aparecer em quantidade ímpar (ela ficará bem no meio). Contamos as letras, 
   construímos a metade esquerda, espelhamos para a direita e colocamos a sobra no centro.
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

    // Vetor para contar a frequência das 26 letras maiúsculas do alfabeto
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'A']++;
    }

    int letras_impares = 0;
    
    // Verifica se é possível montar o palíndromo
    f (i, 0, 26) {
        if (freq[i] % 2 != 0) {
            letras_impares++;
        }
    }

    // Se tivermos mais de uma letra com quantidade ímpar, é impossível haver simetria
    if (letras_impares > 1) {
        cout << "NO SOLUTION" << el;
        return;
    }

    // =========================================================================
    // CONSTRUÇÃO O(N) DO PALÍNDROMO
    // =========================================================================
    string metade_esquerda = "";
    string miolo = "";

    f (i, 0, 26) {
        // Se a quantidade da letra for ímpar, jogamos todas elas para o miolo
        if (freq[i] % 2 != 0) {
            miolo = string(freq[i], i + 'A');
        } 
        // Se for par, jogamos EXATAMENTE A METADE para o lado esquerdo
        else if (freq[i] > 0) {
            metade_esquerda += string(freq[i] / 2, i + 'A');
        }
    }

    // A metade direita é simplesmente a esquerda invertida!
    string metade_direita = metade_esquerda;
    reverse(metade_direita.begin(), metade_direita.end());

    // Imprime as três peças coladas
    cout << metade_esquerda << miolo << metade_direita << el;
}

signed main() {
    ___
    solve();
    return 0;
}