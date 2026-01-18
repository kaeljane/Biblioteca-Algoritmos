#include <bits/stdc++.h>
using namespace std;
#define ll long long
// caderninho. Tamanho máximo do N + margem
// Inicializamos tudo com -1

vector<ll> memo(1005, -1);

ll fib(ll n) {
    // Casos Base (onde a recursoa para)
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Checagem no caderninho
    if (memo[n] != -1) {
        // achou um valor ja calculado no caderno
        return memo[n];
    }

    // Caso contrário, calculamos para salvar (Memoizar)
    // em vez de só retornar, eu salvo em memo[n] primeiro
    memo[n] = fib(n - 1) + fib(n - 2);

    return memo[n];

}

