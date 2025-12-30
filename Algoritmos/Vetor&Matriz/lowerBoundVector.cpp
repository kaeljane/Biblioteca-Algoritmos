// da biblioteca <algorithm>
// O VETOR TEM QUE ESTAR ORDENADO!
// Retorna o iterador para o PRIMEIRO elemento que é >= x
auto it = lower_bound(all(v), x);

// ---------------------------------------

vl v = {10, 20, 30, 40, 50}; 
// sort(all(v)); // Se não tivesse ordenado, teria que ordenar aqui

int procurado = 35; // Note que 35 não existe no vetor

auto it = lower_bound(all(v), procurado);

if (it != v.end()) {
    // lower_bound não necessariamente acha o valor EXATO.
    // Ele acha o primeiro que "não é menor" (maior ou igual).
    cout << "Encontrei o primeiro valor >= " << procurado << el;
    cout << "O valor eh: " << *it << el; // Vai imprimir 40 (que é o próximo maior)
    
    // Se quiser saber o ÍNDICE:
    int indice = it - v.begin();
    cout << "Esta no indice: " << indice << el; 
} 
else {
    cout << "Todos os numeros do vetor sao menores que " << procurado << el;
}