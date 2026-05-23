// =========================================================================================
// TÍTULO: VETOR DE DIFERENÇAS 2D (2D DIFFERENCE ARRAY)
// PALAVRAS-CHAVE: Matriz, Range Update 2D, Inclusão-Exclusão, O(1), Reconstrução O(N*M).
// =========================================================================================

/*
   CASO DE USO CLÁSSICO:
   - O problema te dá uma matriz N x M (inicialmente zerada).
   - Ele faz Q atualizações em lote: "Adicione V em todo o retângulo de (L1, C1) a (L2, C2)".
   - No final, ele pede para você imprimir ou consultar a matriz inteira.
   
   O PULO DO GATO: Marcamos 4 pontos específicos em O(1) usando Inclusão-Exclusão.
   Depois de todas as atualizações, reconstruímos a matriz usando um Prefix Sum 2D.
   Obrigatoriamente usamos Base-1 e tamanho N+2 para evitar Segmentation Faults!
*/

#include <bits/stdc++.h>
#define ll long long
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
using namespace std;

void solve() {
    ll linhas, colunas, q;
    if (!(cin >> linhas >> colunas >> q)) return;

    // 1. Criamos a Matriz de Diferenças com tamanho +2
    // Se a matriz original vai até a linha 'linhas', o muro pode cair na linha 'linhas + 1'.
    vector<vector<ll>> diff(linhas + 2, vector<ll>(colunas + 2, 0));

    // 2. Processamos todas as Q atualizações em O(1)
    while (q--) {
        ll l1, c1, l2, c2, valor;
        cin >> l1 >> c1 >> l2 >> c2 >> valor;

        // Os 4 pilares da atualização 2D:
        diff[l1][c1] += valor;                 // Início (+)
        diff[l1][c2 + 1] -= valor;             // Corta à direita (-)
        diff[l2 + 1][c1] -= valor;             // Corta embaixo (-)
        diff[l2 + 1][c2 + 1] += valor;         // Restaura a intersecção dupla (+)
    }

    // 3. Reconstrução da Matriz (Prefix Sum 2D) em O(N * M)
    // Feito apenas UMA VEZ no final!
    f (i, 1, linhas + 1) {
        f (j, 1, colunas + 1) {
            // A matemática exata do Prefix Sum 2D para espalhar as diferenças:
            // Atual = Cima + Esquerda - Diagonal + Valor do Ponto Atual
            diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
        }
    }

    // 4. Imprime o resultado final validado
    f (i, 1, linhas + 1) {
        f (j, 1, colunas + 1) {
            cout << diff[i][j] << " ";
        }
        cout << el;
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // ll t; cin >> t;
    // while(t--)
    solve();
    return 0;
}