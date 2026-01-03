// Calcula (a^b) % m em O(log b)
long long binPow(long long a, long long b, long long m) {
    a %= m; // Segurança: garante que a base já comece pequena
    long long res = 1;
    
    while (b > 0) {
        // Se o último bit é 1 (b é ímpar), multiplicamos a base atual no resultado
        if (b & 1) { 
            res = (res * a) % m;
        }
        
        // Prepara a base para o próximo bit (a = a^2)
        a = (a * a) % m;
        
        // Descarta o último bit (divide b por 2)
        b >>= 1; 
    }
    return res;
}

ll binPow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % m;
        }
        a = (a*a) % m;
        b >>= 1;
    }
    return res;
}

/*
Detalhes Técnicos Importantes:

1. b & 1: É a forma mais rápida de checar b % 2 != 0. Verifica se o último bit é 1.
2. b >>= 1: É a forma rápida de fazer b = b / 2. Desloca os bits para a direita.
3. a %= m no início: Se o problema te der uma base gigante (ex: $a = 10^{18}$), elevar ela ao quadrado ($10^{36}$) daria overflow no long long antes do módulo. Reduzir logo no começo evita isso.
*/