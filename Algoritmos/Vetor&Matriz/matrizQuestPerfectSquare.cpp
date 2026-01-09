/*
Essa questão trata de transformar uma matriz em uma que quando rotacionada vire ela mesma de forma original

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'

void solve() {
    ll n;
    cin>>n;
    vector<vector<char>> mat(n, vector<char>(n, '0'));

    // input's
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin>>mat[i][j];
        }
    }

    ll ans = 0;
    
    for (ll i = 0; i < n/2; i++) {
        for (ll j = 0; j < n/2; j++) {
            char c1 = mat[i][j];
            char c2 = mat[j][n - 1 - i];
            char c3 = mat[n - 1 - i][n - 1 - j];
            char c4 = mat[n - 1 - j][i];

            char mx = max({c1, c2, c3, c4});

            ans += (mx - c1)+(mx-c2)+(mx-c3)+(mx-c4);

        }
    }
    
    cout << ans << el;

    
}