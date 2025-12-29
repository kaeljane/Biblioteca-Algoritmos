/*
5
3
TMT           -> YES
3
MTT           -> NO
6
TMTMTT        -> YES
6
TMTTTT        -> NO
6
TTMMTT        -> YES


Regras:
    (i) Contagem: A quantidade de 'M' deve ser exatamente N/3, e a de 'T' deve ser 2N/3.
    (ii) Fluxo da Esquerda: Para cada 'M' que aparece, ja deve ter aparecido pelo menos um 'T' sobrando antes dele para ser a "primeira perna" do TMT
    (iii) Fluxo da Direita: Para cada 'M' que aparece, deve existir um 'T' depois dele para ser a "segunda perna"


Algoritmo Guloso

*/

void solve() {
    cin >> n >> s;

    // 1. Verificação Básica de Quantidade
    // O tamanho tem que ser divisível por 3
    if (n % 3 != 0) {
        cout << "NO" << el;
        return;
    }

    // Conta totais
    int countT = count(all(s), 'T');
    int countM = count(all(s), 'M');

    // Tem que ter o dobro de T em relação a M
    if (countM * 2 != countT) {
        cout << "NO" << el;
        return;
    }

    // 2. Varredura da Esquerda para Direita (Garante o primeiro T)
    // "Tem T suficiente antes desse M?"
    int cur_t = 0;
    int cur_m = 0;
    for (char c : s) {
        if (c == 'T') cur_t++;
        else cur_m++;

        // Se em algum momento temos mais M do que T, impossível fechar o prefixo T-M
        if (cur_m > cur_t) {
            cout << "NO" << el;
            return;
        }
    }

    // 3. Varredura da Direita para Esquerda (Garante o segundo T)
    // "Tem T suficiente depois desse M?"
    cur_t = 0;
    cur_m = 0;
    // Loop reverso
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'T') cur_t++;
        else cur_m++;

        if (cur_m > cur_t) {
            cout << "NO" << el;
            return;
        }
    }

    cout << "YES" << el;
}