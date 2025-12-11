// Bagunçando elementos de uma string
// Você precisa de um gerador de números aleatórios (o "motor") e da função de embaralhar.

int main() {
    string s = "CODEFORCES";

    // 1. Criar o gerador de aleatoriedade (Mersenne Twister)
    // Usamos o relógio do sistema para a 'seed' (semente) ser sempre diferente
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    // 2. Chamar a função shuffle
    shuffle(s.begin(), s.end(), rng);

    cout << s << endl; // Ex: "FOCEDROSEC"
    
    return 0;
}