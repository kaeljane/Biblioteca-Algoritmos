/*
Você não precisa construir a string. Você só precisa checar se as "transições" são matematicamente possíveis.

Grafo disfaçado

A (XX): Sai de X, volta pra X (Loop na ilha X).
B (XY): Viaja de X para Y.
C (YX): Viaja de Y para X.
D (YY): Sai de Y, volta pra Y (Loop na ilha Y).

Para existir um caminho válido (uma string conectada), duas condições precisam ser verdadeiras:

Dica 1: O equilíbrio das viagens (B e C)
    Regra 1: |b-x| <= 1 : caso contrário é impossivel porque você ficaria "preso" na outra ilha sem ter como voltar

Dica 2: O caso das Ilhas Isoladas (A e D)
    Regra 2: Se não há pontes (B = 0 e C = 0), você nao pode ter loops nas duas ilhas ao mesmo tempo.
    Se (B == 0 e C == 0), então é PROIBIDO que (A > 0 e D > 0);


    Se o problema fala de "transições", "estados" ou "pares adjacentes", 90% de ser de grafo.
*/

void solve() {
    cin>>n>>a>>b>>c>>d;
    
    if (abs(b-c) > 1) {
        cout << "No" << el;
        return;
    }

    if (b == 0 && c == 0 && a > 0 && d > 0) {
        cout << "No" << el;
        return;
    }

    cout << "Yes" << el;
    
}