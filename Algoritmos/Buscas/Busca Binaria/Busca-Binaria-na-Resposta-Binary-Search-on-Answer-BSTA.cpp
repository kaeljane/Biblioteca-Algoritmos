// =========================================================================================
// TÍTULO: BUSCA BINÁRIA NA RESPOSTA (BSTA - Binary Search The Answer)
// PALAVRAS-CHAVE: Minimizar o máximo, Maximizar o mínimo, Função Monotônica, "É possível?".
// =========================================================================================

/*
   CASO DE USO CLÁSSICO:
   - O problema pede: "Qual o TEMPO MÍNIMO para...", "Qual o CUSTO MÁXIMO que...", etc.
   - É difícil calcular a resposta direto, mas é muito fácil CHECAR se um "chute" é válido.
   - O PULO DO GATO: Chute um valor no meio do infinito. Teste se ele funciona. 
     Se funcionar, tente um valor mais arrojado. Se falhar, tente um valor mais conservador.
   - Complexidade: O(N * log(Limites da Resposta)).
*/

#include <bits/stdc++.h>
#define ll long long
#define all(v) (v).begin(), (v).end()
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
using namespace std;

// =========================================================================
// A FUNÇÃO CHECK: O "Coração" do problema (Isso é o que você vai codar)
// =========================================================================
bool check(ll chute, const vector<ll>& v, ll k) {
    // Aqui você simula o problema assumindo que o limite/resposta é o 'chute'.
    // Exemplo genérico: Consigo dividir o array 'v' em no máximo 'k' blocos 
    // de forma que a soma de nenhum bloco ultrapasse o 'chute'?
    
    ll blocos_usados = 1;
    ll soma_atual = 0;
    
    f (i, 0, v.size()) {
        // Se um único item já for maior que o chute, é impossível!
        if (v[i] > chute) return false; 
        
        if (soma_atual + v[i] > chute) {
            // Estourou o limite do chute! Corta o bloco aqui e começa um novo.
            blocos_usados++;
            soma_atual = v[i];
        } else {
            soma_atual += v[i];
        }
    }
    
    // Se usei um número de blocos menor ou igual a 'k', o meu chute é válido!
    return blocos_usados <= k;
}

// =========================================================================
// O MOTOR DA BUSCA BINÁRIA (Quase sempre igual)
// =========================================================================
void solve() {
    ll n, k; 
    if (!(cin >> n >> k)) return;

    vector<ll> v(n);
    f (i, 0, n) cin >> v[i];

    // PASSO 1: Definir os limites do seu chute (O menor e o maior valor POSSÍVEL no universo)
    ll l = 0;                  // Menor resposta imaginável (às vezes é 0, às vezes é o min do vetor)
    ll r = 1e15;               // Maior resposta imaginável (coloque um INF bem grande, mas seguro)
    ll ans = r;                // Guarda a melhor resposta válida encontrada até agora

    // PASSO 2: A Busca Binária
    while (l <= r) {
        ll mid = l + (r - l) / 2; // O nosso "chute" da vez
        
        // Pergunta para a função check: "O valor 'mid' é suficiente para resolver o problema?"
        if (check(mid, v, k)) {
            // Funcionou! Guarda a resposta, mas tenta ser mais ganancioso (achar um valor MENOR).
            ans = mid;     
            r = mid - 1;   // Reduz o teto
        } else {
            // Deu ruim... O 'mid' foi muito pequeno/rigoroso. Precisamos de mais folga.
            l = mid + 1;   // Aumenta o piso
        }
    }

    cout << ans << el;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    // ll t; cin >> t;
    // while (t--) 
    
    solve();
    
    return 0;
}