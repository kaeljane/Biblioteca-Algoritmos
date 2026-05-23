// =========================================================================================
// TÍTULO: PROGRAMAÇÃO DINÂMICA EM DÍGITOS (DIGIT DP)
// PALAVRAS-CHAVE: Contagem de Números, Limite Gigante, Soma de Dígitos, L e R.
// =========================================================================================

/*
   CASOS DE USO CLÁSSICOS:
   - "Quantos números no intervalo [L, R] têm a soma dos dígitos igual a X?"
   - "Quantos números entre 1 e 10^18 não possuem o dígito '4'?"
   
   O PULO DO GATO: Calculamos a resposta para [0, R] e subtraímos a resposta para [0, L-1].
   A variável 'restricted' garante que os dígitos que estamos escolhendo nunca ultrapassem 
   o limite original do número.
*/

#include <bits/stdc++.h>
#define ll long long
#define el '\n'
#define f(i,b,e) for (ll i = (b); i < (e); i++)
using namespace std;

// Tamanho máximo do número (ex: 20 dígitos para 10^18, ou mais se for dado como string)
// DP State: dp[posição][is_restricted][soma_acumulada]
ll dp[20][2][200]; 
string num_str;
ll soma_alvo;

// =========================================================================
// A FUNÇÃO RECURSIVA (Top-Down)
// =========================================================================
ll solve_dp(ll idx, bool restricted, ll soma_atual) {
    // Caso Base: Chegamos ao final da construção do número
    if (idx == num_str.length()) {
        return (soma_atual == soma_alvo) ? 1 : 0;
    }

    // Memoization: Se já calculamos esse estado (e ele não está restrito), retorna logo!
    // ATENÇÃO: Só podemos aproveitar a memória se NÃO estivermos colados no limite máximo.
    if (!restricted && dp[idx][restricted][soma_atual] != -1) {
        return dp[idx][restricted][soma_atual];
    }

    // Se estamos restritos, o dígito máximo é o dígito correspondente no número original.
    // Se estamos livres, podemos colocar até o 9.
    ll limite = restricted ? (num_str[idx] - '0') : 9;
    ll ans = 0;

    f (d, 0, limite + 1) {
        // O próximo estado só continua restrito se já estávamos restritos 
        // E escolhemos exatamente o dígito máximo permitido agora.
        bool novo_restricted = restricted && (d == limite);
        
        ans += solve_dp(idx + 1, novo_restricted, soma_atual + d);
    }

    // Salva na memória apenas os estados não restritos (pois os restritos mudam dependendo do teto)
    if (!restricted) {
        dp[idx][restricted][soma_atual] = ans;
    }
    
    return ans;
}

// =========================================================================
// FUNÇÃO DE EMBALAGEM (Calcula a resposta para o intervalo de 0 até X)
// =========================================================================
ll calcular_ate(ll limite_superior) {
    if (limite_superior < 0) return 0;
    
    // Converte o limite para string para processarmos dígito por dígito
    num_str = to_string(limite_superior);
    
    // Reseta a tabela de DP (Sempre usar memset com -1 para DP Top-Down)
    memset(dp, -1, sizeof(dp));
    
    // Começamos no índice 0, com a restrição ATIVADA (para não passar do limite), e soma 0.
    return solve_dp(0, true, 0);
}

void solve() {
    ll L, R; 
    if (!(cin >> L >> R >> soma_alvo)) return;

    // A Mágica do Prefixo: Resposta[L, R] = Resposta[0, R] - Resposta[0, L-1]
    ll ans_R = calcular_ate(R);
    ll ans_L = calcular_ate(L - 1);

    cout << "Numeros validos no intervalo: " << ans_R - ans_L << el;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}