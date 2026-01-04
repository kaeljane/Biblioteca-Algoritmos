#include <bits/stdc++.h>
using namespace std;

vector<string> spellings = {
    "zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine"
};
void printSpell(int n) {
    // Caso base: se n for 0, apenas imprime "zero"
    if (n == 0) {
        cout << spellings[0] << " ";
        return;
    }
    
    // Chamada recursiva para os dígitos restantes
    if (n / 10 != 0) {
        printSpell(n / 10);
    }
    
    // Imprime o dígito atual
    cout << spellings[n % 10] << " ";
}

/*
Input n -> Número inteiro não negativo
Imprime a representação por extenso de cada dígito de n.
Example:
Input: 2301
Output: "two three zero one"

*/

