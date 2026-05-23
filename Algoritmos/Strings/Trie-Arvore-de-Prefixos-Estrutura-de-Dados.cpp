// =========================================================================================
// TÍTULO: STRINGS - TRIE (ÁRVORE DE PREFIXOS)
// PALAVRAS-CHAVE: Dicionário, Autocompletar, Prefixos Comuns, Contagem, Max XOR.
// =========================================================================================

/*
   CASOS DE USO CLÁSSICOS:
   - O problema te dá milhares de palavras e pergunta: "Quantas começam com 'auto'?"
   - Autocompletar: Descobrir se um pedaço de texto é prefixo de alguma palavra válida.
   
   O PULO DO GATO: Cada nó da árvore representa uma letra. Se duas palavras começam 
   com "CA" (ex: CASA e CARRO), elas compartilham os mesmos nós 'C' e 'A' na árvore, 
   poupando uma quantidade absurda de memória e tempo!
*/

#include <bits/stdc++.h>
#define ll long long
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
using namespace std;

// =========================================================================
// ESTRUTURA DA TRIE (Array-based, sem ponteiros, O(Tamanho da Palavra))
// =========================================================================
struct Trie {
    struct Node {
        ll filhos[26];          // 26 letras minúsculas do alfabeto
        ll palavras_terminam;   // Quantas palavras exatas terminam neste nó
        ll prefixos_passam;     // Quantas palavras passam por este nó (útil para contar prefixos)
        
        Node() {
            fill(filhos, filhos + 26, -1); // -1 significa que a rota não existe ainda
            palavras_terminam = 0;
            prefixos_passam = 0;
        }
    };

    vector<Node> t;

    Trie() {
        t.emplace_back(); // Cria o Nó 0 (A Raiz da árvore, que é vazia)
    }

    // Insere uma palavra no dicionário em O(Tamanho da Palavra)
    void insert(const string& s) {
        ll atual = 0; // Começamos sempre da raiz
        
        for (char c : s) {
            ll id = c - 'a'; // Mapeia 'a' para 0, 'b' para 1... 'z' para 25
            
            // Se o galho para essa letra não existe, nós criamos um novo nó
            if (t[atual].filhos[id] == -1) {
                t[atual].filhos[id] = t.size();
                t.emplace_back();
            }
            
            // Desce para o próximo nó
            atual = t[atual].filhos[id];
            t[atual].prefixos_passam++; // Registramos que mais uma palavra passou por aqui
        }
        t[atual].palavras_terminam++; // Fim da palavra
    }

    // Procura se uma palavra EXATA existe no dicionário
    bool search(const string& s) {
        ll atual = 0;
        for (char c : s) {
            ll id = c - 'a';
            if (t[atual].filhos[id] == -1) return false; // O caminho quebrou
            atual = t[atual].filhos[id];
        }
        return t[atual].palavras_terminam > 0;
    }

    // Retorna QUANTAS palavras do dicionário começam com esse prefixo
    ll count_prefix(const string& prefix) {
        ll atual = 0;
        for (char c : prefix) {
            ll id = c - 'a';
            if (t[atual].filhos[id] == -1) return 0; // Nenhuma palavra começa assim
            atual = t[atual].filhos[id];
        }
        return t[atual].prefixos_passam; // O número mágico que salvamos na inserção!
    }
};

void solve() {
    ll n, q;
    if (!(cin >> n >> q)) return;

    Trie dicionario;

    // 1. Inserindo as palavras do banco de dados
    f (i, 0, n) {
        string palavra;
        cin >> palavra;
        dicionario.insert(palavra);
    }

    // 2. Respondendo às consultas instantaneamente
    while (q--) {
        ll tipo;
        string s;
        cin >> tipo >> s;

        if (tipo == 1) {
            if (dicionario.search(s)) cout << "Palavra existe!" << el;
            else cout << "Palavra nao existe." << el;
        } 
        else if (tipo == 2) {
            cout << dicionario.count_prefix(s) << " palavras comecam com esse prefixo." << el;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // ll t; cin >> t;
    // while (t--) 
    solve();
    return 0;
}