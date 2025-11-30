void insertionSort(vl &v) {
        ll tam = sz(v);
        for (ll i=1; i < tam; i++) {
                ll atual = v[i];
                ll ant = i - 1;
                while (ant>=0 && v[ant] > atual) {
                        v[ant+1] = v[ant];
                        ant = ant - 1;
                }
                v[ant+1] = atual;
        }
}

// comentado

// Função que ordena um vetor 'v' usando Insertion Sort
// Recebe 'v' por referência (&) para modificar o original
void insertionSort(vl &v) {
    ll tam = sz(v);
    // Começamos do segundo elemento (índice 1), pois o primeiro já é considerado "ordenado"
    for (ll i = 1; i < tam; i++) {
        // Guardamos o valor que queremos inserir na parte ordenada
        ll atual = v[i];
        // 'ant' é o índice do elemento imediatamente à esquerda
        ll ant = i - 1;
        // Enquanto não chegamos no início (ant >= 0) E o elemento anterior for maior que o atual...
        // (Isso significa que encontramos alguém maior que precisa ir pra frente)
        while (ant >= 0 && v[ant] > atual) {
            // ...empurramos o elemento maior uma casa para a direita
            v[ant+1] = v[ant];
            // Continuamos olhando para a esquerda
            ant = ant - 1;
        }
        // Quando o while para, achamos o lugar certo! (ou chegamos no início, ou achamos alguém menor/igual)
        // Inserimos o valor 'atual' na posição vaga (que é ant + 1)
        v[ant+1] = atual;
    }
}

/*
Resumo em 3 passos:

Guarde: Pegue o elemento atual (atual).

Empurre: Mova todos os elementos maiores que estão à esquerda dele uma casa para a direita.

Insira: Coloque o atual no buraco que sobrou.
*/