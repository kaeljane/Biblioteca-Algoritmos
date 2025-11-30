void countingSort(vl &v) {
        if (vazio(v)) return;
        ll maior = max_el(v);// maior elemento
        vl freq(maior+1, 0);// array dinâmico
        for (ll i=0; i < sz(v); i++) freq[v[i]]++;//update freq

        ll j=0;
        for (ll i=0;i <= maior; i++) {// colocar de volta no original
                while (freq[i] > 0) {
                        v[j] = i;
                        freq[i]--;
                        j++;
                }
        }
        return;
}
// algoritmo de ordenação!! array de frequência | numeros positivos


// comentado

// Função Counting Sort: Ordena contando a frequência dos números
void countingSort(vl &v) {
    // 1. Segurança: Se o vetor estiver vazio, não fazemos nada (evita erros)
    if (vazio(v)) return;

    // 2. Descobrimos o alcance: Precisamos saber qual o maior número
    // para criar um vetor de contagem grande o suficiente.
    ll maior = max_el(v);

    // 3. Criamos o "Vetor de Frequência":
    // O índice deste vetor representa o número, e o valor representa a contagem.
    // Tamanho é maior+1 para podermos acessar o índice 'maior'.
    vl freq(maior+1, 0);

    // 4. Fase de Contagem:
    // Percorremos o vetor original e "marcamos" a presença de cada número.
    for (ll i=0; i < sz(v); i++) {
        freq[v[i]]++; 
    }

    // 5. Fase de Reconstrução:
    // Agora sobrescrevemos o vetor original 'v' com os números em ordem.
    ll j=0; // 'j' é a posição no vetor original 'v'
    
    // Percorremos o vetor de frequência do início ao fim (0 até maior)
    for (ll i=0; i <= maior; i++) {
        
        // Enquanto ainda houver contagem para o número 'i'...
        while (freq[i] > 0) {
            v[j] = i;   // ...colocamos o número 'i' na posição 'j' de 'v'
            freq[i]--;  // ...diminuímos a contagem restante
            j++;        // ...avançamos para a próxima posição em 'v'
        }
    }
    return;
}

/*
Resumo em 3 passos:

Mapeie: Descubra o maior valor para saber o tamanho do mapa.

Conte: Percorra a lista e anote quantas vezes cada número aparece.

Reescreva: Percorra suas anotações em ordem e preencha a lista original.
*/