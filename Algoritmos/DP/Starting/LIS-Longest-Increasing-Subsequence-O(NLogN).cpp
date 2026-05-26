// =========================================================================================
// TÍTULO: MAIOR SUBSEQUÊNCIA CRESCENTE (LIS / LNDS) O(N log N)
// PALAVRAS-CHAVE: Subsequência Crescente, Não-Decrescente, lower_bound, upper_bound, Patience Sorting.
// =========================================================================================

/*
   CASOS DE USO CLÁSSICOS:
   - LIS (Estritamente Crescente): Ex: [1, 2, 3]. Não aceita repetidos.
   - LNDS (Não-Decrescente): Ex: [1, 2, 2, 3]. Aceita números iguais.
   
   O PULO DO GATO: O vetor 'tails' NÃO guarda a subsequência real. Ele guarda o 
   "menor final possível" para uma subsequência daquele tamanho. A única coisa que 
   diferencia a LIS da LNDS é trocar lower_bound por upper_bound!
*/

#include <bits/stdc++.h>
#define ll long long
#define vl vector<long long>
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
#define ___ ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

void solve() {
    ll n;
    if (!(cin >> n)) return;
    
    vl v(n);
    f (i, 0, n) cin >> v[i];

    vl tails;

    f (i, 0, n) {
        
        // =====================================================================
        // ESCOLHA A SUA BUSCA BINÁRIA AQUI:
        // =====================================================================
        
        // OPÇÃO A: LIS (Estritamente Crescente) - PADRÃO
        // Busca o 1º elemento MAIOR OU IGUAL a v[i].
        // Efeito: Se v[i] já existe no vetor, ele será substituído. O vetor não cresce.
        auto it = lower_bound(tails.begin(), tails.end(), v[i]);

        // OPÇÃO B: LNDS (Não-Decrescente / Permite Iguais)
        // Busca o 1º elemento ESTRITAMENTE MAIOR que v[i].
        // Efeito: Se v[i] for igual ao último, não acha ninguém maior e adiciona no final!
        // auto it = upper_bound(tails.begin(), tails.end(), v[i]);
        
        // =====================================================================

        if (it == tails.end()) {
            // Se o iterador chegou no fim, significa que não achamos ninguém maior 
            // (ou maior/igual) que o v[i]. Logo, a subsequência cresce!
            tails.push_back(v[i]);
        } else {
            // Se achamos alguém, nós o substituímos por v[i] para manter os finais
            // da nossa subsequência o menor possível, facilitando futuros encaixes.
            *it = v[i];
        }
    }

    // O tamanho do vetor 'tails' é a resposta final.
    // Lembrete: Os elementos dentro de 'tails' NÃO são a subsequência correta na ordem original!
    cout << tails.size() << el;
}

signed main() {
    ___
    // ll t; cin >> t;
    // while (t--)
    solve();
    return 0;
}