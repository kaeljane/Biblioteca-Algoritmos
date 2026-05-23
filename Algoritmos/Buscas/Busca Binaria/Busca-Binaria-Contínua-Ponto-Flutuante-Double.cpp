// =========================================================================================
// TÍTULO: BUSCA BINÁRIA CONTÍNUA (DOUBLE / PONTO FLUTUANTE)
// PALAVRAS-CHAVE: Geometria, Equações, Raízes, Erro absoluto de 10^-6, Variáveis reais.
// =========================================================================================

/*
   CASO DE USO CLÁSSICO:
    - O problema pede para calcular um tempo, distância ou proporção EXATA (ex: 3.45291).
    - O enunciado avisa explicitamente: "A resposta será considerada correta 
    se o erro absoluto ou relativo não exceder 10^-6".
    - O PULO DO GATO: Nada de (mid + 1). O limite vira o próprio 'mid'. E em vez de 
    testar a diferença (r - l), rodamos um laço exato de 100 a 200 vezes.
    - Complexidade: O(100 * Custo_do_Check).
*/

#include <bits/stdc++.h>
#define ll long long
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
using namespace std;

// =========================================================================
// A FUNÇÃO CHECK
// =========================================================================
bool check(double chute, ll n) {
    // Simule a equação ou a lógica da geometria aqui usando o 'chute'.
    // Retorna 'true' se o chute for válido/suficiente.
    return true; 
}

void solve() {
    ll n; 
    if (!(cin >> n)) return;

    // Em problemas contínuos, usamos double (ou long double para precisão insana)
    double l = 0.0;
    double r = 1e9; // Defina um teto lógico razoável

    // =========================================================================
    // O TRUQUE DE OURO DA MARATONA: 
    // Em vez de usar while (r - l > 1e-7), o que pode causar LOOP INFINITO 
    // por causa de arredondamento de bit do C++, nós forçamos 100 iterações.
    // 
    // A cada iteração, o intervalo cai pela metade.
    // Em 100 iterações, o intervalo divide por 2^100.
    // 2^100 é um número tão ridiculamente grande que o 'l' e o 'r' vão
    // estar apontando para o EXATO MESMO ÁTOMO do universo. Erro de precisão ZERO!
    // =========================================================================
    
    f (iteracao, 0, 100) {
        // Nada de (r - l) / 2 para evitar problemas. Soma direto e divide.
        double mid = (l + r) / 2.0;
        
        // Exemplo para um problema de "Maximizar a resposta":
        if (check(mid, n)) {
            // Se funcionou, o piso vira o próprio mid (NADA DE mid + 1)
            l = mid; 
        } else {
            // Se falhou, o teto vira o próprio mid (NADA DE mid - 1)
            r = mid; 
        }
    }

    // Na saída, configuramos o cout para imprimir sempre com 7 ou mais casas decimais
    cout << fixed << setprecision(7) << l << el;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    // ll t; cin >> t;
    // while (t--) 
    
    solve();
    
    return 0;
}