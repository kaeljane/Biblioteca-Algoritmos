void bubbleSort(vl &v) {
        ll tam = sz(v);
        for (ll times=1; times < tam; times++) {
                for (ll j=0; j <= tam - times - 1; j++) {
                        if (v[j] > v[j+1] ) {
                                swap(v[j], v[j+1]);
                        }
                }
        }
}

// comentado

// Função Bubble Sort: Ordena o vetor 'v' modificando-o diretamente (&)
void bubbleSort(vl &v) {
    ll tam = sz(v);

    // Loop externo: Controla as "passadas". 
    // A cada passada completa, o maior elemento restante é garantido no final.
    for (ll times=1; times < tam; times++) {

        // Loop interno: Percorre o vetor comparando vizinhos.
        // O "- times" é a otimização: não precisamos checar o final que já está ordenado.
        for (ll j=0; j <= tam - times - 1; j++) {

            // Se o elemento atual for maior que o próximo vizinho...
            if (v[j] > v[j+1] ) {
                
                // ...troca eles de lugar! O maior vai para a direita.
                swap(v[j], v[j+1]);
            }
        }
    }
}

/*
Resumo em 2 passos:

Compare: Olhe para dois vizinhos.

Troque: Se o da esquerda for maior, troque. Repita até que o maior de todos chegue ao final.
*/