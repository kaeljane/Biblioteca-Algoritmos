// Onde usar: Dicionários automáticos, autocompletar e
// contar quantas strings começam com um determinado pre-
// fixo. Em CF, também é muito usado com bits (0 e 1) para
// achar o XOR Máximo em um array.

const int MAX_NODES = 1e5 + 5;
int trie[MAX_NODES][26]; // 26 letras do alfabeto
int stop[MAX_NODES];     // Conta quantas palavras terminam aqui
int node_cnt = 0;        // Contador de nos criados

void insert(string& s) {
    int node = 0; // Raiz
    for (char c : s) {
        int id = c - 'a';
        if (!trie[node][id]) trie[node][id] = ++node_cnt;
        node = trie[node][id];
    }
    stop[node]++;
}

bool search(string& s) {
    int node = 0;
    for (char c : s) {
        int id = c - 'a';
        if (!trie[node][id]) return false;
        node = trie[node][id];
    }
    return stop[node] > 0;
}