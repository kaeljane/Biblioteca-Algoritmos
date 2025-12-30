// da biblioteca de <algorithm>
auto it = find(all(v), x);

//

vi v = {10, 20, 30, 40};
int procurado = 30;

auto it = find(all(v), procurado);

if (it != v.end()) {
    cout << "Encontrei!" << el;
    
    // Se quiser saber o ÍNDICE (posição 0, 1, 2...):
    int indice = it - v.begin(); 
    cout << "Esta no indice: " << indice << el; // Imprime 2
} 
else {
    cout << "Nao existe no vetor." << el;
}