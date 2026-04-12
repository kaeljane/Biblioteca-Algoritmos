/*
Para ler uma linha inteira no C++ (incluindo os espaços em branco, o que o cin normal não faz), você usa a função getline().
*/

void solve() {
    string linha;
    // Lê a linha inteira até você apertar Enter
    getline(cin, linha); 
    
    cout << "A linha lida foi: " << linha << el;
}

void solve() {
    int n;
    cin >> n; // Lê um número e deixa o '\n' solto
    
    string frase;
    // O 'ws' suga o Enter fantasma e o getline pega a frase real!
    getline(cin >> ws, frase); 
    
    cout << "Numero: " << n << el;
    cout << "Frase: " << frase << el;
}