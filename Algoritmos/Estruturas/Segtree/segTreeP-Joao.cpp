// By: João Pedro
// IFPB
 
#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 2e5+5; // 2*10^5 = 200000 ///////
 
int ns[MAX];
 
/// SEGTREE
/// Para utilizar:
///   seg.build(limite)
///   seg.update(pos, novo_valor)
///   seg.query(l, r)
///   lembrando que é 0-indexado, então tomar cuidado com pos, l e r
 
#define e(u) (u*2)     // Filho da Esquerda
#define d(u) (e(u)+1)  // Filho da Direita
#define out (l > r || l > b || r < a)
#define in (a <= l && r <= b)
 
/// exemplos de declaração de estrutura (quando só tem uma variável):
// Node a = {10};
// Node b = {11};
// Node c = a + b;

// Aqui definimos o que a arvore faz
struct Node {
    long long v = 0; // atenção com o valor padrão, para que ele seja nulo de verdade /////
 
    Node operator+(const Node b) { // operação de mesclagem
        return {v + b.v}; //////
    }
};
// Quer mudar para achar o Mínimo? Troque por return { min(v, b.v) };.
 
struct SEG {
    Node seg[MAX*4];
    int lim;
 
    void build(int u, int l, int r) {
        if(l == r) { // nó folha
                seg[u].v = 5; // ou qualquer outro valor inicial de preferencia /////
            } 
            else {
                const int m = (l+r)/2;
                build(e(u), l, m), build(d(u), m+1, r);
                seg[u] = seg[e(u)] + seg[d(u)];
            }
    }
 
    void build(int lim_) {
        lim = lim_; /////
        build(1, 0,lim);
    }
 
    void update(int u, int l, int r, int a, int b) {
        if(l == r) { // nó folha
            seg[u].v = b; // alterando valor na posição a para b   //////
            return;
        }
        const int m = (l+r)/2;
        if(a <= m) update(e(u), l, m, a, b);
        else update(d(u), m+1, r, a, b);
        seg[u] = seg[e(u)] + seg[d(u)];
    }
    
    void update(int pos, int newv) { // seg.update(10, 3)
        update(1, 0,lim, pos, newv);
    }
 
    Node query(int u, int l, int r, int a, int b) {
        if(out) return Node();
        if(in) return seg[u];
        const int m = (l+r)/2;
        return query(e(u), l, m, a, b) + query(d(u), m+1, r, a, b);
    }
 
    Node query(int l, int r) { // seg.query(1, 10)
        return query(1, 0,lim, l, r);
    }
} seg;
/// SEGTREE
 
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    
    seg.build(5); // 5 5 5 5 5
    seg.update(0, 4); // 4 5 5 5 5
    seg.update(1, 8); // 4 8 5 5 5
    cout<<seg.query(0, 4).v<<'\n'; // 27
}
 