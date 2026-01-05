#include <bits/stdc++.h>
using namespace std;

void backtrack(estado_atual) {
    // 1. LINHA DE CHEGADA (Caso Base)
    if (estado_atual está completo) {
        salvar_resultado();
        return;
    }

    // 2. AS ESCOLHAS (Loop ou IFs) 
    // Tentar Opção A
    if (posso usar A?) {
        adicionar A;
        backtrack(novo_estado);
        remove A; // (Ás vezes necessário desfazer a escolha)
    }

    // Tentar Opção B
    if (posso usar B?) {
        adicionar B;
        backtrack(novo_estado);
        remove B;
    }

}