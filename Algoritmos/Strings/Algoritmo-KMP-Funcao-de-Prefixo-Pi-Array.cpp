// =========================================================================================
// TÍTULO: STRINGS - ALGORITMO KMP (FUNÇÃO DE PREFIXO / VETOR PI)
// PALAVRAS-CHAVE: KMP, Knuth-Morris-Pratt, Pattern Matching, Contar Ocorrências, Período.
// =========================================================================================

/*
   CASOS DE USO CLÁSSICOS:
   - Encontrar todas as posições onde um "Padrão" ocorre dentro de um "Texto" em O(N + M).
   - Encontrar o menor período de repetição de uma string (ex: "abcabcabc" -> período 3).
   
   O PULO DO GATO: Concatenar "Padrao + '#' + Texto". Ao rodar a Função de Prefixo nesta 
   string combinada, qualquer posição que atinja o valor igual ao tamanho do 'Padrao'
   significa que encontraste uma correspondência completa!
*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
using namespace std;

// =========================================================================
// A FUNÇÃO DE PREFIXO (O coração do KMP) - Custa O(N)
// =========================================================================
vector<ll> prefix_function(const string& s) {
    ll n = s.length();
    vector<ll> pi(n, 0);
    
    f (i, 1, n) {
        ll j = pi[i - 1];
        
        // Se as letras não batem, recuamos para o último prefixo válido
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        
        // Se as letras forem iguais, aumentamos o tamanho do prefixo comum
        if (s[i] == s[j]) {
            j++;
        }
        
        pi[i] = j;
    }
    return pi;
}

void solve() {
    string texto, padrao;
    if (!(cin >> texto >> padrao)) return;

    // TRUQUE DE OURO: Concatenar usando um caractere que NUNCA aparece no texto (ex: '#')
    // Isso impede que a função de prefixo ultrapasse o tamanho do próprio padrão.
    string combinada = padrao + '#' + texto;
    
    vector<ll> pi = prefix_function(combinada);
    vector<ll> ocorrencias;

    ll tam_padrao = padrao.length();

    // Começamos a procurar apenas no pedaço que pertence ao 'texto' original
    f (i, tam_padrao + 1, combinada.length()) {
        
        // Se o valor no vetor 'pi' for igual ao tamanho do padrão, encontrámos!
        if (pi[i] == tam_padrao) {
            // Conta matemática para descobrir o índice inicial real no texto original (base-0)
            ll idx_original = i - 2 * tam_padrao;
            ocorrencias.pb(idx_original);
        }
    }

    // Saída dos resultados
    cout << "O padrao aparece " << ocorrencias.size() << " vezes." << el;
    f (i, 0, ocorrencias.size()) {
        cout << "Encontrado no indice: " << ocorrencias[i] << el;
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    // ll t; cin >> t;
    // while (t--) 
    solve();
    
    return 0;
}