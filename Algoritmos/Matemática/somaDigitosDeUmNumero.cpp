ll somaDigitos(ll x) {
    ll soma = 0;
    while (x > 0) {
        soma += x % 10;
        x /= 10;
    }
    return soma;
}