ll most_sig_bit = 63 - __builtin_clzll(a[i]);

/*
__builtin_clzll
__builtin_: Significa que não é uma função da biblioteca padrão, mas sim um comando interno direto do compilador GCC.

clz: Abreviação de Count Leading Zeros (Conta Zeros à Esquerda).

ll: Significa Long Long (para trabalhar com inteiros de 64 bits).

*/

/*
Posicao_do_MSB = (Total de Bits - 1) - (Zeros à Esquerda)

CUIDADO!!! A FUNCAO TEM COMPORTAMENTO INDEFINIDO CASO O NUMERO FOR 0
    SEMPRE GARANTA QUE O NÚMERO É MAIOR QUE 0 ANTES DE CHAMAR ELA.

Seu Loop: O(bits) (Rápido, mas escreve muito código).
__builtin_clzll: O(1) (Instantâneo, usa hardware direto, mas é nome feio).

*/

