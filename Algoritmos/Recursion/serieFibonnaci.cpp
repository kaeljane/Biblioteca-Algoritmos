#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
    // Caso base: os dois primeiros números da série são 0 e 1
    if (n == 0 || n == 1) return n;
    
    // Chamada recursiva: F(n) = F(n-1) + F(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

/*
n -> Número da posição na série de Fibonacci
Retorna o n-ésimo número da série de Fibonacci.
*/