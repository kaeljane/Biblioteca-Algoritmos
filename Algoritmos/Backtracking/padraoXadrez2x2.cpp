/*
Se a soma das coordenadas dos blocos for par, pintamos de um jeito; se for ímpar, de outro.

Fórmula Mágica: ((i / 2) + (j / 2)) % 2

*/

void solve() {
    cin>>n;
    
    for (ll i = 0; i < 2 * n; i++) {
        for (ll j = 0; j < 2 * n; j++) {
            
            if ((i / 2 + j / 2) % 2 == 0) {
                cout << '#';
            } else {
                cout << '.'; 
            }
        }
        cout << el; 
    }
    
}
/*

##
##

##..
##..
..##
..##

##..##
##..##
..##..
..##..
##..##
##..##

##..##..
##..##..
..##..##
..##..##
##..##..
##..##..
..##..##
..##..##

*/