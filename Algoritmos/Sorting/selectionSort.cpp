void selectionSort(vl &v) {
        for (ll pos=0; pos <= sz(v) - 2; pos++) {
                ll atual = v[pos];
                ll minPosition = pos;
                // encontrar o mínimo elemento
                for (ll j=pos; j < sz(v); j++) {
                        if(v[j] < v[minPosition]) {
                                minPosition = j;
                        }
                }
                swap(v[minPosition], v[pos]);
        }
}

// comentado
// Função Selection Sort: Ordena selecionando o menor e colocando no lugar
void selectionSort(vl &v) {
    // Loop externo: Define a posição atual que queremos preencher com o número correto
    // Vai do início até o penúltimo elemento
    for (ll pos=0; pos <= sz(v) - 2; pos++) {
            
            // (Esta variável 'atual' não é necessária para a lógica do Selection Sort, mas não atrapalha)
            ll atual = v[pos];

            // Começamos assumindo que o menor número já está aqui
            ll minPosition = pos;
            
            // Loop interno: Varre o restante do vetor (a parte bagunçada) para achar o VERDADEIRO menor
            for (ll j=pos; j < sz(v); j++) {
                    
                    // Se encontrarmos um valor menor do que o nosso "mínimo" atual...
                    if(v[j] < v[minPosition]) {
                            // ...atualizamos o índice de onde está o menor valor
                            minPosition = j;
                    }
            }

            // Traz o menor elemento que encontramos para a posição correta (pos)
            swap(v[minPosition], v[pos]);
    }
}