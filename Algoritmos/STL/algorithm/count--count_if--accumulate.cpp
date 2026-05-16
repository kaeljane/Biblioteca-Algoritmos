/* ===================================================================
 * 🧮 CONTADORES E ACUMULADORES (count, count_if, accumulate)
 * ===================================================================
 * Função: Contam a quantidade de ocorrências de um valor/regra, ou 
 * somam todos os elementos de um intervalo.
 * * 🚨 REGRAS DE OURO E A ARMADILHA DO TLE:
 * 1. O PERIGO DO LAÇO: Todas essas funções rodam em O(N). 
 * NUNCA coloque um 'count' dentro de um laço 'for' para calcular a 
 * frequência de vários números (isso vira O(N²)). Se precisar olhar 
 * a frequência de muitos números, use um 'map' ou Vetor de Frequência!
 * 2. O TIPO DO ACCUMULATE: O 'accumulate' tira o tipo de dado do 
 * valor inicial que você passa (o 3º parâmetro). Se você passar '0' 
 * (que é um inteiro de 32 bits), a soma de números grandes vai estourar
 * o limite do 'int' e dar Wrong Answer. Passe '0LL' para garantir
 * que a soma seja feita usando 'long long'.
 * =================================================================== */
#include <bits/stdc++.h>
#define ll long long
#define all(v) (v).begin(), (v).end()
#define el '\n'
using namespace std;

void template_count() {
    ll n = 7;
    vector<ll> v = {10, 20, 10, 30, 10, 40, 50};

    // -----------------------------------------------------------
    // 1. COUNT (CONTAGEM EXATA)
    // ⏱️ Complexidade: O(N)
    // Conta quantas vezes um valor exato aparece no vetor.
    // -----------------------------------------------------------
    ll alvo = 10;
    ll qtd_alvo = count(all(v), alvo);
    
    cout << "O numero 10 aparece " << qtd_alvo << " vezes." << el;


    // -----------------------------------------------------------
    // 2. COUNT_IF (CONTAGEM COM CONDIÇÃO / LAMBDA)
    // ⏱️ Complexidade: O(N)
    // Conta quantos elementos passam no teste da função Lambda.
    // Ex: Contar quantos números são maiores que 25.
    // -----------------------------------------------------------
    ll qtd_maiores = count_if(all(v), [](ll x) { 
        return x > 25; 
    });
    
    cout << "Existem " << qtd_maiores << " numeros maiores que 25." << el;
    
    // Exemplo extra com strings (Contar caracteres minúsculos):
    // string s = "Maratona OBI";
    // ll minusculas = count_if(all(s), [](char c) { return islower(c); });


    // -----------------------------------------------------------
    // 3. ACCUMULATE (SOMA TOTAL) - 🏆 O Irmão da biblioteca <numeric>
    // ⏱️ Complexidade: O(N)
    // Soma os valores do vetor a partir de um valor inicial.
    // ATENÇÃO: Use 0LL para o valor inicial se o vetor for de long long!
    // -----------------------------------------------------------
    
    // Soma tradicional:
    ll soma_total = accumulate(all(v), 0LL);
    cout << "A soma de todos os elementos eh: " << soma_total << el;
    
    // Usando accumulate para CONCATENAR STRINGS:
    vector<string> palavras = {"Time", "IFPB", "Joao", "Pessoa"};
    
    // O valor inicial é uma string vazia (string(""))
    string frase = accumulate(all(palavras), string(""), [](string a, string b) {
        if (a.empty()) return b;
        return a + " " + b; // Coloca um espaço entre as palavras
    });
    
    cout << "Frase concatenada: " << frase << el;
}