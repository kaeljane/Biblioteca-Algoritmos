/*
[a*x + b*y = n]
tendo (a, b, n)

*/

// versão da Kay em O(n)
#include <bits/stdc++.h>
using namespace std;
void solve() {
    cin>>n>>a>>b;
    
    if ( (a%2 == 0) && (b%2 == 0) && (n%2 != 0)) {
        cout << "NO" << el;
        return;
    }
    if (n%a == 0) {
        // n/a qt de grupos formados
        cout << "YES" << el;
        cout << n/a << " " << 0 << el;
        return;
    }
    if (n%b == 0) {
        cout << "YES" << el;
        cout << 0 << " " << n/b << el;
        return;
    }
    x = n/a; // dando um valor inicial para o x
    ll r = n%a;

    while (true) {
        if (r % b == 0) {
            cout << "YES" << el;
            cout << x << " " << r/b << el;
            break;
        }    
        else {
            x--;
            r += a;
        }
        if (x < 0) {
            cout << "NO" << el;
            break;
        }
    
    }
}

// Versão com o GCD extended

/*
Rodamos o gcdExtended(a, b, x0, y0) para achar a solução base para o GCD [Verificação]: Se 'n' não for divisível por 'g', não existe solução.
[Escala]: Multiplicamos x_0 e y_0 por (n/g) para adaptar a solução ao valor de n.

*/

void solve() {
    cin >> n >> a >> b;

    ll x0, y0;
    ll g = gcdExtended(a, b, x0, y0);

    // 1. Verifica se tem solução (n precisa ser múltiplo do GCD)
    if (n % g != 0) {
        cout << "NO" << el;
        return;
    }

    // 2. Escalar a solução para N
    // Agora temos: a*x0 + b*y0 = n (mas podem ser negativos)
    x0 *= (n / g);
    y0 *= (n / g);

    // 3. Ajustar para encontrar soluções não-negativas
    // Queremos:
    // x = x0 + k * (b/g) >= 0  =>  k >= -x0 / (b/g)
    // y = y0 - k * (a/g) >= 0  =>  k <=  y0 / (a/g)

    ll b_g = b / g;
    ll a_g = a / g;

    // Cálculo dos limites de K (com ceil para min e floor para max)
    // Cuidado com divisão de negativos em C++
    long double k_min_d = (long double)-x0 / b_g;
    long double k_max_d = (long double)y0 / a_g;

    ll k_min = ceil(k_min_d);
    ll k_max = floor(k_max_d);

    // Se existir um k inteiro válido nesse intervalo
    if (k_min <= k_max) {
        // Usamos o k_min para pegar o menor x não negativo possível (opcional)
        ll k = k_min; 
        
        ll x_final = x0 + k * b_g;
        ll y_final = y0 - k * a_g;

        cout << "YES" << el;
        cout << x_final << " " << y_final << el;
    } 
    else {
        cout << "NO" << el;
    }
}
