// Euclides Extendido
//
// Teorema de Bézout
// Time Complexity: O(log N)
// Auxiliary Space: O(log N)

// ax + by = gcd(a, b)
// gcd(a, b) = gcd(b % a, a) = (b % a) * x1 + a * y1
// ax + by = (b - (b/a) * a) * x1 + a * y1
// ax + by = a(y1 - (b/a) * x1) + b * x1
// x = y1 - (b/a) * x1
// y = x1

int gcdExtended(int a, int b, int *x, int *y) { 
    if(a == 0){ 
        *x = 0; 
        *y = 1; 
        return b; 
    } 
 
    int x1, y1; // To store results of recursive call 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
 
    // Update x and y using results of 
    // recursive call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
 
    return gcd; 
} 
 
// Retorna o gcd(a, b) e atualiza x e y tal que ax + by = gcd
ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
