#include <bits/stdc++.h>
using namespace std;
void solve() {
    vi v = {10, 20, 20, 30, 20, 50};
    
    // Quero saber quantos '20' existem
    int k = 20;
    
    // Usando seu macro all(v)
    int qtd = count(all(v), k);
    
    cout << "O numero " << k << " aparece " << qtd << " vezes." << el;
    // Saída: O numero 20 aparece 3 vezes.
}