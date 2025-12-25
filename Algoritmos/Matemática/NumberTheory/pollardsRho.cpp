/*
Uma artilharia Pesada da fatoração
Fatoração de um número gigante como 10^18 que não é primo
O(n^(1/4))

Raiz quadrada levaria anos
O Pollard's Rho resolve em milissegundos.

[Intuição] -> paradoxo do aniversário
    - Se você procurar alguém com um aniversário específico (ex. 25/dez), vai demorar
    - Mas se você quiser achar quaisquer duas pessoas que façam aniversário no mesmo dia, precisa de muito menos gente (umas 23 pessoas já dão 50% de chance).

    Pollard's Rho usa essa ideia

Tartaruga (x): Anda 1 passo por vez (x = f(x)).
Lebre (y): Anda 2 passos por vez (y = f(f(y))).
A cada passo, calculamos g = GCD(|x - y|, N).
    Se 1 < g < N, Achamos um fator.
    Se g = N, falhamos (o ciclo fechou sem achar nada). Tentamos novamente mudando o c.

OBS:
    Precisa do [Miller-Rabin] para funcionar para nao precisar fatorar numeros primos.
    Use quando: precisar contar divisores, somar divisores ou achar fatores primos de números > 10^12


*/

// ---------------- INICIO POLLARD'S RHO ----------------
// Requer: isPrime (Miller-Rabin) e u128 definidos acima

// Algoritmo Pollard's Rho para encontrar UM fator não trivial
ll pollard_rho(ll n) {
    if (n % 2 == 0) return 2;

    // Tenta com constantes diferentes caso falhe
    ll x = 2, y = 2, d = 1, c = 1;
    auto f = [&](ll x) { return ((u128)x * x + c) % n; };

    while (d == 1) {
        x = f(x);               // Tartaruga
        y = f(f(y));            // Lebre
        d = __gcd(abs(x - y), n);

        // Se falhar (d == n), reseta com parâmetros diferentes
        if (d == n) {
            x = rand() % (n - 2) + 2;
            y = x;
            c = rand() % (n - 1) + 1;
            d = 1;
        }
    }
    return d;
}

// Mapa para guardar a fatoração completa (primo -> expoente)
map<ll, int> factors;

// Função recursiva para fatorar completamente o número
void factorize(ll n) {
    if (n == 1) return;

    // 1. Se for primo, adiciona ao mapa e retorna.
    if (isPrime(n)) {
        factors[n]++;
        return;
    }

    // 2. Se for composto, usa Rho para quebrar em pedaços
    ll divisor = pollard_rho(n);

    // 3. Fatora recursivamente os pedaços
    factorize(divisor);
    factorize(n / divisor);
}
// ---------------- FIM POLLARD'S RHO ----------------

void solve() {
    cin >> n;
    factors.clear(); // Importante limpar em casos de teste multiplos
    factorize(n);    

    cout << n << " =";
    for (auto const& [p, exponent] : factors) {
        cout << " " << p << "^" << exponent;
    }
    cout << el;
}