// =========================================================================================
// TÍTULO: TWO POINTERS - FUSÃO DE ARRAYS (MERGE POINTERS)
// PALAVRAS-CHAVE: Merge, Intersecção, Unir ordenado, Dois vetores independentes.
// =========================================================================================

/*
   CASO DE USO CLÁSSICO:
   - Você tem DOIS arrays/strings e precisa combiná-los, compará-los ou achar elementos em comum.
   - A regra de ouro: Os arrays normalmente precisam estar ordenados!
   - O PULO DO GATO: Um ponteiro corre no Array A e outro no Array B. Eles "disputam" 
     quem avança primeiro dependendo de quem tem o menor/maior valor na ponta da fila.
   - Complexidade: O(N + M), super rápido, pois cada item é olhado apenas uma vez.
*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
using namespace std;

void solve() {
    ll n, m; 
    if (!(cin >> n >> m)) return;

    vector<ll> a(n);
    f (i, 0, n) cin >> a[i];

    vector<ll> b(m);
    f (i, 0, m) cin >> b[i];

    // PASSO 1: Se o problema não garantir que estão ordenados, você DEVE ordenar!
    // sort(a.begin(), a.end());
    // sort(b.begin(), b.end());

    // PASSO 2: Posiciona os corredores na linha de largada
    ll p1 = 0; // Ponteiro do Array A
    ll p2 = 0; // Ponteiro do Array B
    vector<ll> ans;

    // PASSO 3: A corrida! Enquanto NENHUM dos dois cruzar a linha de chegada...
    while (p1 < n && p2 < m) {
        
        // Quem tem o menor número ganha a vaga na resposta e dá um passo à frente
        if (a[p1] <= b[p2]) {
            ans.pb(a[p1]);
            p1++;
        } else {
            ans.pb(b[p2]);
            p2++;
        }
    }

    // PASSO 4: Limpando as sobras (A grande pegadinha!)
    // A corrida acima parou assim que UM dos ponteiros chegou no fim. 
    // Ou seja, o outro array ainda tem números sobrando que já estão ordenados. 
    // Precisamos "raspar o tacho" e colocar o que sobrou no final da resposta.
    
    while (p1 < n) {
        ans.pb(a[p1]);
        p1++;
    }
    
    while (p2 < m) {
        ans.pb(b[p2]);
        p2++;
    }

    // Imprime a fusão perfeita
    f (i, 0, ans.size()) {
        cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
    }
    cout << el;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    // ll t; cin >> t;
    // while (t--) 
    
    solve();
    
    return 0;
}