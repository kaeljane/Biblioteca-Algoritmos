#include <bits/stdc++.h>
using namespace std;

// Função recursiva para imprimir números de 1 a N de forma crescente e decrescente
void dec(int n) {
    if (n == 0) {
        return;
    }
    
    cout << n << " ";
    dec(n - 1);
    
}

void cresc(int n) {
    if (n == 0) {
        return;
    }
    
    cresc(n - 1);
    cout << n << " ";
    
}


int main() {
    int N;
    cout << "Digite um número N: ";
    cin >> N;
    
    dec(N);
    
    return 0;
}
