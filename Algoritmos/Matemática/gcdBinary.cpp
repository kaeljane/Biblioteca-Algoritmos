// Algoritmo de Euclides Otimizado
//
// is an optimization to the normal Euclidean algorithm
// The slow part of the normal algorithm are the modulo operations. 
// Modulo operations O(1) , but are a lot slower than simpler operations like addition, subtraction or bitwise operations.

int binary_gcd(int a, int b) {
    if(!a || !b) return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while(b);
    return a << shift;
}