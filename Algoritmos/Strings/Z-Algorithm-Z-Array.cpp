// =========================================================================================
// TÍTULO: STRINGS - Z-ALGORITHM (Z-ARRAY)
// PALAVRAS-CHAVE: Z-Array, Pattern Matching, Prefixo Comum, Substring, O(N).
// =========================================================================================

/*
   CASOS DE USO CLÁSSICOS:
   - Encontrar todas as ocorrências de um Padrão num Texto em tempo O(N + M).
   - Problemas que pedem o "maior prefixo em comum" (Longest Common Prefix) entre a string 
     inteira e um sufixo dela mesma.
   
   O PULO DO GATO: O vetor Z na posição 'i' guarda exatamente a quantidade de caracteres 
   consecutivos que são idênticos começando de s[0] e s[i]. A janela [l, r] otimiza
   a busca para não compararmos a mesma letra duas vezes.
*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
using namespace std;

// =========================================================================
// O Z-ALGORITHM (Constrói o Z-Array em O(N))
// =========================================================================
vector<ll> z_function(const string& s) {
    ll n = s.length();
    vector<ll> z(n, 0);
    
    // [l, r] formam a "janela" do pedaço mais à direita que já bateu com o prefixo
    ll l = 0, r = 0;
    
    f (i, 1, n) {
        // Se 'i' está dentro da janela conhecida, podemos reaproveitar cálculos passados!
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        
        // Tentamos expandir o tamanho do prefixo comum caractere por caractere
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        
        // Se a nova correspondência ultrapassou a nossa janela 'r', atualizamos a janela
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

void solve() {
    string texto, padrao;
    if (!(cin >> texto >> padrao)) return;

    // A mesma técnica de blindagem do KMP: concatenar com um caractere neutro
    string combinada = padrao + '#' + texto;
    
    vector<ll> z = z_function(combinada);
    vector<ll> ocorrencias;

    ll tam_padrao = padrao.length();

    // Varremos a parte que corresponde ao texto original
    f (i, tam_padrao + 1, combinada.length()) {
        
        // Se o valor de Z for exatamente igual ao tamanho do padrão, achamos!
        if (z[i] == tam_padrao) {
            // A matemática para voltar ao índice original do texto
            ll idx_original = i - (tam_padrao + 1);
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