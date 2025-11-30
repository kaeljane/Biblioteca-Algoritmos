vector<ll> divisores(ll n) {
        vl v;
        for (ll i = 1; i <= n/2; i++) {
                if (n % i == 0) v.pb(i);
        }
        return v;
}