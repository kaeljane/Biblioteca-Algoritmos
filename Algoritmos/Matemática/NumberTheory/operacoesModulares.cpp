/*
[EVITA OVERFLOW]

Adição Modular
    (A+B) % M = (A%M + B%M) % M

Subtração Modular
    (A-B) % M = ((A%M - B%M) + M ) % M

Multiplicação Modular
    (A*B) % M = ((A%M) * (B%M)) % M 

    útil para utilizar em calculos de fatoriais
            ll ans = 1;
            ll M = 1e9 + 7;
            for (ll i=1; i <= 100; i++) {
                ans = ((ans % M) * (i % M)) % M;
            }
            cout << ans << el;

Divisão Modular
    ll divide(ll a, ll b) {
        return a * binPow(b, MOD-2) % MOD;
    }
*/