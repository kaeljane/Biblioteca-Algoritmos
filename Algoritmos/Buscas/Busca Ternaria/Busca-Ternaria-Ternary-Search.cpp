// =========================================================================================
// TÍTULO: BUSCA TERNÁRIA (TERNARY SEARCH)
// PALAVRAS-CHAVE: Função Unimodal, Parábola, Ponto Máximo, Ponto Mínimo, Geometria.
// =========================================================================================

/*
   CASO DE USO CLÁSSICO:
   - O problema pede para você encontrar uma posição ideal (ex: Onde colocar uma torre 
     para minimizar a distância máxima até outras N cidades).
   - O gráfico do custo/lucro forma um "V" (vale) ou um "^" (montanha).
   - O PULO DO GATO: Dividimos o intervalo de busca em 3 partes. Comparamos o resultado 
     da função nos dois pontos de corte (m1 e m2) para descartar 1/3 do intervalo a cada passo.
   - Complexidade: O(100 * Custo_da_Funcao), absurdamente rápido!
*/

#include <bits/stdc++.h>
#define ll long long
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
using namespace std;

// =========================================================================
// A FUNÇÃO UNIMODAL (O que queremos otimizar)
// =========================================================================
double f_custo(double x) {
    // Aqui você calcula o custo/lucro assumindo que a resposta é 'x'.
    // Exemplo didático: Uma parábola f(x) = (x - 5)^2 + 3
    // O ponto mínimo matemático dela é exatamente no X = 5.
    
    return (x - 5.0) * (x - 5.0) + 3.0;
}

void solve() {
    // Definimos os limites lógicos do nosso universo de busca
    double l = -1e9;
    double r = 1e9;

    // Usamos o Truque das 100 Iterações (igualzinho na Busca Binária Contínua!)
    // Isso blinda o código contra loops infinitos por falha de ponto flutuante.
    f (iteracao, 0, 100) {
        
        // Em vez de 1 'mid', calculamos 2 pontos dividindo o intervalo em 3 pedaços
        double m1 = l + (r - l) / 3.0;
        double m2 = r - (r - l) / 3.0;

        // ---------------------------------------------------------------------
        // SE QUEREMOS ENCONTRAR O PONTO MÍNIMO (O fundo do vale):
        // ---------------------------------------------------------------------
        if (f_custo(m1) > f_custo(m2)) {
            // Se o m1 custa MAIS que o m2, a descida continua para a direita de m1.
            // Logo, o mínimo verdadeiro não pode estar no terço esquerdo.
            l = m1; 
        } else {
            // Se o m2 custa MAIS que o m1, o mínimo verdadeiro não pode estar no terço direito.
            r = m2; 
        }
        
        /* // ---------------------------------------------------------------------
        // SE O PROBLEMA PEDIR O PONTO MÁXIMO (O topo da montanha):
        // ---------------------------------------------------------------------
        // A lógica simplesmente inverte!
        if (f_custo(m1) < f_custo(m2)) {
            l = m1;
        } else {
            r = m2;
        }
        */
    }

    // Após 100 iterações, 'l' e 'r' estarão apontando para o mesmo átomo.
    cout << fixed << setprecision(7);
    cout << "A posicao ideal eh: " << l << el;
    cout << "O custo minimo alcançado foi: " << f_custo(l) << el;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    // ll t; cin >> t;
    // while (t--) 
    
    solve();
    
    return 0;
}