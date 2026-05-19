// By: João Pedro (Evoluído com Lazy Propagation) por Kay
// IFPB
 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int MAX = 2e5+5; // 2*10^5 = 200000 ///////
 
ll ns[MAX]; // <-- Agora é ll para evitar overflow na soma
 
/// SEGTREE COM LAZY PROPAGATION
/// Para utilizar:
///   seg.build(limite)
///   seg.update(l, r, valor_para_somar) <-- AGORA ATUALIZA UM INTERVALO INTEIRO!
///   seg.query(l, r)
///   lembrando que é 0-indexado, então tomar cuidado com pos, l e r
 
#define e(u) (u*2)     // Filho da Esquerda
#define d(u) (e(u)+1)  // Filho da Direita

// Removi as macros 'in' e 'out' para evitar bugs invisíveis.
 
// Aqui definimos o que a arvore faz
struct Node {
    ll v = 0; // atenção com o valor padrão, para que ele seja nulo de verdade /////
 
    Node operator+(const Node b) { // operação de mesclagem (SOMA)
        return {v + b.v}; //////
    }
};
// Quer mudar para achar o Mínimo? Troque por return { min(v, b.v) };.
 
struct SEG {
    Node seg[MAX*4];
    ll lazy[MAX*4]; // O CADERNINHO DE ANOTAÇÕES PREGUIÇOSO
    int lim;
 
    // ---------------------------------------------------------
    // O CARTEIRO PREGUIÇOSO: Entrega a atualização atrasada para os filhos
    // ---------------------------------------------------------
    void push(int u, int l, int r) {
        if (lazy[u] != 0) { // Se tem algo anotado no caderninho
            // 1. Atualiza o valor real DESTE nó
            // Como é soma em intervalo, o valor ganha (lazy * tamanho_do_intervalo)
            seg[u].v += lazy[u] * (r - l + 1); 
            
            // 2. Se não for folha, passa a anotação para os filhos
            if (l != r) {
                lazy[e(u)] += lazy[u];
                lazy[d(u)] += lazy[u];
            }
            
            // 3. Apaga a anotação (já foi entregue)
            lazy[u] = 0; 
        }
    }

    void build(int u, int l, int r) {
        lazy[u] = 0; // Limpa o caderninho no início
        
        if(l == r) { // nó folha
            seg[u].v = ns[l]; // Pega o valor real do vetor global /////
        } 
        else {
            const int m = (l+r)/2;
            build(e(u), l, m); 
            build(d(u), m+1, r);
            seg[u] = seg[e(u)] + seg[d(u)];
        }
    }
 
    void build(int lim_) {
        lim = lim_; /////
        build(1, 0, lim);
    }
 
    // AGORA O UPDATE RECEBE UM INTERVALO (a, b) INTEIRO!
    void update(int u, int l, int r, int a, int b, ll val) {
        push(u, l, r); // SEMPRE chame o carteiro antes de visitar um nó!

        if(l > r || l > b || r < a) return; // Totalmente fora

        if(a <= l && r <= b) { // Totalmente dentro: Anota no caderninho e para!
            lazy[u] += val;
            push(u, l, r); // Aplica agora para o nó ficar correto para o pai
            return;
        }

        const int m = (l+r)/2;
        update(e(u), l, m, a, b, val);
        update(d(u), m+1, r, a, b, val);
        
        seg[u] = seg[e(u)] + seg[d(u)];
    }
    
    void update(int l, int r, ll val) { // seg.update(2, 5, 10) -> Soma 10 do índice 2 ao 5
        update(1, 0, lim, l, r, val);
    }
 
    Node query(int u, int l, int r, int a, int b) {
        push(u, l, r); // SEMPRE chame o carteiro antes de ler um nó!

        if(l > r || l > b || r < a) return Node(); // Elemento Neutro
        
        if(a <= l && r <= b) return seg[u];
        
        const int m = (l+r)/2;
        return query(e(u), l, m, a, b) + query(d(u), m+1, r, a, b);
    }
 
    Node query(int l, int r) { // seg.query(1, 10)
        return query(1, 0, lim, l, r);
    }
} seg;
/// FIM SEGTREE COM LAZY
 
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    
    // Supondo N = 5 (Índices 0 a 4)
    // ns = {0, 0, 0, 0, 0}
    seg.build(4); 
    
    // Soma 10 em todo mundo do índice 1 ao 3
    seg.update(1, 3, 10); // Array mental: {0, 10, 10, 10, 0}
    
    // Soma 5 apenas no índice 2 (Para Range Update agir como Point Update, basta l = r)
    seg.update(2, 2, 5);  // Array mental: {0, 10, 15, 10, 0}
    
    // Pergunta a soma do índice 0 ao 2 (0 + 10 + 15 = 25)
    cout << seg.query(0, 2).v << '\n'; // Imprime 25
}