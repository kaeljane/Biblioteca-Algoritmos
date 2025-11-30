const int MAXN = 1e6;
ll qt[MAXN + 1] = {0}; // array de frequencias

void solve() {
        cin>>n;
        // jogar no arr global
        for (ll i=0; i < n; i++) {
                cin>>x;
                qt[x]++;
        }
        
        for (ll gcd = MAXN; gcd >= 1; gcd--) {
                ll multiplos = 0;
                for (ll j = gcd; j <= MAXN; j += gcd) {
                        multiplos += qt[j];
                }

                if (multiplos >= 2) {
                        cout << gcd << el;
                        return;
                }
        }
}

signed main() {
        ___
        t=1;
        solve();
        return 0;
}