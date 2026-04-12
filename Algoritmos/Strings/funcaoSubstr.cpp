#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Codeforces";
    
    // 1. Pegando um pedaço no meio (começa no índice 4, pega 5 letras)
    string meio = s.substr(4, 5); 
    cout << meio << '\n'; // Saída: force
    
    // 2. Pegando do meio até o final (começa no índice 4, sem tamanho definido)
    string sufixo = s.substr(4);
    cout << sufixo << '\n'; // Saída: forces
    
    // 3. Pegando um prefixo (começa no índice 0, pega 4 letras)
    string prefixo = s.substr(0, 4);
    cout << prefixo << '\n'; // Saída: Code

    return 0;
}