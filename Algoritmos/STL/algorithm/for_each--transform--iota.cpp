/* ===================================================================
 * 🔄 ITERADORES E MODIFICADORES (for_each, transform, iota)
 * ===================================================================
 * Função: Percorrem o vetor aplicando operações, modificando os
 * valores ou preenchendo o vetor de forma automática.
 * * 🚨 REGRAS DE OURO:
 * 1. O SEGREDO DO '&': Se você quiser que o 'for_each' modifique os 
 * valores originais do seu vetor, você TEM que colocar o '&' na 
 * lambda: [](ll &x). Isso significa "passagem por referência". Se 
 * esquecer o '&', ele só altera uma cópia temporária e o vetor fica igual!
 * * ⏱️ COMPLEXIDADE:
 * Todas rodam em Tempo O(N).
 * =================================================================== */
#include <bits/stdc++.h>
#define ll long long
#define all(v) (v).begin(), (v).end()
#define el '\n'
using namespace std;
#include <numeric> // ATENÇÃO: a função 'iota' mora nessa biblioteca!

void template_modificadores() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) cin >> v[i];

    // -----------------------------------------------------------
    // 1. FOR_EACH (PARA CADA UM)
    // Aplica uma função a todos os elementos. Excelente para 
    // modificações diretas (in-place) ou para imprimir dados.
    // Ex: Dobrar o valor de todos os números do vetor
    // -----------------------------------------------------------
    for_each(all(v), [](ll &x) { 
        x *= 2; 
    }); 
    
    // Ex: Imprimir todos os elementos de forma limpa (sem precisar do '&')
    // for_each(all(v), [](ll x) { cout << x << " "; }); cout << el;


    // -----------------------------------------------------------
    // 2. TRANSFORM (TRANSFORMAR)
    // O irmão bombado do for_each. Ele pega os dados de um lugar,
    // aplica uma regra, e SALVA o resultado. Pode salvar por cima 
    // do próprio vetor ou em um vetor novo.
    // Ex: Substituir todos os números do vetor pelo seu valor absoluto (positivo)
    // -----------------------------------------------------------
    transform(all(v), v.begin(), [](ll x) { 
        return abs(x); 
    });
        // transform(all(s), s.begin(), ::tolower);
        
        // =======================================================
        // O Transform "Duplo" (Magia Pura do C++)
        // Se você passar DUAS origens, a sua lambda recebe DOIS parâmetros!
        // Ex: Somar o vetor v1 com o vetor v2, índice por índice.
        // =======================================================
        vector<ll> v1 = {-1, 2, -3, 4, -5};
        vector<ll> v2 = {10, 20, 30, 40, 50};
        // Parâmetros: (Início orig1, Fim orig1, Início orig2, Início destino, Lambda)
        transform(all(v1), v2.begin(), resultado.begin(), [](ll a, ll b) {
            return a + b;
        });
        // Se v1={1,2,3...} e v2={10,20,30...}, resultado = {11, 22, 33, 44, 55}

    // -----------------------------------------------------------
    // 3. IOTA (PREENCHIMENTO SEQUENCIAL) - 🏆 Dica de Ouro CP
    // Sabe quando a questão diz: "Existem N pessoas numeradas de 1 a N"?
    // O iota preenche o vetor com valores crescentes a partir de uma semente.
    // Chega de fazer 'for(int i=0... v[i] = i+1)'!
    // -----------------------------------------------------------
    vector<ll> pessoas(n);
    iota(all(pessoas), 1); // Preenche com: 1, 2, 3, 4, 5... até N.
    // iota(all(pessoas), 100); // Preencheria com: 100, 101, 102, 103...
}
