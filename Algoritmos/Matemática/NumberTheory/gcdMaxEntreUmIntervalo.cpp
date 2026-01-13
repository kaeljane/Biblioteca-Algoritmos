#include <bits/stdc++.h>
using namespace std;

/*
O número de múltiplos de c entre A e B (inclusive) pode ser calculado como:

O número de múltiplos de c entre A e B = (o número de múltiplos de c entre 1 e B) - (o número de múltiplos de c entre 1 e A - 1).

= floor(B/C) - floor((A-1)/c);

Caso contrário, basta verificar se existem pelo menos dois deles

ceil(A/C) < floor(B/C)


*/

int main(){
    int A, B;
    cin >> A >> B;
    for(int c = B; ; c--) if((A + c - 1) / c < B / c){
        cout << c << endl;
        return 0;
    }
}


// versão mais fácil de ler
void solve() {
    int a, b;
    cin >> a >> b;
    // Começa testando do maior GCD possível (b) até 1
    for (int c = b; c >= 1; c--) {
        // Encontra o primeiro múltiplo de c >= a
        int primeiro_multiplo = (a + c - 1) / c * c; 
        
        // Se o próximo múltiplo ainda estiver dentro do limite b
        if (primeiro_multiplo + c <= b) {
            cout << c << endl;
            return;
        }
    }
}