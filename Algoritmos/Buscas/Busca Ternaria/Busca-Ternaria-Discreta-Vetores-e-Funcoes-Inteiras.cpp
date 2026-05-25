// =========================================================================================
// TÍTULO: BUSCA TERNÁRIA DISCRETA (VETORES E FUNÇÕES INTEIRAS)
// PALAVRAS-CHAVE: Array, Unimodal, Pico, Vale, Platô, Busca em Inteiros.
// =========================================================================================

/*
   CASOS DE USO CLÁSSICOS:
   - Encontrar o pico (máximo) ou vale (mínimo) num vetor que sobe e depois desce (ou vice-versa).
   - A função avaliada retorna valores inteiros e pode conter pequenos "platôs" (áreas retas).
   
   O PULO DO GATO: Em vez de tentar achar a resposta exata com a busca ternária (o que 
   causa loops infinitos com inteiros), nós usamos a busca para reduzir o intervalo 
   gigante para uma janela muito pequena (ex: 40 posições). Depois, finalizamos com 
   um 'for' simples nessa janela.
*/

#include <bits/stdc++.h>
#define ll long long
#define vl vector<long long>
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
#define ___ ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

// Esta função isolada ajuda caso o problema não te dê um vetor pronto, 
// mas sim uma fórmula matemática para calcular a altura na posição 'x'.
ll f_custo(const vl &v, ll x) {
    return v[x];
}

void solve() {
    ll n;
    if (!(cin >> n)) return;
    
    vl v(n);
    f (i, 0, n) cin >> v[i];

    ll l = 0;
    ll r = n - 1;

    // Reduzimos o intervalo até sobrar no máximo 40 elementos.
    // O número 40 blinda o código contra platôs de tamanho até ~13.
    while (r - l >= 40) {
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
        
        // ---------------------------------------------------------------------
        // SE QUEREMOS O PICO (PONTO MÁXIMO):
        // ---------------------------------------------------------------------
        if (f_custo(v, m1) < f_custo(v, m2)) {
            // A subida continua para a direita de m1, logo o pico não está à esquerda dele.
            l = m1; 
        } 
        else if (f_custo(v, m1) > f_custo(v, m2)) {
            // A descida já começou antes de m2, logo o pico não está à direita dele.
            r = m2; 
        }
        else {
            // Se m1 e m2 têm o mesmo valor E sabemos que o platô é pequeno,
            // o pico obrigatoriamente está entre eles!
            l = m1;
            r = m2;
        }
        
        /* // ---------------------------------------------------------------------
        // SE QUEREMOS O VALE (PONTO MÍNIMO):
        // ---------------------------------------------------------------------
        // Invertemos apenas o sinal de comparação!
        if (f_custo(v, m1) > f_custo(v, m2)) l = m1;
        else if (f_custo(v, m1) < f_custo(v, m2)) r = m2;
        else { l = m1; r = m2; }
        */
    }

    // A busca ternária fez o trabalho pesado em O(log N).
    // Agora, o intervalo [l, r] é minúsculo (tamanho <= 40).
    // Varremos ele linearmente para achar a resposta exata.
    
    ll pico = -1; // Cuidado com problemas onde a altura pode ser negativa! (Aí use -1e18)
    ll pos_pico = -1;

    f (i, l, r + 1) {
        if (v[i] > pico) {
            pico = v[i];
            pos_pico = i;
        }
    }

    // A questão pede apenas a altura do pico.
    cout << pico << el;
}

signed main() {
    ___
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}