#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
    // Caso base: o fatorial de 0 ou 1 é 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // Chamada recursiva: n! = n * (n-1)!
    return n * factorial(n - 1);
}