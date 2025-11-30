void printMatrizInspiral(const vll &matriz) {
        // Checagem de segurança
        if (matriz.empty() || matriz[0].empty()) return;
        ll n = matriz.size();    // número de linhas
        ll m = matriz[0].size(); // número de colunas

        // A lógica da "espiral" é a mesma do código original
        ll startRow = 0;
        ll endRow = n - 1;
        ll startCol = 0;
        ll endCol = m - 1;

        while (startCol <= endCol && startRow <= endRow) {
                // Imprime a linha do topo (da esq p/ a dir)
                for (ll col = startCol; col <= endCol; col++) cout<<matriz[startRow][col]<<" ";
                startRow++; // Move a fronteira da linha do topo para baixo
                
                // Imprime a coluna da dir (de cima p/ baixo)
                for (ll  row = startRow; row <= endRow; row++) cout<<matriz[row][endRow]<< " ";
                endCol--; // Move a fronteira da coluna da dir para a esq

                // Imprime a linha de baixo (da dir p/ esq )
                // (Só se a linha de baixo não for a mesma que a do topo)
                if (startRow <= endRow) {
                        for (ll col = endCol; col >= startCol; col--) cout<<matriz[endRow][col]<< " "; 
                        endRow--; // Move a fronteira da linha de baixo para cima
                }

                // Imprime a coluna da esq (de baixo para cima)
                // (Só se a coluna da esquerda não for a mesma que a da direita)
                if (startCol <= endCol) {
                        for (ll row = endRow; row >= startRow; row--) cout<<matriz[row][startCol]<<" ";
                        startCol++;
                }

        }

}