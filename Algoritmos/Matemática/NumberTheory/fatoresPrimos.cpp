map<ll, int> fatores(ll n) {
        map<ll, int> fatores;

        while (n % 2 == 0) {
                fatores[2]++;
                n /= 2;
        }

        for (ll i=3; i*i <= n; i+=2) {
                while (n % i == 0) {
                        fatores[i]++;
                        n /= i;
                }
        }

        if (n > 2) {
                fatores[n]++;
        }
        return fatores;
}