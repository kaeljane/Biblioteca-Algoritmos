// Fórmula Geral
reverse(v.begin() + L, v.begin() + R + 1);

// Por que R + 1?
// A função reverse espera dois iteradores:

// Onde começa: v.begin() + L (Aponta para o elemento no índice L).

// Onde para: v.begin() + R + 1 (Aponta para o elemento depois do índice R). O reverse vai inverter tudo antes desse ponto.